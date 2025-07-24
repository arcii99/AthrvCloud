//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function prototypes
void scan(char *filename);
int check_header(FILE *fp);

//Virus signatures
char virus1[] = {0x41, 0x56, 0x41, 0x53, 0x54, 0x2E, 0x4D, 0x5A};
char virus2[] = {0x00, 0x01, 0x00, 0x00, 0x00, 0x00};

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: ./antivirus <filename>\n");
        exit(1);
    }

    //Loop through command line arguments and scan the files
    for(int i = 1; i < argc; i++) {
        scan(argv[i]);
    }

    printf("Scanning complete.\n");

    return 0;
}

void scan(char *filename) {
    //Open file
    FILE *fp = fopen(filename, "rb");

    //Check if file can be opened
    if(fp == NULL) {
        printf("Cannot open file %s.\n", filename);
        return;
    }

    //Check if file contains virus signature
    int header_check = check_header(fp);
    if(header_check == 1) {
        printf("File %s is infected with virus1.\n", filename);
    }
    else if(header_check == 2) {
        printf("File %s is infected with virus2.\n", filename);
    }
    else {
        printf("File %s is clean.\n", filename);
    }

    //Close file
    fclose(fp);

    return;
}

int check_header(FILE *fp) {
    //Read first 8 bytes of file
    char header[8];
    fread(header, 1, 8, fp);

    //Check for virus signature
    if(memcmp(header, virus1, sizeof(virus1)) == 0) {
        return 1;
    }
    else if(memcmp(header, virus2, sizeof(virus2)) == 0) {
        return 2;
    }
    else {
        return 0;
    }
}