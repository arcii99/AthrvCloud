//FormAI DATASET v1.0 Category: Data recovery tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILESIZE 1024

void recover_data(char *filename) {
    char data[MAX_FILESIZE];
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file \"%s\"\n", filename);
        return;
    }
    fread(data, sizeof(char), MAX_FILESIZE, fp);
    fclose(fp);

    char recovered_data[MAX_FILESIZE];
    int idx = 0;
    for (int i = 0; i < MAX_FILESIZE; i++) {
        if ((int)data[i] == 0) {
            printf("Data recovery complete.\nRecovered data: %s\n", recovered_data);
            return;
        } else if ((int)data[i] % 2 == 0) {
            recovered_data[idx] = (char)((int)data[i] / 2);
        } else {
            recovered_data[idx] = (char)((int)data[i] * 2);
        }
        idx++;
    }
    printf("Data recovery failed. Max filesize reached.\n");
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Data Recovery Tool\n");
    printf("Please enter the filename (including extension): ");
    scanf("%s", filename);

    recover_data(filename);

    return 0;
}