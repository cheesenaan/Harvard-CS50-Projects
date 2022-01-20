#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    //command line error check
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //make buffer array of type BYTE to store each block from mememory into buffer array
    BYTE buffer[512];
    /*

    command line check

    open input file
    check input file exists - ie is not NULL

    buffer : array of type BYTE. need space for 512 bytes.

    iterate through card blocks - each 512 bytes
    read one block at a time into buffer

    read first four bytes of the block at hand
    check if the header if jpeg

    if header is jpeg : create a new file to write this data to. keep writing until new jpeg is found
                        ie keep reading blocks until a new block of new jpeg header is found


    */

    //declare img FILE for output
    FILE *img;

    //counters
    int countFiles = 0;
    int x = 0;
    int count = 0;
    int headerCount = 0;

    while (fread(&buffer, 512, 1, input) > 0)
    {

        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            headerCount++;

            if (headerCount == 1)
            {
                //make new space
                char *filename = malloc(3);
                //make new file
                sprintf(filename, "%03i.jpg", countFiles);
                img = fopen(filename, "w");
                countFiles++;
                //write to new file
                fwrite(&buffer, 512, 1, img);

            }
            else
            {
                //close old image if new jpg header found
                if (img != NULL)
                {

                    fclose(img);
                }
                //allocate space for file name
                char *filename = malloc(3);
                //make file
                sprintf(filename, "%03i.jpg", countFiles);
                img = fopen(filename, "w");
                countFiles++;
                //write to new file
                fwrite(&buffer, 512, 1, img);
            }
        }
        else //if not new jpg header
        {
            if (headerCount != 0)
            {
                fwrite(&buffer, 512, 1, img);
            }
        }
        x++;
    }
    //fclose(img);


}
