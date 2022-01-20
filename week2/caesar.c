#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //make sure there is only one command line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //printf("the length of the key is , %lu\n" , strlen(argv[1]));


    //if not a deciaml digit then there is an error
    string keyString = argv[1];
    for (int i = 0; i < strlen(keyString); i++)
    {
        char z = keyString[i];
        if (!isdigit(z))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //if the key is negative, there is an error
    int intKey = atoi(argv[1]);
    if (intKey < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    //user
    string plaintext = get_string("plaintext: ");


    for (int i  = 0; i < strlen(plaintext); i++)
    {
        char c = 0;
        int add = plaintext[i] + intKey;
        if (islower(plaintext[i]))
        {
            c = ((add - 97) % 26) + 97;
        }
        else if (isupper(plaintext[i]))
        {
            c = ((add - 65) % 26) + 65;
        }
        else
        {
            c = plaintext[i];
        }
        plaintext[i] = c;
    }

    printf("ciphertext: %s\n", plaintext);

    //sure -- fher

}








