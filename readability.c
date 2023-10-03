#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    // Getting user input e.g. text from a book
    string text = get_string("Text:");

    // Count letters, words and sentences letters", L);

    float W = count_words(text);

    int S = count_sentences(text);

    int L = count_letters(text);

    // Find the reading age
    L = (L / W)*100;
    S = (S / W)*100;

    int index = round(0.0588*L - 0.296*S - 15.8);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}


int count_letters(string text)
{
    float letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
    }
    return letters;
}

int count_words(string text)
{
    float words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}
int count_sentences(string text)
{
    float sentences = 0;
    for (int i = 0;  i < strlen(text); i++)
    {
        if (text[i] == '.')
        {
            sentences++;
        }
        else if (text[i] == '!')
        {
            sentences++;
        }
        else if (text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}