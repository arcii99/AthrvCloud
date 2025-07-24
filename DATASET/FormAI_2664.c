//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char name[20];
    int age;

    // Create a file named "data.txt" and write user input to it
    fptr = fopen("data.txt", "w");
    if(fptr == NULL)
    {
        printf("Error creating file!");
        exit(1);
    }

    printf("Enter your name: ");
    scanf("%s", name);
    fprintf(fptr, "Name: %s\n", name);

    printf("Enter your age: ");
    scanf("%d", &age);
    fprintf(fptr, "Age: %d\n", age);

    fclose(fptr);

    // Read data from the file "data.txt" and print it to the console
    fptr = fopen("data.txt", "r");
    if(fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    printf("\nData read from file:\n");
    fscanf(fptr, "%s %d", name, &age);
    printf("Name: %s\nAge: %d\n", name, age);

    fclose(fptr);

    return 0;
}