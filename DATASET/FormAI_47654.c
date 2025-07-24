//FormAI DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1024

// Function to recover data from the text file
void recoverData(char* fileName)
{
    FILE* fp;
    char buffer[MAX_SIZE], currentChar;
    int currentLine = 0, currentIndex = 0, recoveredData = 0;

    // Open the file in read mode
    fp = fopen(fileName, "r");

    if(fp != NULL)
    {
        // Loop through each character in the file
        while((currentChar = fgetc(fp)) != EOF)
        {
            if(currentChar == '\n')
            {
                currentLine++;    // Advance to the next line
                currentIndex = 0; // Reset the index to 0
            }
            else
            {
                buffer[currentIndex++] = currentChar; // Add the character to the buffer
            }

            if(currentIndex == MAX_SIZE)
            {
                printf("Error: line %d is too long to recover\n", currentLine);
                fclose(fp);
                return;
            }

            if(currentIndex >= 4 && strcmp(buffer + currentIndex - 4, "###\n") == 0)
            {
                // Remove the delimiters from the buffer and print the recovered data
                buffer[currentIndex - 4] = '\0';
                printf("%s", buffer);
                currentIndex = 0;
                recoveredData++;
            }
        }

        fclose(fp);

        if(recoveredData == 0)
        {
            printf("Error: no data found in file\n");
        }
        else
        {
            printf("Successfully recovered data from %d lines!\n", recoveredData);
        }
    }
    else
    {
        printf("Error: could not open file for reading\n");
    }
}

int main()
{
    char fileName[MAX_SIZE];

    printf("Enter the name of the file to recover data from: ");
    fgets(fileName, MAX_SIZE, stdin);

    // Remove the newline character from the end of the string
    fileName[strcspn(fileName, "\n")] = '\0';

    recoverData(fileName);

    return 0;
}