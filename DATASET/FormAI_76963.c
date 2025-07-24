//FormAI DATASET v1.0 Category: QR code reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_BUF 256

int main(int argc, char *argv[]) {
    FILE *f;
    char str[MAX_BUF];
    char *token;
    bool code_found = false;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 0;
    }

    while (fgets(str, MAX_BUF, f) != NULL) {
        token = strtok(str, " \t\n");
        while (token != NULL) {
            if (strcmp(token, "QR") == 0) {
                code_found = true;
                break;
            }
            token = strtok(NULL, " \t\n");
        }
        if (code_found) {
            printf("QR code found!\n");
            break;
        }
    }

    if (!code_found) {
        printf("No QR code found.\n");
    }

    fclose(f);

    return 0;
}