//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp; //file pointer
    char filename[20] = "example.txt"; //file name
    char ch, c[100]; //variables to store characters and string

    //writing to file
    fp = fopen(filename, "w+"); //opening file for writing
    if(fp == NULL) //checking if file opened successfully
    {
        printf("Unable to create file.\n");
        exit(0);
    }
    else
    {
        printf("Enter text to write to file: ");
        fgets(c, 100, stdin); //reading string from user
        fprintf(fp, "%s", c); //writing string to file
        printf("Content written to file successfully.\n");
        fclose(fp); //closing file pointer
    }

    //reading from file
    fp = fopen(filename, "r"); //opening file for reading
    if(fp == NULL) //checking if file opened successfully
    {
        printf("Unable to open file.\n");
        exit(0);
    }
    else
    {
        printf("Reading from file: ");
        while((ch = fgetc(fp)) != EOF) //reading character by character till end of file
            printf("%c", ch); //printing character
        printf("\n");
        fclose(fp); //closing file pointer
    }

    return 0;
}