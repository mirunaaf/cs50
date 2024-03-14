#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate president = get_candidate("Enter a candidate: ");
    printf("%s\n", president.name);
    printf("%i\n", president.votes);
}

candidate get_candidate(string prompt) {
    printf("%s\n", prompt);
    candidate c;
    c.name = get_string("what's the name of the candidate?: ");
    c.votes = get_int("how many votes?: ");
    return c;
}
