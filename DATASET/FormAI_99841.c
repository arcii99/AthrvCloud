//FormAI DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file_name;
    char ch, prev_ch;
    int braces_count = 0, spaces_count = 0, tabs_count = 0;

    file_name = fopen("input.html", "r");
    if (file_name == NULL)
    {
        printf("Error opening the file!\n");
        exit(1);
    }

    while ((ch = fgetc(file_name)) != EOF)
    {
        if (ch == '{')
        {
            braces_count++;
        }
        else if (ch == '}')
        {
            braces_count--;
        }
        else if (ch == ' ')
        {
            spaces_count++;
        }
        else if (ch == '\t')
        {
            tabs_count++;
        }

        // Remove additional spaces and tabs
        if (prev_ch != ' ' && prev_ch != '\t')
        {
            printf("%c", ch);
        }

        prev_ch = ch;
    }

    fclose(file_name);

    // Indent the code based on braces
    printf("\n\n\n");
    int i;
    for (i = 0; i < braces_count; i++)
    {
        printf("    ");
    }

    // Print statistics
    printf("\n\n\nSTATISTICS:\n");
    printf("Number of braces: %d\n", braces_count);
    printf("Number of spaces: %d\n", spaces_count);
    printf("Number of tabs: %d\n", tabs_count);

    return 0;
}