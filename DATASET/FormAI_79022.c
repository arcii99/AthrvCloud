//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PARANOID_LEVEL 10 // A higher value indicates higher paranoia

void extractMetadata(char* filePath);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./metadata_extractor <file_path>\n");
        exit(1);
    }

    char* filePath = argv[1];
    extractMetadata(filePath);

    return 0;
}

void extractMetadata(char* filePath) {
    char command[256] = {0};
    strcat(command, "exiftool ");
    strcat(command, filePath);

    // Adding paranoid flags to the command based on the paranoid level
    switch (PARANOID_LEVEL) {
        case 10:
            strcat(command, " -unsafe");
        case 9:
            strcat(command, " -use");
        case 8:
            strcat(command, " -k");
        case 7:
            strcat(command, " -a");
        case 6:
            strcat(command, " -recurse");
        case 5:
            strcat(command, " -head");
        case 4:
            strcat(command, " -charset");
        case 3:
            strcat(command, " -fast");
        case 2:
            strcat(command, " -m");
        case 1:
            strcat(command, " -u");
        default:
            strcat(command, " -q");
    }
    
    // Running the command and capturing the output
    char output[65536] = {0};
    FILE* fp = popen(command, "r");
    fread(output, 1, sizeof(output), fp);
    pclose(fp);

    // Printing the metadata if there is any
    if (strlen(output) == 0) {
        printf("No metadata found in the file.\n");
    } else {
        printf("Metadata extracted successfully:\n%s", output);
    }
}