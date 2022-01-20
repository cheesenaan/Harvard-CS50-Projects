#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>




// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    loop over image height and then width -- loop over 2D array
    get each pixel from array
    get each RGB component from each pixel
    find the average
    */
    //printf("%i\n",height);
    //printf("%i\n",width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double daverage = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            int average = round(daverage / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
            int originalRed = image[i][j].rgbtRed;
            int originalGreen  = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            /*
            printf("%i\n red",originalRed);
            printf("%i\n green",originalGreen);
            printf("%i\n blue",originalBlue);
            */

            double dsRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            double dsGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            double dsBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            int sepiaRed = round(dsRed);
            int sepiaGreen = round(dsGreen);
            int sepiaBlue = round(dsBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //printf("%i\n red",sepiaRed);
            //printf("%i\n green",sepiaGreen);
            //printf("%i\n blue",sepiaBlue);

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE array[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            array[i][j] = image[i][width - j - 1];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = array[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int rightC = 0;
            int leftC = 0;
            int topR = 0;
            int bottomR = 0;

            //right column
            if ((j + 1) > width)
            {
                rightC = width;
            }
            else
            {
                rightC = j + 1;
            }

            //left column
            if ((j - 1) < 0)
            {
                leftC = 0;
            }
            else
            {
                leftC = j - 1;
            }

            //top row
            if ((i - 1) < 0)
            {
                topR = 0;
            }
            else
            {
                topR = i - 1;
            }

            //bottom row
            if ((i + 1) > height)
            {
                bottomR = height;
            }
            else
            {
                bottomR = i + 1;
            }


            //height and width of grid
            int h = abs(topR - bottomR);
            int wi = abs(rightC - leftC);


            //making new array of type RGBTRIPLE for  grid
            RGBTRIPLE grid[h][wi];

            //go through each pixel and find average of rgb
            int count = 0;
            double redSum = 0;
            double greenSum = 0;
            double blueSum = 0;

            //           max      min

            //find max for row
            int maxR = 0;
            int minR = 0;
            if (topR > bottomR)
            {
                maxR = topR;
                minR = bottomR;
            }
            else
            {
                maxR = bottomR;
                minR = topR;
            }

            //find max for columns
            int maxC = 0;
            int minC = 0;
            if (rightC > leftC)
            {
                maxC = rightC;
                minC = leftC;
            }
            else
            {
                maxC = leftC;
                minC = rightC;
            }

            //iterate through the column, from -1 to +1
            for (int z = -1; z < 2; z++)
            {
                //iterate similarly through rows
                for (int w = -1; w < 2; w++)
                {
                    //if pixel is outside the image (column)
                    if (i + z < 0 || i + z > (height - 1))
                    {
                        continue; //skip
                    }
                    //if pixel is outside the image (row)
                    if (j + w  < 0 || j + w > (width - 1))
                    {
                        continue; //skip
                    }
                    //sum up the values of all the pixels
                    blueSum += image[i + z][j + w].rgbtBlue;
                    redSum += image[i + z][j + w].rgbtRed;
                    greenSum += image[i + z][j + w].rgbtGreen;
                    count++;
                }
            }


            int redAvg = round(redSum / count);
            int greenAvg = round(greenSum / count);
            int blueAvg = round(blueSum / count);

            copy[i][j].rgbtRed = redAvg;
            copy[i][j].rgbtGreen = greenAvg;
            copy[i][j].rgbtBlue = blueAvg;

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}
