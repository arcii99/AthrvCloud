//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define FILE_SIGNATURE_LEN 4

char* virus_signature = "VRSN";

int scan_file(char* file_name) {
    FILE* file = fopen(file_name, "rb");

    if(file == NULL) {
        printf("Can't open file: %s\n", file_name);
        return 0;
    }

    char signature[FILE_SIGNATURE_LEN];
    fread(signature, 1, FILE_SIGNATURE_LEN, file);

    if(memcmp(signature, virus_signature, FILE_SIGNATURE_LEN) == 0) {
        printf("File: %s is infected with virus\n", file_name);
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}

int main() {
    int num_files;
    char file_name[MAX_FILE_NAME_LEN];

    printf("Enter the number of files you want to scan: ");
    scanf("%d", &num_files);

    for(int i=0; i<num_files; i++) {
        printf("Enter the file name with complete path: ");
        scanf("%s", file_name);

        if(scan_file(file_name) == 0) {
            printf("File: %s is clean\n", file_name);
        }
    }

    return 0;
}