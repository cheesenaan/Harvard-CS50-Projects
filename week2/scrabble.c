#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

//main method
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    int winner = 0;
    if (score1 > score2)
    {
        winner = score1;
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        winner = score2;
        printf("Player 2 wins!");
    }
    else if (score1 == score2)
    {
        winner = score1 = score2;
        printf("Tie!");
    }

}

//methods
int compute_score(string word)
{
    // TODO: Compute and return score for string

    //make word all upercase

    for (int i = 0 ; i < strlen(word); i++)
    {

        if ((int)word[i] >= 97 && (int)word[i] <= 122)
        {
            word[i] =  toupper(word[i]);
        }
        else
        {
            word[i] = word[i];
        }

    }
    //printf("the string x is, %s",word);


    //count score
    int count = 0;
    for (int i = 0; i < strlen(word) ; i++)
    {
        for (int j = 65; j < sizeof(POINTS) + 65; j++)
        {
            if ((int) word[i] ==  j)
            {
                count = count + POINTS[j - 65];
            }
            else
            {
                count += 0;
            }
        }
    }
    return count;
}
