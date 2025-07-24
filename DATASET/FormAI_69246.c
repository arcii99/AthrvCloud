//FormAI DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc != 2) { // check for proper number of command line arguments
        printf("Usage: %s [filename]\n", argv[0]); // print usage statement and exit
        exit(1);
    }

    FILE* file = fopen(argv[1], "r"); // attempt to open file
    if(!file) {
        printf("Error: could not open file %s\n", argv[1]); // print error message and exit
        exit(1);
    }

    int numLines = 0; // variable to keep track of number of lines in file
    char buffer[256]; // buffer to hold lines read from file

    while(fgets(buffer, 256, file)) { // loop through lines in file
        if(strstr(buffer, "ERROR")) { // if line contains "ERROR"
            printf("Error: %s", buffer); // print line
        }
        numLines++; // increment line count
    }

    printf("Total number of lines in file: %d\n", numLines); // print total number of lines in file

    fclose(file); // close file

    return 0;
}