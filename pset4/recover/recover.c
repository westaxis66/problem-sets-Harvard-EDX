#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{

    if (argc != 2)
    {

        printf("Usage: ./recover image\n");

        return 1;

    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {

        printf("Error occured opening the raw file.\n");

        return 1;

    }

    typedef uint8_t BYTE; // check to see if its unit or uint

    BYTE buffer[BLOCK_SIZE]; // valid file 

    size_t bytes_read;

    bool is_first_jpeg = false;

    FILE *current_file;

    char current_filename[100];

    int current_filenumber = 0;

    bool found_jpeg = false;

    // make valid file // open memory card
    while (true)
    {

        bytes_read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file);//repeat until end of card and read bytes into buffer

        if (bytes_read == 0)
        {

            break;//end file

        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            found_jpeg = true;

            if (!is_first_jpeg) //if first jpeg mark
            {

                is_first_jpeg = true;

            }

            else
            {

                fclose(current_file);  //close current file 

            }

            sprintf(current_filename, "%03i.jpg", current_filenumber);

            current_file = fopen(current_filename, "w");

            fwrite(buffer, sizeof(BYTE), bytes_read, current_file);

            current_filenumber++;


        }

        else
        {

            if (found_jpeg)
            {

                fwrite(buffer, sizeof(BYTE), bytes_read, current_file);

            }
        }
    }

    fclose(file);

    fclose(current_file);

    return 0;


}
