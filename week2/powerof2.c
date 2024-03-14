#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = get_int("Length: ");
    int power_of_2[size];
    power_of_2[0] = 1;

    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            printf("%i\n", power_of_2[i]);
        }
        else
        {
        power_of_2[i] = power_of_2[i - 1] * 2;
        printf("%i\n", power_of_2[i]);
        }
    }
}
