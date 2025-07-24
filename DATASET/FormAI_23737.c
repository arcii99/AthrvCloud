//FormAI DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    char filename[50], date[15], entry[500];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Welcome to Digital Diary!\n\n");
    printf("Enter today's date (dd/mm/yyyy): ");
    scanf("%s", date);
    sprintf(filename, "%s.txt", date);

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: Could not create file.");
        return 1;
    }

    printf("\nStart typing your entry below:\n");
    printf("(Press Ctrl+D or Ctrl+Z to save and exit)\n\n");
    getchar();

    while (fgets(entry, 500, stdin)) {
        fprintf(fp, "%s", entry);
    }

    printf("\nEntry saved successfully!\n");

    fclose(fp);

    return 0;
}