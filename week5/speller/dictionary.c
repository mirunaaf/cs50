// Implements a dictionary's functionality

#include <ctype.h>
#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 143093 ;

// Hash table
int total_count = 0;
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //hash the word to obtain its hash value
    int index = hash(word);
    //search the hash table at the location specified by the word's hash value
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function- math using all the letters- sum of ASCII
    //return toupper(word[0]) - 'A';
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open the dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    //create a buffer to store each word
    char word[LENGTH + 1];
    //read each word in the file
    while (fscanf(dict, "%s", word)!= EOF)
    {
        //add each word to the hashtable
        //create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            //fclose(dict);
            return false;
        }

        //copy the word into the new node
        strcpy(n->word, word);
        n->next = NULL;

        //hash the word to obtain its hash value
        unsigned int index = hash(word);

        //insert the new node into the hash table(using the index specified by its hash value)
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
        }
        total_count++;
    }

    //close the dictionary file
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return total_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //iterate through the hash table
    for (int i = 0; i < N; i++)
    {
        //pointer to traverse each linked list
        node *cursor = table[i];

        //traverse the linked list and free nodes
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;

            //free current node
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
