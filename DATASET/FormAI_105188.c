//FormAI DATASET v1.0 Category: System boot optimizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

/**
 * Returns the number of spaces at the start of a string.
 */
int get_indentation(char line[])
{
    int count = 0;
    while (line[count] == ' ')
    {
        count++;
    }
    return count;
}

/**
 * Returns true if the line contains nothing but whitespace.
 */
bool is_blank(char line[])
{
    int count = 0;
    while (line[count] != '\0')
    {
        if (line[count] != ' ')
        {
            return false;
        }
        count++;
    }
    return true;
}

/**
 * Optimizes the boot process by removing unnecessary lines from the systemd
 * service unit file.
 */
void optimize_boot(char file_path[])
{
    FILE *file_ptr = fopen(file_path, "r+");
    if (file_ptr == NULL)
    {
        printf("Cannot open file %s\n", file_path);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int current_indentation = 0;
    bool is_description = false;

    while (fgets(line, MAX_LINE_LENGTH, file_ptr))
    {
        if (is_blank(line))
        {
            continue;
        }

        int indentation = get_indentation(line);

        if (indentation == 0 && !is_description)
        {
            // This is a new section, so reset the current indentation level.
            current_indentation = 0;
        }

        if (strstr(line, "Description=") != NULL)
        {
            is_description = true;
        }

        if (is_description)
        {
            // If we are in the Description section, let the entire line pass through.
            fwrite(line, sizeof(char), strlen(line), file_ptr);
        }
        else
        {
            // Only write the line if it is more indented than the previous one.
            if (indentation > current_indentation)
            {
                fwrite(line, sizeof(char), strlen(line), file_ptr);
            }
            current_indentation = indentation;
        }
    }

    fclose(file_ptr);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s PATH_TO_SERVICE_FILE\n", argv[0]);
        return 1;
    }

    optimize_boot(argv[1]);
    printf("Done!\n");

    return 0;
}