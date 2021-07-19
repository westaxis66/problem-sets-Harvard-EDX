#include <cs50.h>

#include <stdio.h>

int main(void)
{
    int h;
    
    do

    {
        h = get_int("height: ") ;
    }

    while (h < 1 || h > 8);       // h is height, setting condition

    for (int r = 1; r <= h; r++)  // r is row, number of rows the number of hashmarks  
    {
        
        for (int s = 0; s < h - r; s++)  // s is space to align hashmarks to the right
        {

            printf(" ");    //prints spaces 
         
        }

        for (int t = 1; t <= r; t++)  // print the row how many times 
        
        {
            printf("#");     //prints hashmarks
        
        }
    
        printf("\n");    // prints ne line 

    }
    return 0;

}

