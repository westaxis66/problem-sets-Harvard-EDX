// Get key as a comman-line arguement. Amount to shift each character by; use a get_srting
// Get plaintext. Prompt user to input plaintext.
// Encipher  plaintext by shifting all the letters in the key.
// Print cipher text
// Only alpabetic characters change and not case.
// Ensure single line command arg
// Arg containes only digits and characters.
// Convert arg into an integer.
// What function check to see if somethig is or is not a didget?
// Use atoi function, in stdlib.h, converts srting into a number.
//
// IF alpha shift plaintext cha by key, preserving case.
// If ! apha leave cha as is. isalpah, isuper, islower. each has an asky value.
// char c = 'A' + 1;
// printf("%c", c); onve past letter Z should wrap around
// Convert plaintext to ciphertext Ci=(Pi+K) % 26
// Convert ASCII to alphabetical index. Shit alph index using formula
// Convert resulting alphaindex back to ASCII.
#include <cs50.h>

#include <stdio.h>

#include <string.h>

#include <math.h>

#include <ctype.h>

#include <stdlib.h>

bool is_valid_key(string s); // validating the key

void encrypt(string plaintext, string ciphertext, int k);

int main(int argc, string argv[])

{
    if (argc != 2 || !is_valid_key(argv[1]))
    {

        printf("Usage: ./caesar key\n");

        return 1;

    }

    int k = atoi(argv[1]);

    string s = get_string("plaintext: ");//asking for plaintext

    int n = strlen(s);

    char ciphertext[n + 1]; //
    encrypt(s, ciphertext, k);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

void encrypt(string plaintext, string ciphertext, int k)

{
    int i = 0;

    for (i = 0; i < strlen(plaintext); i++) //loops text
    {
        char ch = plaintext[i];

        // ci = (pi + k) % 26
        if (isalpha(ch))

        {
            char temp = tolower(ch);

            int pi = temp - 'a';

            char ci = ((pi + k) % 26) + 'a';

            ciphertext[i] = islower(ch) ? ci : toupper(ci);

        }

        else

        {
            ciphertext[i] = ch;
        }
    }

    ciphertext[i] = '\0';

}
bool is_valid_key(string s)

{

    for (int i = 0; i < strlen(s); i++) // function for is_valid_key

    {
        char ch = s[i];

        if (!isdigit(ch))

        {

            return false;

        }

    }

    return true;

}
