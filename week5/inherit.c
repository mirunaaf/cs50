//Simulate genetic inheritance blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generations);
void free_family(person *p);
char random_allele();

int main (void)
{
    //seed random number generator
    srand(time(0));

    //create a new family with three generations
    person *p = create_family(GENERATIONS);

    //print family tree of blood types
    print_family(p, 0);

    //free memory
    free_family(p);
}

// create a new individual with 'generations'
person *create_family(int generations)
{
    //to do: allocate memory for new person
    person *new_person = malloc(sizeof(person));

    if (new_person == NULL)
    {
        printf("Error allocating memory for the new person\n");
        return NULL;
    }

    //if there are still generations left to create
    if (generations > 1)
    {
       //create two new parents for current person by recursively calling create_family
       person *parent0 = create_family(generations - 1);
       person *parent1 = create_family(generations - 1);

       //to do : set parent pointers for current person (assign a parent for the person's current parent)
       new_person->parents[0] = parent0;
       new_person->parents[1] = parent1;

       //to do : randomly assign current person's alleles based on the alleles of their parents
       new_person->alleles[0] = parent0->alleles[rand() % 2];
       new_person->alleles[1] = parent1->alleles[rand() % 2];
    }

    //if there are no generations left to create
    else
    {
        //to do: set parent pointers to NULL
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        //to do: randomly assign alleles
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    //to do : return newly created person
    return new_person;
}

// free 'p' and all ancestors of 'p'
void free_family(person *p)
{
    //to do : handle base case
    if (p == NULL)
    {
        return;
    }
    //to do: free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    //to do: free child
    free(p);
}

//print each family member and their alleles
void print_family(person *p, int generation)
{
    //handle base case
    if (p == NULL)
    {
        return;
    }

    //print indentation
    for (int i = 0; i < generation + INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    //print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    //print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

//randomly chooses a blood type allele
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return '0';
    }
}
