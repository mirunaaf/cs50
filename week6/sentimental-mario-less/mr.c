#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h, i, j, k;

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }
        for (j = 0; j < i + 1; j++){
            printf("#");
        }

        printf("  ");

        for (k = 0; k < j; k++){
            printf("#");
        }
        printf("\n");
     }
}
