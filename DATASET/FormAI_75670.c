//FormAI DATASET v1.0 Category: Data recovery tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to our C Data Recovery Tool! We are grateful you have chosen to use our program.\n");

    char data[100];
    FILE *fp;
    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("We are sorry, but we encountered an error opening the data file.\n");
        printf("Please double check the file name and that it is in the correct directory.\n");
        return 1;
    }

    // Read in data from file
    fgets(data, 100, fp);

    // Recover the data
    char recoveredData[100];
    int i, j;
    j = 0;

    for (i = strlen(data) - 2; i >= 0; i--)
    {
        if (data[i] != ' ')
        {
            recoveredData[j] = data[i];
            j++;
        }
    }

    printf("Your recovered data is: %s\n", recoveredData);

    printf("Thank you for using our C Data Recovery Tool! We are grateful for your patronage.\n");
    return 0;
}