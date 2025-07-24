//FormAI DATASET v1.0 Category: Log analysis ; Style: happy
#include<stdio.h>

int main(){
    printf("Hooray! Let's start analyzing some logs!\n");
    
    // Opening the file for reading
    FILE* fp = fopen("log.txt", "r");

    // Checking if file exists or not
    if(fp == NULL){
        printf("Oops, looks like the log file doesn't exist.\n");
        return 0;
    }

    printf("Yay, we found the log file!\n");

    // Initializing counters
    int warnings = 0, errors = 0, infos = 0;
    char line[100];

    // Reading each line
    while(fgets(line, 100, fp)){

        // Searching for keywords
        if(strstr(line, "WARNING")){
            warnings++;
        }
        else if(strstr(line, "ERROR")){
            errors++;
        }
        else if(strstr(line, "INFO")){
            infos++;
        }
    }

    // Closing the file
    fclose(fp);
    
    // Displaying the results
    printf("Total Warnings: %d\n", warnings);
    printf("Total Errors: %d\n", errors);
    printf("Total Info Messages: %d\n", infos);

    printf("Yippee! We have successfully analyzed the log file.\n");

    return 0;
}