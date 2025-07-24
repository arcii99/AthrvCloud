//FormAI DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program reads a C log file and analyzes it by searching for certain keywords
 * and counting their occurrences. The program prints out the results of the analysis.
 */

#define MAX_LINE_LENGTH 1000 // set the maximum line length to read

int main(int argc, char *argv[]) {
    char *filename = argv[1]; // get the filename from command line argument
    char line[MAX_LINE_LENGTH]; // buffer for each line read from file
    int line_count = 0; // count of total lines
    int keyword1_count = 0; // count of keyword 1 occurrences
    int keyword2_count = 0; // count of keyword 2 occurrences
    int keyword3_count = 0; // count of keyword 3 occurrences
    FILE *fp = fopen(filename, "r"); // open the file for reading
    if (fp == NULL) { // check if file could not be opened
        printf("Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE); // exit the program with a failure status
    }
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) { // read each line from file
        line_count++; // increment line count
        if (strstr(line, "Keyword1") != NULL) { // check if keyword 1 is present in line
            keyword1_count++; // increment keyword 1 count
        }
        if (strstr(line, "Keyword2") != NULL) { // check if keyword 2 is present in line
            keyword2_count++; // increment keyword 2 count
        }
        if (strstr(line, "Keyword3") != NULL) { // check if keyword 3 is present in line
            keyword3_count++; // increment keyword 3 count
        }
    }
    printf("Total lines read: %d\n", line_count); // print total lines count
    printf("Keyword1 count: %d\n", keyword1_count); // print keyword 1 count
    printf("Keyword2 count: %d\n", keyword2_count); // print keyword 2 count
    printf("Keyword3 count: %d\n", keyword3_count); // print keyword 3 count
    fclose(fp); // close the file
    return 0; // exit the program with success status
}