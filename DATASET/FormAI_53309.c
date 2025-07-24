//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576 //1 MB

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 0;
    }

    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("File \"%s\" not found.\n", argv[1]);
        return 0;
    }

    char *buffer = (char*) malloc(MAX_FILE_SIZE);
    if (buffer == NULL) {
        printf("Error: failed to malloc() buffer.\n");
        fclose(f);
        return 0;
    }

    fread(buffer, MAX_FILE_SIZE, 1, f);
    fclose(f);

    /* ============= SHAPE SHIFTING STARTS HERE ============== */

    // Convert buffer to uppercase
    for (int i=0; i<MAX_FILE_SIZE && buffer[i] != 0; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            buffer[i] -= 32;
        }
    }

    // Reorder bytes
    for (int i=0; i<MAX_FILE_SIZE-1; i=i+2) {
        char temp = buffer[i];
        buffer[i] = buffer[i+1];
        buffer[i+1] = temp;
    }

    // Add random characters
    const char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()-_=+[]{};:'\",.<>/?|\\";
    for (int i=0; i<MAX_FILE_SIZE; i++) {
        if (buffer[i] == 0) {
            buffer[i] = characters[rand() % sizeof(characters)];
        }
    }

    /* ============= SHAPE SHIFTING ENDS HERE ============== */

    // Scan for virus signatures
    const char virus1[] = "malware";
    const char virus2[] = "virus";
    const char virus3[] = "trojan";
    const char *result = strstr(buffer, virus1);
    if (result != NULL) {
        printf("File \"%s\" is infected with \"%s\".\n", argv[1], virus1);
    }

    result = strstr(buffer, virus2);
    if (result != NULL) {
        printf("File \"%s\" is infected with \"%s\".\n", argv[1], virus2);
    }

    result = strstr(buffer, virus3);
    if (result != NULL) {
        printf("File \"%s\" is infected with \"%s\".\n", argv[1], virus3);
    }

    printf("File \"%s\" is virus-free.\n", argv[1]);
    free(buffer);
    return 0;
}