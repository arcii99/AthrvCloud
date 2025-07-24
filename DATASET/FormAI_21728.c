//FormAI DATASET v1.0 Category: Digital Diary ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ENTRIES 100

int main(){

    struct DiaryEntry{
        char date[20];
        char title[50];
        char content[500];
    };

    struct DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to your Digital Diary!\n");
    printf("Enter 'quit' at any time to exit the program.\n");
    printf("Press any key to continue.\n");
    getchar();

    while(1){
        printf("\nDate (MM/DD/YYYY): ");
        fgets(entries[num_entries].date, 20, stdin);
        strtok(entries[num_entries].date, "\n");

        if(strcmp(entries[num_entries].date, "quit") == 0){
            break;
        }

        printf("Title: ");
        fgets(entries[num_entries].title, 50, stdin);
        strtok(entries[num_entries].title, "\n");

        printf("Content: ");
        fgets(entries[num_entries].content, 500, stdin);
        strtok(entries[num_entries].content, "\n");

        printf("\nEntry added successfully!\n");

        num_entries++;
        if(num_entries >= MAX_ENTRIES){
            printf("Maximum number of entries reached.\n");
            break;
        }
    }

    printf("\n\n");
    printf("Your Diary Entries:\n");
    for(int i = 0; i<num_entries; i++){
        printf("Date: %s\n", entries[i].date);
        printf("Title: %s\n", entries[i].title);
        printf("Content: %s\n", entries[i].content);
        printf("--------------------------------------\n");
    }

    printf("\nThank you for using our Digital Diary program!");

    return 0;
}