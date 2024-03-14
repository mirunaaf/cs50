// Implements a sorted list of numbers using a linked list

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    //memory for numbers
    node *list = NULL;

    //for each command-line argument
    for (int i = 1; i < argc; i++)
    {
        //convert arg into int
        int number = atoi(argv[i]);

        //allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        //if list is empty
        if (list == NULL)
        {
            list = n;
        }

        //if number belongs at the beginning of list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }

        //if number belongs later in the list
        else
        {
            //iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                //if at end of list
                if (ptr->next == NULL)
                {
                    //append node
                    ptr->next = n;
                    break;
                }

                //if in the middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }
    //print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
    //free memory
    node *ptr = list;
    while (ptr!= NULL)
    {
        node *next = ptr->next;
        free (ptr);
        ptr = next;
    }
}
