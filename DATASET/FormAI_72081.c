//FormAI DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 100

/**
 * Function to read the data file and store the data in a 2D array
 */
int read_data(char *filename, char data[][MAX_CHARS_PER_LINE], int max_lines)
{
    FILE *fp;
    char line[MAX_CHARS_PER_LINE];
    int line_count = 0;
    
    // Open the data file for reading
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    
    // Read each line of the data file and store it in the 2D array
    while(fgets(line, MAX_CHARS_PER_LINE, fp) != NULL && line_count < max_lines)
    {
        strcpy(data[line_count], line);
        line_count++;
    }
    
    // Close the data file
    fclose(fp);
    
    return line_count;
}

/**
 * Function to print the contents of the data array
 */
void print_data(char data[][MAX_CHARS_PER_LINE], int line_count)
{
    for(int i=0; i<line_count; i++)
    {
        printf("%s", data[i]);
    }
}

int main(int argc, char *argv[])
{
    char data[MAX_LINES][MAX_CHARS_PER_LINE];
    int line_count = 0;
    
    // Check if the filename is provided as command line argument
    if(argc != 2)
    {
        printf("Usage: %s [data_file]\n", argv[0]);
        return -1;
    }
    
    // Read the data file
    line_count = read_data(argv[1], data, MAX_LINES);
    if(line_count == -1)
    {
        return -1;
    }
    
    // Print the data
    print_data(data, line_count);
    
    return 0;
}