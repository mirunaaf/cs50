#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompting user for a starting # of llamas
    int startNumber;
    int endNumber;
    int years = 0;

    do
    {
        startNumber = get_int("Start size: ");
    }
    while (startNumber < 9);

    //Prompting user for a ending number of llamas
    do
    {
        endNumber = get_int("End size: ");
    }
    while(endNumber < startNumber);

    //How many years will it take to get to the goal?

    while (startNumber < endNumber) {
        startNumber += (startNumber / 3) - (startNumber / 4);
        years++;
    }
    printf("Years: %i\n", years);
 }