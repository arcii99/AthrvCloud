//FormAI DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

/* A sample dataset */
const char * dataset[MAX_ROWS][MAX_COLS] = {
    {"Name", "Age", "Gender", "Height", "Weight"},
    {"John", "23", "Male", "6'2\"", "180 lbs"},
    {"Jane", "32", "Female", "5'8\"", "150 lbs"},
    {"Dave", "27", "Male", "5'10\"", "170 lbs"},
    {"Alice", "20", "Female", "5'5\"", "140 lbs"},
    {"Tom", "45", "Male", "5'11\"", "190 lbs"},
    {"Lisa", "29", "Female", "5'4\"", "130 lbs"}
};

/* Function to convert string to integer */
int str_to_int(const char * str) {
    int val = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            val = val * 10 + (str[i] - '0');
        }
    }
    return val;
}

/* Main function */
int main() {
    char input[MAX_COLS];
    char * output[MAX_ROWS];
    int num_rows = sizeof(dataset) / sizeof(dataset[0]);
    int num_cols = sizeof(dataset[0]) / sizeof(dataset[0][0]);

    printf("Welcome to Data Mining Example Program!\n");

    /* Get input from user */
    printf("Enter a query: ");
    fgets(input, MAX_COLS, stdin);
    input[strlen(input) - 1] = '\0';

    /* Parse input */
    char * query = strtok(input, " ");
    char * criteria = strtok(NULL, " ");

    /* Iterate over dataset */
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            /* If query matches column name */
            if (strcmp(dataset[0][j], query) == 0) {
                /* Check criteria against value */
                if (strcmp(criteria, "=") == 0) {
                    if (strcmp(dataset[i][j], strtok(NULL, " ")) == 0) {
                        output[i] = dataset[i][j];
                    }
                } else if (strcmp(criteria, ">") == 0) {
                    if (str_to_int(dataset[i][j]) > str_to_int(strtok(NULL, " "))) {
                        output[i] = dataset[i][j];
                    }
                } else if (strcmp(criteria, "<") == 0) {
                    if (str_to_int(dataset[i][j]) < str_to_int(strtok(NULL, " "))) {
                        output[i] = dataset[i][j];
                    }
                } else {
                    printf("Invalid criteria!\n");
                    exit(1);
                }
            }
        }
    }

    /* Print output */
    printf("Results:\n");
    for (int i = 0; i < num_rows; i++) {
        if (output[i] != NULL) {
            printf("%s\n", output[i]);
        }
    }

    return 0;
}