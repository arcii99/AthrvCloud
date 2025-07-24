//FormAI DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char fileName[] = "input.txt";
    int num1, num2;

    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error: Unable to open the file %s\n", fileName);
        exit(1);
    }

    if (fscanf(fp, "%d %d", &num1, &num2) != 2) {
        printf("Error: Reading failed from the file %s\n", fileName);
        fclose(fp);
        exit(1);
    }

    fclose(fp);

    if (num1 < 0 || num2 < 0) {
        printf("Error: Positive integers only\n");
        exit(1);  
    }

    int result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);

    return 0;
}