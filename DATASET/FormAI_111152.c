//FormAI DATASET v1.0 Category: HTML beautifier ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void beautifyHTML(char *filename);

int main()
{
    char *filename = "index.html"; // file name to be beautified
    beautifyHTML(filename); // call the beautify function
    printf("HTML content has been beautified successfully!");
    return 0;
}

// function to beautify the given HTML file
void beautifyHTML(char *filename)
{
    FILE *file;
    file = fopen(filename, "r"); // open the file in read mode
    if (file == NULL) // check if file is empty or not
    {
        printf("Error opening the file! Please check if the file exists or not.\n");
        exit(0);
    }
    char c;
    int indent = 0;
    while ((c = getc(file)) != EOF)
    {
        if (c == '<') // check if starting tag is encountered
        {
            putchar(c);
            c = getc(file);
            if (c == '/') // check if closing tag is encountered
            {
                indent--;
                printf("\n%*c", indent, ' ');
            }
            else if (c != '!' && c != '?' && c != '\n') // ignore comments, directives and empty lines
            {
                indent++;
                printf("\n%*c", indent, ' ');
            }
            putchar(c);
        }
        else if (c == '>') // check if ending tag is encountered
        {
            putchar(c);
            printf("\n%*c", indent, ' ');
        }
        else // print other characters as it is
        {
            putchar(c);
        }
    }
    fclose(file); // close the file
}