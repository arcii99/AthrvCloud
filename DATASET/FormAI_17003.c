//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[100];
    double num, sum = 0;
    int count = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    while (fscanf(fp, "%lf", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(fp);

    printf("Read %d numbers from file, sum = %g\n", count, sum);

    fp = fopen(filename, "a");

    if (fp == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    fprintf(fp, "Average: %g\n", sum/count);

    fclose(fp);

    printf("Data written to file.\n");

    return 0;
}