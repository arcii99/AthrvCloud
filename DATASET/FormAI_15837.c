//FormAI DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp;
    FILE *file; // declare file pointer

    file = fopen("temp.txt", "r"); // open the file for reading

    if (file == NULL) // check if the file exists
    {
        printf("File does not exist.\n");
        exit(1);
    }

    fscanf(file, "%f", &temp); // read the temperature from the file

    printf("The current temperature is: %.2f degrees Celsius\n", temp);

    fclose(file); // close the file

    return 0;
}