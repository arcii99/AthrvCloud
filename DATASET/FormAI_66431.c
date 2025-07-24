//FormAI DATASET v1.0 Category: Text processing ; Style: scientific
//This program processes scientific data and outputs the result in a user-friendly format
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

int main() {
    char data[MAX_LEN]; //data string to be processed
    float value; //value extracted from the data string
    char unit[MAX_LEN]; //unit extracted from the data string
    char output[MAX_LEN]; //formatted output string
    int count = 0; //number of data strings processed
    
    FILE *input_file = fopen("input.txt", "r"); //open input file for reading
    if (input_file == NULL) {
        printf("Error: Could not open input file!\n");
        exit(1);
    }
    
    FILE *output_file = fopen("output.txt", "w"); //open output file for writing
    if (output_file == NULL) {
        printf("Error: Could not open output file!\n");
        exit(1);
    }
    
    while (fgets(data, MAX_LEN, input_file) != NULL) { //loop through each line of the input file
        count ++;
        
        //extract value and unit from data string
        sscanf(data, "%f %s", &value, unit);
        
        //perform data processing and create output string
        float processed_data = value * 2.5; //example of data processing
        sprintf(output, "Data point %d: %.2f %s processed to %.2f V\n", count, value, unit, processed_data);
        
        //write output string to output file
        fputs(output, output_file);
    }
    
    fclose(input_file); //close input file
    fclose(output_file); //close output file
    
    printf("Data processing complete!\n");
    
    return 0;
}