// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <cs50.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) *'z';

// Hash table
int total_words = 0;

node *table[N];//allocating buckets

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);

    node *cursor = table[index];

    while (cursor != NULL)
    {

        if (strcasecmp(cursor -> word, word) == 0)
        {

            return true;

        }

        cursor = cursor -> next;



    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;// TODO

    for (int i =0; i < strlen(word); i++)
    {

        sum += tolower(word[i]);//converts everything to lower case

    }
    return (sum % N);//return int
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r'"); // open dictionary files

    if (file == NULL)
    {
        return false;

    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s",word) !=EOF)//Read one at a time
    {

        node *new_node = malloc(sizeof(node));// Creating new node

        if (new_node == NULL)
        {

            return false;

        }

        strcpy(new_node -> word, word);//copy over word to node

        new_node -> next = NULL;

        int index = hash(word);// get hash index

        if (table[index] == NULL)
        {

            table[index] = new_node;
        }

        total_words++;

    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)//freeing linking list
    {

        node *head = table[i];//head pointer

        node *cursor = head;//cursor pointer

        node *tmp = head;// temp pointer

        while (cursor != NULL)
        {

            cursor = cursor -> next;

            free(tmp);

            tmp = cursor;

        }

    }
    return true;
}
