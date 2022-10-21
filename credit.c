#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    //AMEX 15 digit, 3
    //mastercard 16 digit, 5
    //visa 13 or 16 digit, 4
    long n, m, l;
    int size = 0, f, sum = 0, x, ft;
    //entering credit card number
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);
    
    m = n;
    //calculating the number of digits
    while (n > 0)
    {
        if (n >= 10 && n < 100)
        {
            ft = n;
        }
        else if (n < 10)
        {
            f = n;
        }
        n /= 10;
        size++;
    }
    
    if (size == 13 || size == 16 || size == 15)
    {
        //finding the first digit of card
        //f = m / (pow(10, size - 1));
        
        //checking if it belongs to one of the companies
        if (f == 4 || ft == 34 || ft == 37 || ft == 51 || f == 52 || ft == 53 || ft == 54 || ft == 55)
        {
            //calculating evenly indexed digits' sums
            l = m;
            while (m > 0)
            {
                x = 2 * ((m % 100) / 10);
                while (x > 0)
                {
                    sum += x % 10;
                    x /= 10;
                }
                m /= 100;
            }
            //adding the oddly indexed digits to the sum
            while (l > 0)
            {
                sum += l % 10;
                l /= 100;
            }
            //checking if the card is legit
            printf("%i\n", sum);
            if (sum % 10 == 0)
            {
                if (f == 3)
                {
                    printf("AMEX\n");
                }
                else if (f == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("MASTERCARD\n");
                }
            }
            //printing invalid
            else
            {
                printf("INVALID\n");
            }
        }
        //printing invalid
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}