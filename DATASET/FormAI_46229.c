//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_SIGNATURES 1000
#define SIGNATURE_LENGTH 32

char signatures[MAX_NUM_SIGNATURES][SIGNATURE_LENGTH];

void read_signatures()
{
    FILE* fp = fopen("signatures.txt", "r");
    if (fp == NULL) {
        printf("Error opening signatures file\n");
        exit(1);
    }
    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && i < MAX_NUM_SIGNATURES) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = 0;
        if (strlen(line) == SIGNATURE_LENGTH) {
            strcpy(signatures[i], line);
            i++;
        }
    }
    fclose(fp);
}

int is_hex_digit(char c)
{
    return (isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int is_valid_signature(char* signature)
{
    for (int i = 0; i < SIGNATURE_LENGTH; i++) {
        if (!is_hex_digit(signature[i])) {
            return 0;
        }
    }
    return 1;
}

int scan_file(char* filename)
{
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return 0;
    }
    char buffer[SIGNATURE_LENGTH];
    int bytes_read = fread(buffer, 1, SIGNATURE_LENGTH, fp);
    while (bytes_read == SIGNATURE_LENGTH) {
        int found = 0;
        for (int i = 0; i < MAX_NUM_SIGNATURES; i++) {
            if (memcmp(buffer, signatures[i], SIGNATURE_LENGTH) == 0) {
                printf("Found match: %s\n", signatures[i]);
                found = 1;
                break;
            }
        }
        if (found) {
            fclose(fp);
            return 1;
        }
        bytes_read = fread(buffer, 1, SIGNATURE_LENGTH, fp);
    }
    fclose(fp);
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    read_signatures();
    for (int i = 1; i < argc; i++) {
        if (scan_file(argv[i])) {
            printf("File %s is infected!\n", argv[i]);
        } else {
            printf("File %s is clean\n", argv[i]);
        }
    }
    return 0;
}