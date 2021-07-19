#include <cs50.h>

#include <stdio.h>

#include <math.h>

int main(void)
//Should promt user for an amount of chanege owed:
//Use the largest coins possible, keeping track of coins used.
// Print nuber of coins
// Using do while loops

{
    float dollars;

    do

    {

        dollars = get_float("change owed?: ");// Prompting the user for input. use get_float. Accept only non-negaative input.

    }

    while (dollars <= 0);

    int cents = round(dollars * 100); //Convert dollars to cents . Multiply dollars by 100

    int coins = 0;

    while (cents >= 25) //  Subtract 25 until less than 25.

    {

        coins++; //number of coins added
      
        cents -= 25;

    }

    while (cents >= 10) //Subtract 10 until less than 10

    {

        coins++;

        cents -= 10;


    }

    while (cents >= 5) // subtract 5 until less thn 5

    {

        coins++;

        cents -= 5;

    }

    while (cents >= 1) //subtract 1 until less than 1

    {

        coins++;

        cents -= 1;

    }

    //Figure out how many coins to make said amount of change.
    //Compution coins.
    //Keep track of remaining changed owed.
    //Keep track of how many coins used.
    // Maybe use loops.
    //Other approcahes is to consider how much change is left over after using as many said coins as possibe.


    printf("%i\n", coins); // substitute in the value of the variable  coin. Print result.

}
