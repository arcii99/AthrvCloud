//FormAI DATASET v1.0 Category: Digital Diary ; Style: systematic
#include<stdio.h> //header file for input/output operations

int main()
{
    int choice, date, month, year;
    char entry[1000];

    printf("\n\n=======================================================\n");
    printf("Welcome to your Digital Diary!\n");
    printf("=======================================================\n\n");

    printf("Enter today's date (DD MM YYYY): ");
    scanf("%d %d %d", &date, &month, &year);

    printf("\n\nPlease select the operation you want to perform:\n");
    printf("1. Add an Entry\n");
    printf("2. View previous Entries\n");
    printf("3. Exit\n\n");

    while(1) //infinite loop to keep program running until user exits
    {
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: //Add an Entry
                printf("\nEnter your entry (maximum 1000 characters):\n");
                getchar(); //to clear previous buffer
                fgets(entry, 1000, stdin);

                FILE *filePointer;
                char fileName[50];

                sprintf(fileName, "diary_%d-%d-%d.txt", date, month, year); //creating a file name with current date

                filePointer = fopen(fileName, "a"); //opening a file in append mode

                fprintf(filePointer, "\n\n%s", entry); //writing entry to file
                fclose(filePointer);

                printf("\nEntry successfully added to your Digital Diary!\n\n");

                break;

            case 2: //View previous Entries
                FILE *fp;
                char ch;

                sprintf(fileName, "diary_%d-%d-%d.txt", date, month, year); //creating file name with current date

                fp = fopen(fileName, "r"); //opening file in read mode

                if(fp == NULL)
                {
                    printf("\nNo Entries found for the selected date.\n\n");
                }
                else
                {
                    printf("\n\nPrevious Entries are:\n\n");

                    while((ch = fgetc(fp)) != EOF) //reading file character by character
                    {
                        printf("%c", ch);
                    }

                    fclose(fp);
                }

                break;

            case 3: //Exit
                printf("\n\nThank you for using your Digital Diary!\n");
                printf("=======================================================\n\n");
                return 0; //returning 0 to exit the program

            default: //Invalid Entry
                printf("\n\nInvalid choice. Please select a valid option.\n\n");
        }
    }

    return 0;
}