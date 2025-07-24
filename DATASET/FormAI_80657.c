//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    // check if the user provided a file name
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    // open the file
    FILE *file = fopen(filename, "r");

    // check if the file was opened successfully
    if(!file) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // flag to keep track if the virus was found
    int virus_found = 0;

    // read the file line by line
    char line[1024];
    while(fgets(line, sizeof(line), file)) {
        // check if the line contains the virus signature
        if(strstr(line, "virus_signature")) {
            printf("Virus found!\n");
            virus_found = 1;
            break;
        }
    }

    // close the file
    fclose(file);

    if(!virus_found) {
        printf("No virus found\n");
    }

    return 0;
}