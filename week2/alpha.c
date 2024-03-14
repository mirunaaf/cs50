//check if a lowercase string's characters are in alphabetical order. if yes print yes. if no print no
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int length = strlen(word);
    for (int i = 0; i < length - 1; i++)
    {
        //check if not alphabetical
        if(word[i] > word[i + 1])
        {
        printf("No\n");
        return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
