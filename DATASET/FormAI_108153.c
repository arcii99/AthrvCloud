//FormAI DATASET v1.0 Category: File handling ; Style: active
#include<stdio.h>

int main(){
    FILE *input_file, *output_file;
    char input_filename[] = "input.txt";
    char output_filename[] = "output.txt";
    char buffer[100];

    // Opening the input and output files
    input_file = fopen(input_filename, "r");
    output_file = fopen(output_filename, "w");

    // Checking if the files have been opened successfully
    if(input_file == NULL){
        printf("Error opening input file\n");
        exit(1);
    }
    if(output_file == NULL){
        printf("Error opening output file\n");
        exit(1);
    }

    // Reading from the input file and writing to the output file
    while(fgets(buffer, 100, input_file)){
        fputs(buffer, output_file);
    }

    // Closing the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Contents of input.txt have been copied to output.txt\n");

    return 0;
}