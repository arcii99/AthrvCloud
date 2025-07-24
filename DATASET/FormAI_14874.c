//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[50], name[50], address[100], temp[100];
    int age, count = 0, i;

    printf("Welcome to my contact list program!\n");
    printf("Let's create your first contact\n\n");

    printf("Enter your full name: ");
    fgets(name, 50, stdin);

    printf("Enter your age: ");
    scanf("%d", &age);
    getchar();

    printf("Enter your address: ");
    fgets(address, 100, stdin);

    sprintf(temp, "%s%d.txt", name, age);
    for (i = 0; temp[i] != '\n'; i++)
    {
        filename[count] = temp[i];
        count++;
    }
    filename[count - 1] = '\0';

    fp = fopen(filename, "w+");
    if(fp == NULL) {
        printf("Error in creating a file");
        exit(0);
    }

    fprintf(fp, "Name: %s", name);
    fprintf(fp, "Age: %d\n", age);
    fprintf(fp, "Address: %s", address);

    printf("\nSuccess! Contact is saved to file %s\n", filename);

    fclose(fp);
    return 0;
}