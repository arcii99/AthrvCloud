//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_ASCII_LEN 120

int main() {
    char string[MAX_STR_LEN];
    char ascii_art[MAX_ASCII_LEN][MAX_ASCII_LEN];

    printf("Enter a string to convert to ASCII art:\n");
    fgets(string, MAX_STR_LEN, stdin);
    string[strcspn(string, "\n")] = '\0';

    int len = strlen(string);
    int row = 0, col = 0, i = 0;

    while (i < len) {
        int ascii_num = (int)string[i];

        if (ascii_num >= 97 && ascii_num <= 122) {
            // lowercase letters
            FILE *fp = fopen("ascii_lowercase.txt", "r");
            if (fp == NULL) {
                printf("Error opening file.\n");
                exit(1);
            }
            char line[MAX_ASCII_LEN];
            while (fgets(line, MAX_ASCII_LEN, fp) != NULL) {
                line[strcspn(line, "\n")] = '\0';
                strcat(ascii_art[row], line);
                row++;
            }
            fclose(fp);
        } else if (ascii_num >= 65 && ascii_num <= 90) {
            // uppercase letters
            FILE *fp = fopen("ascii_uppercase.txt", "r");
            if (fp == NULL) {
                printf("Error opening file.\n");
                exit(1);
            }
            char line[MAX_ASCII_LEN];
            while (fgets(line, MAX_ASCII_LEN, fp) != NULL) {
                line[strcspn(line, "\n")] = '\0';
                strcat(ascii_art[row], line);
                row++;
            }
            fclose(fp);
        } else if (ascii_num >= 48 && ascii_num <= 57) {
            // numbers
            FILE *fp = fopen("ascii_numbers.txt", "r");
            if (fp == NULL) {
                printf("Error opening file.\n");
                exit(1);
            }
            char line[MAX_ASCII_LEN];
            while (fgets(line, MAX_ASCII_LEN, fp) != NULL) {
                line[strcspn(line, "\n")] = '\0';
                strcat(ascii_art[row], line);
                row++;
            }
            fclose(fp);
        } else if (ascii_num == 32) {
            // space
            for (int j = 0; j < 7; j++) {
                strcat(ascii_art[row], " ");
            }
            row++;
        }
        col += 8;
        i++;
    }

    // print ASCII art
    for (int k = 0; k < 7; k++) {
        for (int l = 0; l < row; l++) {
            printf("%c", ascii_art[l][k]);
        }
        printf("\n");
    }
    return 0;
}