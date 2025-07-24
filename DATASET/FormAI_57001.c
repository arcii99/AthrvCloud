//FormAI DATASET v1.0 Category: Data recovery tool ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to our C Data Recovery Tool!\n");

    // opening the file for recovery
    FILE *fp = fopen("lost_data.txt", "r");
    if(fp == NULL)
    {
        printf("Error: Cannot open file for read.");
        return 0;
    }

    // count the number of characters in the file
    int count = 0;
    char ch;
    while((ch = fgetc(fp)) != EOF)
        count++;

    // allocate memory for data recovery
    char *data = (char*) malloc(count * sizeof(char));

    // recover the lost data
    rewind(fp); // go back to the beginning of the file
    int i = 0;
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
            data[i] = ' '; // replace new line character with space
        else
            data[i] = ch;
        i++;
    }
    data[i] = '\0'; // terminate the string

    // close the file
    fclose(fp);

    // display the recovered data
    printf("\nRecovered Data:\n%s\n", data);

    // free the allocated memory
    free(data);

    return 0;
}