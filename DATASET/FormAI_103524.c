//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to my happy example program for file handling in C!\n");

    // Creating a file and writing to it
    FILE *file = fopen("output.txt", "w");
    if (file == NULL)
    {
        printf("Error creating file!\n");
        return 0;
    }
    fprintf(file, "Hello world!\n");
    fprintf(file, "I am so happy to be programming in C!\n");
    fclose(file);
    printf("File created and data successfully written to it!\n");

    // Reading from a file
    file = fopen("output.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }
    printf("Now let's read what we wrote earlier:\n");
    char line[50];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);

    // Appending to a file
    file = fopen("output.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }
    fprintf(file, "I love learning new things in programming!\n");
    fclose(file);
    printf("Data successfully appended to file!\n");

    // Reading from the file again to see our appended data
    file = fopen("output.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }
    printf("Now let's read what we wrote after appending:\n");
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);

    printf("Hope you enjoyed our happy example program for file handling in C. Bye-bye!\n");

    return 0;
}