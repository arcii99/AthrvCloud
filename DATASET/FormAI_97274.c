//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to perform digital watermarking
void digitalWatermark(char* input_file, char* output_file, char* watermark_message){
    FILE* fin = fopen(input_file, "rb"); // Opening the input file in binary mode
    FILE* fout = fopen(output_file, "wb"); // Opening the output file in binary mode

    if(fin == NULL || fout == NULL){ // Check if input/output file exists
        printf("Error in opening the input/output file\n");
        exit(0);
    }

    fseek(fin, 0, SEEK_END); // fseek to end of file
    long int size = ftell(fin); // ftell gives the position of file pointer
    rewind(fin); // Returns file pointer to the beginning of file

    fwrite(watermark_message, sizeof(char), strlen(watermark_message), fout); // Writing watermark message to output file
    fwrite(&size, sizeof(long int), 1, fout); // Writing size of input file to output file

    char c;
    while(fread(&c, sizeof(char), 1, fin) == 1){ // Loop through input file one character at a time
        fwrite(&c, sizeof(char), 1, fout); // Write each character to the output file
    }

    fclose(fin); // Close input file
    fclose(fout); // Close output file
    printf("Digital watermarking completed successfully!\n");
}

int main(){
    char input_file[] = "input.txt"; // Input file name
    char output_file[] = "output.txt"; // Output file name
    char watermark_message[] = "This file has been watermarked!"; // Watermark message

    digitalWatermark(input_file, output_file, watermark_message); // Function to perform digital watermarking
    return 0;
}