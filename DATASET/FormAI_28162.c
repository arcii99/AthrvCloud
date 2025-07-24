//FormAI DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 1024

// Function to recover data from a file
int recover_data(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Failed to open file %s\n", filename);
        return 1;
    }

    char buffer[MAX_DATA];
    int data_found = 0;
    while (fgets(buffer, MAX_DATA, fp)) {
        if (strstr(buffer, "DATA")) {
            printf("Recovered data: %s", buffer);
            data_found = 1;
        }
    }

    if (!data_found) {
        printf("No data found in file %s\n", filename);
    }

    fclose(fp);
    return 0;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int status = recover_data(argv[1]);
    if (status) {
        printf("Data recovery failed\n");
        return 1;
    }

    printf("Data recovery successful\n");
    return 0;
}