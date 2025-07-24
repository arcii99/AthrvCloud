//FormAI DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_ROWS 1000

int main() {
	char data[MAX_ROWS][MAX_COLS][30];
	int rows = 0, cols = 0;
	float mean[MAX_COLS] = {0};
	FILE *fp;
	fp = fopen("data.csv", "r");
	if (fp == NULL) {
		printf("Error opening file\n");
		exit(1);
	}
	while (fgets(data[rows][0], 30, fp) != NULL) {
		char *token = strtok(data[rows][0], ",");
		cols = 0;
		while (token != NULL) {
			strcpy(data[rows][cols], token);
			token = strtok(NULL, ",");
			cols++;
		}
		rows++;
	}
	fclose(fp);
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			mean[j] += atof(data[i][j]);
		}
		mean[j] /= rows;
		printf("Mean of column %d: %.2f\n", j+1, mean[j]);
	}
	return 0;
}