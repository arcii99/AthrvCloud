//FormAI DATASET v1.0 Category: Digital Diary ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(void){
    time_t t;
    struct tm *tm_info;
    char curr_time[26];

    time(&t);
    tm_info = localtime(&t);
    strftime(curr_time, 26, "%Y:%m:%d %H:%M:%S\n", tm_info);

    char filename[50];
    strcpy(filename, "diary_");
    strcat(filename, curr_time);
    strcat(filename, ".txt");

    FILE *fptr;
    fptr = fopen(filename, "w");
    if(fptr == NULL){
        printf("Error: Unable to create file!");
        exit(1);
    }

    printf("Welcome to your digital diary! Please enter your thoughts for today:\n");

    char input[500];
    fgets(input, 500, stdin);

    fprintf(fptr, "Date: %s\n", curr_time);
    fprintf(fptr, "Entry:\n%s", input);

    printf("Your entry has been saved in the file %s.\nGoodbye!\n", filename);

    fclose(fptr);

    return 0;
}