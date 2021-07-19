#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];//current pixel

            int average = round((pixel.rgbtBlue + pixel.rgbtRed + pixel.rgbtGreen) / 3.0);// calculating current pixel

            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            int sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);

            int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);

            int sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;

            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;

            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {

        int curPos = 0;

        for (int j = width - 1; j >= 0; j--, curPos++)
        {

            temp[i][curPos] = image[i][j];

        }
    }

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            image[i][j] = temp[i][j];

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];

    for (int row = 0; row < height; row++)// iterate to image
    {

        for (int col = 0; col < width; col++)
        {

            int count = 0; //sets point

            int rowCoords[] = {row - 1, row, row + 1}; // reads array of coordinates across either side of point

            int colCoords[] = {col - 1, col, col + 1}; // reads array of coordinates up and down of point

            float totalR = 0;

            float totalG = 0;

            float totalB = 0; //set color

            for (int r = 0; r < 3; r ++) // generating 9 coordunates
            {
                for (int c = 0; c < 3; c++)
                {
                    int curRow = rowCoords[r];

                    int curCol = colCoords[c];

                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {

                        RGBTRIPLE pixel = image[curRow][curCol];

                        totalR += pixel.rgbtRed;

                        totalG += pixel.rgbtGreen;

                        totalB += pixel.rgbtBlue;

                        count++;

                    }
                }
            }

            temp[row][col].rgbtRed = round(totalR / count); // determining surrounding pixels

            temp[row][col].rgbtGreen = round(totalG / count);

            temp[row][col].rgbtBlue = round(totalB / count);

        }

    }

    for (int i = 0; i < height; i++) //copying to final image
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = temp[i][j];

        }
    }


    return;
}
