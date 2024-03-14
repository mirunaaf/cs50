//implements a list of numbers with an array of dynamic size

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    //initialize list of 3
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //list of size 4
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    //copy list of size 3 into list of size 4
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    //add number to list of size 4
    tmp[3] = 4;

    //free list of size 3
    free(list);

    //remember list of size 4
    list = tmp;

    //print list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    //free list
    free(list);
    return 0;
}
