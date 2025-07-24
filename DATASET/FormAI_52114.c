//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50];
    int num, sum = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening the file\n");
        return 1;
    }

    printf("Numbers in the file:\n");

    while (!feof(fp)) {
        fscanf(fp, "%d", &num);
        printf("%d\n", num);
        sum += num;
    }

    printf("The sum of the numbers is %d\n", sum);

    fclose(fp);

    return 0;
}