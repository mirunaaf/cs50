#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //get a string
    char *s = get_string("s:");
    if (s == NULL)
    {
        return 1;
    }

    //allocate memory for another string
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    //copy string into memory
    strcpy(t, s);

    //capitalize copy
    t[0] = toupper(t[0]);

    //print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    //free memory
    free(t);
    return 0;
}
