//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>

int main()
{
    // Define input and output file names
    char input_file[100], output_file[100];
    printf("Enter the input file name: ");
    scanf("%s", input_file);
    printf("Enter the output file name: ");
    scanf("%s", output_file);

    // Open input and output files
    FILE *in_file = fopen(input_file, "rb");
    FILE *out_file = fopen(output_file, "wb");

    // Define the watermark message
    char watermark[] = "This is a watermark message.";

    // Read input file byte by byte and write to output file
    int byte_index = 0;
    char byte;
    while(fread(&byte, sizeof(char), 1, in_file) == 1)
    {
        // Write the watermark message to the first few bytes of the file
        if(byte_index < sizeof(watermark))
        {
            byte = watermark[byte_index];
        }
        byte_index++;
        fwrite(&byte, sizeof(char), 1, out_file);
    }

    // Close input and output files
    fclose(in_file);
    fclose(out_file);

    // Print success message
    printf("Watermarking successful!\n");

    return 0;
}