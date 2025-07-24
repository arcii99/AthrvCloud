//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int data[10];           // Array to hold the log file data
    int i = 0, count = 0;   // Counter variables

    FILE *filePointer;

    filePointer = fopen("log.txt", "r"); // Change log.txt to your log file name

    if (filePointer == NULL)  // Check if the file is opened or not
        printf("File unable to open.\n");
    else
    {
        printf("Log file opened successfully.\n");

        while (!feof(filePointer))  // Loop through the file till we reach the end of file
        {
            fscanf(filePointer, "%d", &data[i]);  // Read the integer values from the file and store them in an array
            i++;
        }

        fclose(filePointer);  // Close the file after reading the data

        printf("Log data analysis: \n");

        for (i = 0; i < 10; i++)  // Loop through the array to analyze the data
        {
            if (data[i] == 0)  // If the value is 0, it means no error occurred
                count++;
            else              // If the value is not 0, it means there was some error occurred
                printf("Error occurred at line %d: %d\n", i + 1, data[i]);
        }

        if (count == 10) // If there are no errors in the log file
            printf("No errors found in the log file.\n");

        printf("Log data analysis completed.\n");
    }

    return 0;
}