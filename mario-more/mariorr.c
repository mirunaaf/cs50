#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for height
    int h, i, j;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    // Allign blocks from left to right
    for (i = 0; i < h; i++)
    {

        for (j = 0; j < i + 1; j++)
            printf("#");

        printf("\n");
    }
}
    // Building the pyramid