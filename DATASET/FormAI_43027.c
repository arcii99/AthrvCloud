//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to the most exciting file handling program ever!\n");
    printf("We will create a brand new file and write some epic contents in it.\n");

    FILE *fp;

    fp = fopen("excitement.txt", "w"); //creating a new file named excitement.txt in write mode

    if(fp == NULL) //checking if file was created successfully
    {
        printf("Oh no! Something went wrong while creating the file. Please try again later.");
        exit(0); //exit the program
    }

    printf("\n File created successfully!");

    printf("\nNow, let's add some thrilling content to the file.");

    char excitement[] = "This is the most exciting file handling program ever! ";

    int i;

    for(i = 0; i < 10; i++)
    {
        fputs(excitement, fp); //writing the content to the file
    }

    printf("\nContent added successfully!");

    fclose(fp); //closing the file

    printf("\nBe prepared to witness the power of C file handling at work!");

    fp = fopen("excitement.txt", "r"); //opening the file in read mode

    if(fp == NULL) //checking if file was opened successfully
    {
        printf("Oops! Something went wrong while opening the file. Please try again later.");
        exit(0); //exit the program
    }

    printf("\nContents of the file: \n");

    char ch;

    while((ch = fgetc(fp)) != EOF) //printing the contents of the file
    {
        printf("%c", ch);
    }

    fclose(fp); //closing the file

    printf("\n\nExcited beyond belief? That's the power of C file handling!");

    return 0;
}