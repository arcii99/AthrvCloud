//FormAI DATASET v1.0 Category: Digital Diary ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

    char diaryText[1000];
    char currentDate[20];
    char option;
    FILE *fp;

    printf("Welcome to your digital diary!\n");

    printf("Enter current date (dd/mm/yyyy): ");
    scanf("%s", currentDate);

    fp = fopen(currentDate, "w+");

    if(fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    printf("Enter what's on your mind: ");
    scanf("\n%[^\n]s", diaryText);

    fwrite(diaryText, strlen(diaryText), 1, fp);
    printf("Successfully wrote the diary entry!\n");

    printf("Do you want to read your previous entries? (Y/N): ");
    scanf("\n%c", &option);

    if(option == 'Y' || option == 'y') {

        fp = fopen(currentDate, "r");

        while(fgets(diaryText, sizeof(diaryText), fp) != NULL) {
            printf("%s\n", diaryText);
        }

        fclose(fp);
    }

    printf("Thank you for using our digital diary program. See you again soon!");
    return 0;
}