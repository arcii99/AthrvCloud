//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void recoverData(void);

int main(void) {
    recoverData();
    return 0;
}

void recoverData(void) {
    char *filename = "data.txt";
    FILE *fp;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Unable to open file!");
        exit(EXIT_FAILURE);
    }

    int num;

    printf("Recovered data:\n");

    while (fscanf(fp, "%d", &num) != EOF) {
        printf("%d\n", num);
    }

    fclose(fp);
    printf("\nData recovery successful!\n");
}