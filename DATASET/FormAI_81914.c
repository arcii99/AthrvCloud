//FormAI DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of the diary entry
struct Entry{
    char date[10];
    char time[10];
    char contents[1000];
};

int main(){
    printf("Welcome to the Secure Digital Diary!\n");
    printf("Please enter your password to proceed: ");
    char password[20];
    scanf("%s", password);
    if(strcmp(password, "mypassword") != 0){
        printf("Incorrect password. Exiting program.\n");
        exit(0);
    }
    printf("Password accepted.\n");

    // Create a file for diary entries
    FILE *fptr;
    fptr = fopen("diary.txt", "a");
    if(fptr == NULL){
        printf("Error opening file. Exiting program.\n");
        exit(0);
    }

    // Display menu
    printf("\nMenu:\n");
    printf("1. Add entry\n");
    printf("2. View all entries\n");
    printf("0. Exit\n");

    int option;
    do{
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option){
            case 1:{
                // Add entry
                struct Entry entry;

                // Get date
                printf("Enter date (DD/MM/YYYY): ");
                scanf("%s", entry.date);

                // Get time
                printf("Enter time (HH:MM): ");
                scanf("%s", entry.time);

                // Get contents
                printf("Enter contents (max 1000 characters):\n");
                getchar();
                fgets(entry.contents, 1000, stdin);

                // Validate contents length
                if(strlen(entry.contents) > 1000){
                    printf("Entry length exceeds limit. Exiting program.\n");
                    fclose(fptr);
                    exit(0);
                }

                // Write entry to file
                fprintf(fptr, "%s %s %s\n", entry.date, entry.time, entry.contents);
                printf("Entry added successfully.\n");
                break;
            }
            case 2:{
                // View all entries
                char c;
                printf("\nAll entries:\n");
                fseek(fptr, 0, SEEK_SET); // Set file pointer to start of file
                while((c = fgetc(fptr)) != EOF) printf("%c", c);
                printf("\n");
                break;
            }
            case 0:{
                // Exit
                fclose(fptr);
                printf("Exiting program.\n");
                exit(0);
            }
            default:{
                printf("Invalid option. Please try again.\n");
                break;
            }
        }

    } while(option != 0);

    return 0;
}