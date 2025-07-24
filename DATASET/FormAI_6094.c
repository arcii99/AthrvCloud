//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: authentic
/*
Title: C Antivirus Scanner Example
Author: Bot
Description: This program scans a specified file for virus signatures and marks them as infected.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 255
#define MAX_SIGNATURES 50
#define SIGNATURE_SIZE 10

char virus_signatures[MAX_SIGNATURES][SIGNATURE_SIZE] = {
    "e4f8d2c1",
    "1a2b3c4d",
    "deadbeef",
    "f00baa",
    "c0ffee",
    "d00d",
    "cafe",
    "babe",
    "0badf00d",
    "c001d00d",
    "f001c001",
    "f1a2f3c4",
    "b000b5e5",
    "8badf00d",
    "b16b00b5",
    "dabbad00",
    "f00dbabe",
    "c0dedead",
    "a5a5a5a5",
    "5a5a5a5a",
    "a0b0c0d0",
    "d0c0b0a0",
    "abcdef01",
    "febaadde",
    "aa55aa55",
    "55aa55aa",
    "0f0f0f0f",
    "f0f0f0f0",
    "deadc0de",
    "b00b1e5",
    "baadf00d",
    "feedface",
    "cafef00d",
    "f00df00d",
    "f000baaa",
    "0ddba11",
    "baddf00d",
    "facade",
    "ba5eba11",
    "b0551e",
    "ca55e77e",
    "c0ffee77",
    "d1edfec7",
    "dec0de",
    "c0de",
    "c01dface",
    "facec0de",
    "c0deface",
    "deadfa11",
    "1dea",
    "d15ea5e",
};

int scan(char* file_name);

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    char* file_name = argv[1];

    int result = scan(file_name);

    if(result) {
        printf("%s is infected with a virus.\n", file_name);
    } else {
        printf("%s is clean.\n", file_name);
    }

    return 0;
}

int scan(char* file_name) {
    FILE* file = fopen(file_name, "r");

    if(file == NULL) {
        printf("Could not open file %s.\n", file_name);
        return -1;
    }

    char signature[SIGNATURE_SIZE];
    int infected = 0;

    while(fread(signature, SIGNATURE_SIZE, 1, file) == 1 && !infected) {
        for(int i = 0; i < MAX_SIGNATURES; i++) {
            if(memcmp(signature, virus_signatures[i], SIGNATURE_SIZE) == 0) {
                infected = 1;
                break;
            }
        }
    }

    fclose(file);

    return infected;
}