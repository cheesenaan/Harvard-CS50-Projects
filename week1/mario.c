#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, column, space;
    //user input
    n = get_int("Height: ");
    while (n > 8 || n < 1)
    {
        n = get_int("Height: ");
    }

    for (column = 0; column < n; column++) // repeat n times
    {
        printf("\n");

        //space
        for (space = 0; space < n - column - 1; space++)
        {
            printf(" ");
        }


        //hashes
        for (int row = 0; row <= column; row++)
        {
            printf("#");
        }
    }
    printf("\n");
}