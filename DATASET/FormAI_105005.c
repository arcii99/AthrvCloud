//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: paranoid
#include <stdio.h>
#include <string.h>

int scan(char *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (scan(argv[1]) == 0)
        printf("File \"%s\" is safe\n", argv[1]);
    else
        printf("File \"%s\" is infected\n", argv[1]);

    return 0;
}

int scan(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file \"%s\"\n", filename);
        return -1;
    }

    // Check for signature of known viruses
    char signature[] = "1234567890!@#$%^&*()qwertyuiop[]\\asdfghjkl;'zxcvbnm,./{}|:\"<>?";
    char buffer[sizeof(signature)];
    memset(buffer, 0, sizeof(buffer));

    int len = sizeof(signature);
    int count = 0;
    while (fread(buffer, len, 1, fp) > 0) {
        if (memcmp(buffer, signature, len) == 0) {
            count++;
        }
        memset(buffer, 0, sizeof(buffer));
    }

    fclose(fp);

    // If there are more than 10 occurrences of the signature, assume the file is infected
    if (count >= 10)
        return 1;
    else
        return 0;
}