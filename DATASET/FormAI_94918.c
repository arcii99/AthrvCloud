//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: grateful
//Welcome to my unique C Metadata Extractor program!
//I'm thrilled to show you how I can extract metadata from a file.
//This program will not only impress you, it will also be extremely useful for your needs!

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    //Check if the user has provided a filename as an argument.
    if(argc < 2) {
        printf("Please provide a filename as an argument.\n");
        return 1;
    }

    //Open the file in read mode.
    FILE *fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    //Read the metadata from the file.
    char metadata[100];
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, -100, SEEK_END);
    fread(metadata, 100, 1, fp);

    //Close the file.
    fclose(fp);

    //Print the metadata.
    printf("Metadata:\n%s", metadata);

    //Return 0 to indicate success.
    return 0;
}