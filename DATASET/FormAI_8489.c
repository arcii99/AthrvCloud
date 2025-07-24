//FormAI DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to Invasive File Handling!\n");
    char choice;
    printf("Would you like to delete all files in the current directory? (y/n): ");
    scanf("%c", &choice);
    getchar(); // Used to clear the remaining newline character from the input buffer
    if (choice == 'y') {
        system("rm -rf *");
        printf("All files in the current directory have been deleted.\n");
    } else {
        printf("Good choice. We won't delete any files.\n");
    }
    printf("Would you like to create a new file? (y/n): ");
    scanf("%c", &choice);
    getchar(); // Used to clear the remaining newline character from the input buffer
    if (choice == 'y') {
        char filename[100];
        printf("Please enter the filename: ");
        scanf("%s", filename);
        FILE *fptr;
        fptr = fopen(filename, "w");
        if (fptr == NULL) {
            printf("Error creating file.\n");
            exit(1);
        }
        printf("File created successfully.\n");
        printf("Please enter some text: ");
        char text[1000];
        scanf("%s", text);
        fprintf(fptr, "%s", text);
        printf("Text written to file successfully.\n");
        fclose(fptr);
    } else {
        printf("Alright, we won't create a new file.\n");
    }
    printf("Thank you for using Invasive File Handling. Have a nice day!\n");
    return 0;
}