//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char name[50];
    int age;
}Person;

int main()
{
    // Creating a file pointer and opening the file in read and write mode
    FILE *fp;
    fp = fopen("person.dat", "w+b");

    if(fp == NULL)
    {
        printf("Failed to open the file");
        exit(1);
    }

    int n = 3; // Number of persons to be written

    // Write data to the file
    for(int i=0; i<n; i++)
    {
        Person p;
        printf("Enter name and age of person %d: ", i+1);
        scanf("%s %d", p.name, &p.age);
        fwrite(&p, sizeof(Person), 1, fp);
    }

    rewind(fp); // Move the file pointer to the beginning of the file

    // Read data from the file and print it on the screen
    printf("\nDetails of all the persons:\n");
    Person p;
    while(fread(&p, sizeof(Person), 1, fp))
    {
        printf("Name: %s, Age: %d\n", p.name, p.age);
    }

    fclose(fp); // Close the file

    return 0;
}