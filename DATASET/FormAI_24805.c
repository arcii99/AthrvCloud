//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("Welcome to my file handling program!\n");
    printf("This program will create a file and store your favorite joke in it!\n");
    printf("Please enter the name of the file you want to create: ");

    char filename[50];
    fgets(filename, 50, stdin);

    //Removing the trailing newline character
    filename[strcspn(filename, "\n")] = 0;

    FILE *fptr;
    fptr = fopen(filename, "w+");

    if(fptr == NULL){
        printf("Oops! Something went wrong with file creation :( \n");
        return 0;
    }

    printf("Please enter your favorite joke. Make sure it's funny! \n");

    char joke[100];

    fgets(joke, 100, stdin);
    
    printf("Storing your joke in the file... \n");

    fprintf(fptr, "%s", joke);

    fclose(fptr);

    printf("\nNow let's retrieve your joke! \n");

    fptr = fopen(filename, "r");

    if(fptr == NULL){
        printf("Oops! Couldn't retrieve your joke :( \n");
        return 0;
    }

    char retrieved_joke[100];

    fgets(retrieved_joke, 100, fptr);

    //Printing the retrieved joke
    printf("Your favorite joke is: %s\n\n", retrieved_joke);

    printf("Thanks for using my file handling program! Stay funny :)\n");

    fclose(fptr);

    return 0;
}