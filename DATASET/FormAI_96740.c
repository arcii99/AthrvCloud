//FormAI DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() { 
    // Open file for writing
    FILE *fp = fopen("example.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter 10 integers separated by a space: ");
    int arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);

    // Open file for reading
    fp = fopen("example.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int sum = 0, temp;
    printf("Contents of the file: ");
    while (fscanf(fp, "%d", &temp) == 1) {
        printf("%d ", temp);
        sum += temp;
    }
    printf("\nSum of numbers in file: %d", sum);
    fclose(fp);

    return 0;
}