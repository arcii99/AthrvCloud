//FormAI DATASET v1.0 Category: Error handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int num;

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error: file failed to open.\n");
        exit(0);
    }

    if (fscanf(file, "%d", &num) != 1) {
        printf("Error: invalid data format.\n");
        fclose(file);
        exit(0);
    }

    if (num < 0 || num > 100) {
        printf("Error: number is out of range.\n");
        fclose(file);
        exit(0);
    }

    printf("The number is %d\n", num);

    fclose(file);
    exit(0);
}