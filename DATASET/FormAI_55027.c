//FormAI DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 100

int main() {
    FILE *fp;
    char *filename = "data.txt";
    char lines[MAX_LINES][MAX_CHARS_PER_LINE];
    int num_lines = 0, i, j;

    // Read the file
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    while (fgets(lines[num_lines], MAX_CHARS_PER_LINE, fp) != NULL) {
        num_lines++;
        if (num_lines == MAX_LINES) {
            printf("Too many lines in file!\n");
            break;
        }
    }

    fclose(fp);

    // Manipulate the data
    for (i = 0; i < num_lines; i++) {
        for (j = 0; j < strlen(lines[i]); j++) {
            if (lines[i][j] >= 'a' && lines[i][j] <= 'z') {
                lines[i][j] += 'A' - 'a'; // Convert lowercase to uppercase
            }
        }
    }

    // Write to the file
    if ((fp = fopen(filename, "w")) == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    for (i = 0; i < num_lines; i++) {
        fputs(lines[i], fp);
    }

    fclose(fp);

    return 0;
}