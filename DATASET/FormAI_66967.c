//FormAI DATASET v1.0 Category: Ebook reader ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000 // Maximum size of eBook

int main()
{
    char eBook[MAX_SIZE]; 
    FILE *fp; // File pointer
    int ch, i=0;

    printf("Enter the name of the eBook file: ");
    scanf("%s", eBook);

    fp = fopen(eBook, "r"); // Open eBook in read mode

    if (fp == NULL) // Check if the file exists or not
    {
        printf("Error in opening the file!");
        exit(1);
    }

    printf("\n----------EBOOK DETAILS----------\n\n");

    while ((ch = getc(fp)) != EOF) // Reading the eBook character by character
    {
        printf("%c", ch); // Displaying the eBook
    }

    fclose(fp); 

    return 0;
}