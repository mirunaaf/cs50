#include <cs50.h>
#include <stdio.h>

int main(void)
// {
//     //get two strings
//     char *s = get_string("s: ");
//     char *t = get_string("t: ");

//     //compare strings' addressses
//     if (s == t)
//     {
//         printf("Same\n");
//     }
//     else
//     {
//         printf("Different\n");
//     }
// }
// shows different because the 2 addresses are different
{
    //get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    //print strings addresses
    printf("%p\n", s);
    printf("%p\n", t);
}
