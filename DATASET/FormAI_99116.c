//FormAI DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char filename[100];
    FILE *fp;
    int i, n, sum = 0;
    float avg;
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }
    fscanf(fp, "%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
        sum += arr[i];
    }
    avg = (float)sum / n;
    printf("The average of %d numbers in file \"%s\" is %.2f.\n", n, filename, avg);
    fclose(fp);
    free(arr);
    return 0;
}