//FormAI DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main() 
{ 
    FILE *fp;

    // Create a file pointer
    fp = fopen("diary.txt", "a+");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Get current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Write the date to the file
    fprintf(fp, "\n\n%d-%d-%d\n", t->tm_mday, t->tm_mon+1, t->tm_year+1900);

    // Ask user for input
    printf("What did you do today?\n");
    char input[256];
    fgets(input, 256, stdin);

    // Write input to file
    fprintf(fp, "%s\n", input);

    // Close file
    fclose(fp);

    printf("Entry saved successfully!\n");

    return 0; 
}