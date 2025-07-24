//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {

    //Create and open file
    FILE *filePtr;

    filePtr = fopen("happy.txt", "w");

    //Check for null pointer
    if(filePtr == NULL) {
        printf("Oops! File could not be opened.");
        exit(1);
    }

    char happyMessage[50] = "I am feeling absolutely fantastic today!";

    //Write to file
    fprintf(filePtr, "Happy File Handling Example:\n");
    fprintf(filePtr, "----------------------------\n");
    fprintf(filePtr, "Today's happy message is:\n\n");
    fprintf(filePtr, "%s\n", happyMessage);

    //Close file
    fclose(filePtr);

    //Reopen file in read mode
    filePtr = fopen("happy.txt", "r");

    //Check for null pointer
    if(filePtr == NULL) {
        printf("Oops! File could not be opened.");
        exit(1);
    }

    printf("Reading contents of Happy File Handling Example:\n");
    printf("-----------------------------------------------\n");

    char lineBuffer[256];

    //Print contents of file
    while(fgets(lineBuffer, sizeof(lineBuffer), filePtr)) {
        printf("%s", lineBuffer);
    }

    //Close file
    fclose(filePtr);

    return 0;
}