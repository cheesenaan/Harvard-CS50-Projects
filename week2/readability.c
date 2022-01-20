#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int countLetters(string text);
int countWords(string text);
int countSentences(string text);


int main(void)
{

    //get user input
    string text = get_string("Text: ");

    //count the number of letters in the text
    int letterCount = countLetters(text);
    //printf("the number of letters in text is: %i\n",letterCount);

    //count words
    int wordCount = countWords(text);
    //printf("the number of words in text is: %i\n",wordCount);

    //count sentences
    int sentenceCount = countSentences(text);
    //printf("the number of sentences in text is: %i\n",sentenceCount);

    //long L = ((letterCount * 100) / wordCount); this does not work
    float L = ((float)letterCount / wordCount) * 100;
    //long S = (sentenceCount * 100) / wordCount; this does not work
    float S = ((float)sentenceCount / wordCount) * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("index is %lu\n",index);
    int grade = round(index);

    //printf("%f\n", index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

//methods
int countLetters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            count++;
        }
        if (islower(text[i]))
        {
            count++;
        }
    }
    return count;
}
int countWords(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((int)text[i] == 32)
        {
            count++;
        }
    }
    return count + 1;
}
int countSentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((int)text[i] == 33)
        {
            count++;
        }
        if ((int)text[i] == 46)
        {
            count++;
        }
        if ((int)text[i] == 63)
        {
            count++;
        }
    }
    return count;
}
