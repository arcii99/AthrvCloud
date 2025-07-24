//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    //getting system time 
    time_t current_time;
    time(&current_time);
    
    //creating file name with timestamp
    char file_name[25];
    strftime(file_name, sizeof(file_name), "digital_diary_%Y%m%d%H%M%S.txt", localtime(&current_time));
    
    //creating file with timestamp as name
    FILE *fp;
    fp = fopen(file_name, "w+");
    
    if(fp == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }
    
    printf("Welcome to your digital diary!\n\n");
    
    char user_input[200];
    printf("Start writing...\n(Type 'exit' to save and close your diary)\n");
    
    while(strcmp(user_input, "exit") != 0) {
        fgets(user_input, 200, stdin);
        fprintf(fp, "%s", user_input);
    }
    
    printf("\nYour diary has been saved!\n\nGoodbye!\n");
    
    fclose(fp);
    
    return 0;
}