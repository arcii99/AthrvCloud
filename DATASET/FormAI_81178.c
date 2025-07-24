//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 500

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *token;
    double dataset[100][4];
    int index = 0;

    fp = fopen("iris_dataset.txt", "r");

    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        token = strtok(line, ",");

        for (int i = 0; i < 4; i++) {
            dataset[index][i] = atof(token);
            token = strtok(NULL, ",");
        }

        index++;
    }

    fclose(fp);

    double mean[4] = {0};
    double min[4] = {99999, 99999, 99999, 99999};
    double max[4] = {0};

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 4; j++) {
            mean[j] += dataset[i][j];
            if (dataset[i][j] < min[j]) {
                min[j] = dataset[i][j];
            }
            if (dataset[i][j] > max[j]) {
                max[j] = dataset[i][j];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        mean[i] /= 100;
    }

    printf("Mean Values:\n");
    for (int i = 0; i < 4; i++) {
        printf("Feature %d: %lf\n", i+1, mean[i]);
    }

    printf("\nMin Values:\n");
    for (int i = 0; i < 4; i++) {
        printf("Feature %d: %lf\n", i+1, min[i]);
    }

    printf("\nMax Values:\n");
    for (int i = 0; i < 4; i++) {
        printf("Feature %d: %lf\n", i+1, max[i]);
    }

    return 0;
}