//FormAI DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[255];

    fp = fopen("nonexistent_file.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    if (fgets(buffer, 255, fp) == NULL) {
        printf("Error: File is empty.\n");
        fclose(fp);
        return 1;
    }

    printf("The contents of the file are: %s", buffer);
    fclose(fp);

    return 0;
}