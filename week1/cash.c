#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //asks the user how much change is owed
    float dollars = get_float("Change owed: ");
    while (dollars < 0)
    {
        dollars = get_float("Change owed: ");
    }

    //quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
    int cents = round(dollars * 100);
    //printf("%i\n" , cents);

    int count = 0;

    while (cents > 0)
    {
        if (cents >= 25)
        {
            count++;
            cents = cents  - 25;
        }
        else if (cents >= 10)
        {
            count++;
            cents = cents  - 10;
        }
        else if (cents >= 5)
        {
            count++;
            cents = cents  - 5;
        }
        else if (cents >= 1)
        {
            count++;
            cents = cents  - 1;
        }
        // printf("cents = ths , %i\n", count);
    }



    //last line of output is only the minimum number of coins possible: an integer followed by \n.
    printf("%i\n", count);
}