#include <stdio.h>
# include <cs50.h>

int x = GetInt();
switch(x);
{
    case 1:
    printf("One!\n");
    break;
    case 2:
    printf("Two!\n");
    case 3:
    printf("Three!\n");
    default:
    printf("Sorry!\n");
}