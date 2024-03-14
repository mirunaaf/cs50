#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name ?");
    int age = get_int("What's your age? ");
    string number = get_string("what's your number? ");
    printf("Age is %i. Name is %s. Number is %s.\n", age, name, number);
}