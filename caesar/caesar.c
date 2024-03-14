#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


bool only_digits(string key);

int main(int argc, string argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plain_text = get_string("Plaintext: ");
    int key = 0;
    char cipher[1] ;

    for ( int i = 0; i < strlen(plain_text); i++){

        char c = plain_text[i];
        cipher[i] = (c + key) % 26;

        printf("%s \n", cipher);

        if(isalpha(c)){
            char base = isupper(c) ? 'A' : 'a';
            char encrypted = (c - base + key) % 26 + base;
            cipher[i] = encrypted;
        }
        else {
            cipher[i] = c;
        }

        // cipher[i] = (plain_text[i] + key) % 26;

    }

     printf("%s \n", cipher);









    if (only_digits(argv[1]))
    {
         key = atoi(argv[1]); // Convert the string to an integer
        if (key <= 27)
        {
            printf("Valid key: %d\n", key);
        }
        else
        {
            printf("Key must be less than or equal to 27.\n");
        }
    }
    else
    {
        printf("Invalid input.\n");
    }
}

bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            printf("false\n");
            return false; // Return false if a non-digit character is found
        }
    }
    return true; // Return true if all characters are digits
}

