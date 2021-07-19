#include <cs50.h>

#include <stdio.h>

#include <string.h>

#include <math.h>

#include <ctype.h>


int get_index(string s);

int main()

{
    string text = get_string("Text: ");//Colleection of input from the user.

    int index = get_index(text);

// Declares integers as floats and calculates with theh Coleman Liau index.

    if (index < 1)

    {

        printf("Before Grade 1\n");

    }

    else if (index >= 16)

    {

        printf("Grade 16+\n");

    }

    else

    {

        printf("Grade %d\n", index);


    }

    return 0;

}

int get_index(string s)
{

// Counting the number of words, letters, senteces. Declaring integers.

    int letter = 0;

    int word = 0;

    int sentence = 0;


    for (int i = 0; i < strlen(s); i++)

    {

        char ch = s[i];

        if (isalpha(ch))

        {

            letter++;

        }

        if (isspace(ch))

        {

            word++;

        }

        if (ch == '.' || ch == '!' || ch == '?')

        {

            sentence++;

        }

    }

    word++;


//Declares integers as floats and calculates with theh Coleman Liau index.
    float L = (letter * 100.0f) / word;

    float S = (sentence * 100.0f) / word;

    return round(0.0588 * L - 0.296 * S - 15.8);





}


