#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Get length from user
    int length;
    do
    {
        length = get_int("Length: ");
    }
    while(length < 1);

    //declare ou array
    int twice[length];

    //set the first value
    twice[0] = 1;
    printf("%i\n", twice[0]);
    for (int i = 1; i < length; i++)
    {
        //make the current element twice the previous
        twice[i] = 2 * twice[i - 1];
        printf("%i\n", twice[i]);
    }
}
