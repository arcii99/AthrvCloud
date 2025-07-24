//FormAI DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100

void print_error(char* error_message)
{
    printf("ERROR: %s\n", error_message);
    exit(EXIT_FAILURE);
}

int main()
{
    char filename[MAX_FILENAME_LEN];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        char error_message[MAX_FILENAME_LEN + 20];
        strcpy(error_message, "Unable to open file ");
        strcat(error_message, filename);
        print_error(error_message);
    }

    float sum = 0;
    float num;
    int line_number = 1;
    while(fscanf(file, "%f", &num) != EOF)
    {
        if(num < 0)
        {
            printf("ERROR at line %d! Invalid number: %f\n", line_number, num);
            continue;
        }

        sum += num;
        line_number++;
    }

    printf("Sum of positive numbers in file %s: %f\n", filename, sum);
    fclose(file);
    return 0;
}