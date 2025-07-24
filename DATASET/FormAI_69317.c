//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char file_name[100];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s", file_name);
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    long int size = ftell(file);
    fclose(file);

    printf("The size of %s is %ld bytes\n", file_name, size);

    return 0;
}