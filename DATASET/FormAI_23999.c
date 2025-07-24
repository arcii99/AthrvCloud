//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_SIGNATURE_LENGTH 10

typedef struct signature {
    char hex[MAX_SIGNATURE_LENGTH];
} Signature;

int scan_file(char *filename, Signature *signatures, int num_signatures);

int main(void) {
    Signature signatures[] = {
        {"4d 5a"}, // exe
        {"23 21 41 4d 52 0a 23 21 69 6e 63 6c 75 64 65 20 22 73 74 64 69 6f 2e 68 22 0a"},
        // shell script
        {"23 21 2f 62 69 6e 2f 62 61 73 68 0a"}
    };
    int num_signatures = sizeof(signatures) / sizeof(Signature);
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    // remove newline character from fgets input
    filename[strcspn(filename, "\n")] = 0;
    int result = scan_file(filename, signatures, num_signatures);
    if (result == 1) {
        printf("File %s is infected.\n", filename);
    } else {
        printf("File %s is clean.\n", filename);
    }
    return 0;
}

int scan_file(char *filename, Signature *signatures, int num_signatures) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }
    char buffer[MAX_SIGNATURE_LENGTH];
    for (int i = 0; i < num_signatures; i++) {
        Signature signature = signatures[i];
        fseek(file, 0, SEEK_SET);
        fread(buffer, 1, sizeof(signature.hex), file);
        if (memcmp(buffer, signature.hex, sizeof(signature.hex)) == 0) {
            fclose(file);
            return 1; // file is infected
        }
    }
    fclose(file);
    return 0; // file is clean
}