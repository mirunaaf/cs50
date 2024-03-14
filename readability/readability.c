#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calc(int letters, int sentences, int words);

int main(void)
{
    // Prompt user for input
    string text = get_string("Text: ");
    int num_letters = count_letters(text);
    int num_words = count_words(text);
    int num_sentences = count_sentences(text);
    float index = calc(num_letters, num_sentences, num_words);
}
// Count the number of letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
            letters++;
    }
    return letters;
}

// Count the number of words
int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
            words++;
    }
    return words;
}

// Count the number of sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }
    return sentences;
}
// Calculate index
float calc(num_letters, num_sentences, num_words)
{
    float index = (0.0588 * num_letters / num_words * 100) - (0.296 * num_sentences / num_words * 100) - 15.8;
    int rounded_index = round(index);

    if (rounded_index < 1)
    {
        printf("Before grade 1\n");
        return 0;
    }
    else if (rounded_index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", rounded_index);
        return 0;
    }
}
