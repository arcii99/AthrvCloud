//FormAI DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputFile, *outputFile;
    char c;

    //Open the input file to read
    inputFile = fopen("input.html", "r");

    //Error handling for file open failure
    if (inputFile == NULL)
    {
        printf("Error opening the input file!\n");
        exit(1);
    }

    //Create and open the output file to write
    outputFile = fopen("output.html", "w");

    while ((c = fgetc(inputFile)) != EOF)
    {
        if (c == '<')
        {
            fputc(c, outputFile);
            fputc('\n', outputFile);
        }
        else if (c == '>')
        {
            fputc('\n', outputFile);
            fputc(c, outputFile);
        }
        else if (c == '/')
        {
            fputc('\n', outputFile);
            fputc(c, outputFile);
        }
        else
        {
            fputc(c, outputFile);
        }
    }

    //Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}