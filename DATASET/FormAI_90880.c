//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Opening a file for writing
    FILE *fp = fopen("grateful.txt", "w");

    // Checking if the file was opened successfully
    if(fp == NULL){
        printf("Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Writing to the file
    fprintf(fp, "I am grateful for this opportunity to write code.\n");
    fprintf(fp, "I am grateful for the endless possibilities of programming.\n");
    fprintf(fp, "I am grateful for the joy that coding brings to my life.\n");
    fprintf(fp, "I am grateful for the skills that I have acquired through coding.\n");
    fprintf(fp, "I am grateful for the community of programmers who support and inspire me.\n");

    // Closing the file
    fclose(fp);

    // Opening the same file for reading
    fp = fopen("grateful.txt", "r");

    // Checking if the file was opened successfully
    if(fp == NULL){
        printf("Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Reading from the file and printing to the console
    printf("Reading from the grateful.txt file:\n");

    char buffer[255];
    while(fgets(buffer, 255, fp) != NULL){
        printf("%s", buffer);
    }

    // Closing the file
    fclose(fp);

    // End of program
    printf("\nCode execution complete.\n");

    return 0;
}