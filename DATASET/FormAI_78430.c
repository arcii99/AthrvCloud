//FormAI DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINES 1000

int main(){
    char diary[MAX_LINES][100], input[100];
    int i, length = 0;
    FILE *fp;

    /* if the file does not exist, create one */
    fp = fopen("digital_diary.txt", "a+");
    if(fp == NULL){
        printf("Error creating file");
        exit(1);
    }

    /* read the diary entries from the file */
    while(fgets(diary[length], 100, fp) != NULL){
        length++;
    }

    printf("Welcome to your digital diary!\n");

    while(1){
        printf("What would you like to add to your diary today? Type 'quit' to exit.\n");
        fgets(input, 100, stdin);

        /* remove the newline character at the end of the input */
        input[strcspn(input, "\n")] = 0;

        /* exit loop if user types 'quit' */
        if(strcmp(input, "quit") == 0){
            printf("Goodbye!\n");
            break;
        }

        /* add the entry to the diary */
        strcat(diary[length], input);
        strcat(diary[length], "\n");
        length++;

        /* write the diary to the file */
        rewind(fp);
        for(i = 0; i < length; i++){
            fputs(diary[i], fp);
        }
        fflush(fp);

        printf("Entry saved.\n");
    }

    fclose(fp);

    return 0;
}