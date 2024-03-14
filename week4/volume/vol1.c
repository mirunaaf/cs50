// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    char header_buffer[HEADER_SIZE];
    size_t bytes_read = fread(&header_buffer, 1, HEADER_SIZE, input);
    if (bytes_read != HEADER_SIZE){
        fclose(input);
        fclose(output);
        return 1;
    }
    //write the header to the output
    size_t bytes_written = fwrite(&header_buffer, 1, HEADER_SIZE, output);

     if (bytes_written != HEADER_SIZE){
        fclose(input);
        fclose(output);
        return 1;
    }
    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}
