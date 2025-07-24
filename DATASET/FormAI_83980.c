//FormAI DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char filename[50], line[100], input[100], ch;
    FILE *fptr;
    time_t t;
    struct tm *tm;

    // Get the current time
    t = time(NULL);
    tm = localtime(&t);

    // Create a filename based on the current date
    sprintf(filename, "%04d-%02d-%02d-diary.txt", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday);

    // Check if the file already exists
    if ((fptr = fopen(filename, "r"))) {
        printf("File already exists. Appending to existing diary.\n");
        fclose(fptr);
        fptr = fopen(filename, "a");  // Open file in append mode
    } else {
        printf("File does not exist. Creating a new diary.\n");
        fptr = fopen(filename, "w");  // Open file in write mode
    }

    // Get the user's input and write it to the file
    printf("Write something in your diary: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove trailing newline character

    fprintf(fptr, "%02d:%02d:%02d - %s\n", tm->tm_hour, tm->tm_min, tm->tm_sec, input);
    printf("Entry added to diary.\n");

    // Print the contents of the file
    printf("Here's what's in your diary:\n");
    rewind(fptr);  // Move file pointer to beginning of file
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }

    fclose(fptr);  // Close file

    return 0;
}