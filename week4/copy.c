#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
// not an authentic copy, only pointing to the same memory block
// {
//     //get a string
//     string s = get_string("s: ");

//     // copy string's address
//     string t  = s;

//     // capitalize first letter in string
//     if(strlen(t) > 0)
//     {
//     t[0] = toupper(t[0]);
//     }

//     //print string twice
//     printf("s: %s\n", s);
//     printf("t: %s\n", t);
// }

    //create an authenthic string copy
{
    //get a string
    char *s = get_string("s: ");

    //allocate memory for another string
    char *t = malloc(strlen(s) + 1);

    //copy string into memory including '\0'
    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        t[i] = s[i];
    }

    //capitalize copy
    t[0] = toupper(t[0]);

    //print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
