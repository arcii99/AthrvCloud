//FormAI DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
// C Ebook Reader Example Program
// Written in the style of Claude Shannon

#include <stdio.h>

int main() {
    // Opening file
    FILE *fp;
    char filename[20];
    printf("Enter ebook filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    // Checking if file exists
    if (fp == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    // Reading file line by line
    char line[100];
    int line_num = 1;
    while (fgets(line, 100, fp) != NULL) {
        printf("%d: %s", line_num, line);
        line_num++;
    }

    // Closing file
    fclose(fp);
    return 0;
}