//FormAI DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char filename[100], buff[1024];
    int bytesRead, lineNumber = 1;

    // Opening the log file
    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Start analyzing the log file
   while(fgets(buff,sizeof(buff),fptr) != NULL) {
       if (strstr(buff,"ERROR") != NULL) {
           printf("Error found on line %d: %s", lineNumber, buff);
       }
       lineNumber++;
    }

    // Closing the file
    fclose(fptr);

    return 0;
}