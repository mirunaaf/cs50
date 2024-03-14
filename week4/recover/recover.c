#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check if proper input
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //open file for reading
    FILE *input_file = fopen(argv[1], "r");

    //check that input file is valid
    if (input_file == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 2;
    }

    //store blocks of 512 bytes in an array
    unsigned char buffer[512];

    //track number of images
    int image_counter = 0;

    //file pointer for recovered images
    FILE *output_file = NULL;

    //allocate memory for filename storage
    char *filename = malloc(8 * sizeof(char));

    if (filename == NULL)
    {
        printf("Memory allocation failed.\n");
        return 3;
    }

    //read blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file) == 512)
    {
        //check if beginning of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //close output_file if jpeg found before and written into ###.jpg
            // if (output_file == NULL)
            // {
            //     fclose(output_file);
            // }
            //write the JPEG filenames
            sprintf(filename, "%03i.jpg", image_counter);

            //open a new output_file for writing a new found jpeg
            output_file = fopen(filename, "w");

            //count images
            image_counter++;
        }

        //keep writing to jpeg file if new jpeg is not found
        if(output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(input_file);
    fclose(output_file);

    return 0;
}
