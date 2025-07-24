//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: ./antivirus [filename]\n");
        return 1;
    }
    
    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");
    
    if(fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    
    char* extension = strrchr(filename, '.');
    
    if(extension == NULL) {
        printf("Error: Filename does not have an extension\n");
        fclose(fp);
        return 1;
    }
    
    if(strncmp(extension, ".exe", 4) != 0) {
        printf("File is safe. Extension is %s\n", extension);
        fclose(fp);
        return 0;
    }
    
    printf("Warning: File may be a virus. Extension is %s\n", extension);
    fclose(fp);
    return 1;
}