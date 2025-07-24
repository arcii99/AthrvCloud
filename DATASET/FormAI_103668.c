//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_LEN 256
#define SIGNATURE_LEN 256
#define VIRUS_LIST_SIZE 3

int scan_file(char *file_name, char **virus_list, int virus_list_size) {
    FILE *fp;
    char signature[SIGNATURE_LEN];
    int i, j;
    int virus_found = 0;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", file_name);
        return 0;
    }

    // read signature from file
    fgets(signature, SIGNATURE_LEN, fp);

    // check if signature matches any virus signature
    for (i = 0; i < virus_list_size; i++) {
        for (j = 0; j < SIGNATURE_LEN; j++) {
            if (virus_list[i][j] != signature[j]) {
                break;
            }
        }
        if (j == SIGNATURE_LEN) {
            printf("Virus found in file: %s\n", file_name);
            virus_found = 1;
            break;
        }
    }

    fclose(fp);

    return virus_found;
}

int main() {
    char *virus_list[VIRUS_LIST_SIZE] = {
        "This is malicious code signature",
        "Another malicious code signature",
        "Yet another malicious code signature"
    };

    char file_name[FILE_NAME_LEN];
    int virus_found = 0;

    printf("Enter file name to scan: ");
    fgets(file_name, FILE_NAME_LEN, stdin);
    file_name[strcspn(file_name, "\r\n")] = 0;

    virus_found = scan_file(file_name, virus_list, VIRUS_LIST_SIZE);

    if (!virus_found) {
        printf("No virus found in file: %s\n", file_name);
    }

    return 0;
}