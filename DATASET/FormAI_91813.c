//FormAI DATASET v1.0 Category: Log analysis ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 10000
#define MAX_LENGTH 1000

int main(){
    char log_line[MAX_LENGTH];
    int count_sensitive_entries = 0, count_non_sensitive_entries = 0; 
    int index = 0, i, j;
    char* sensitive_keywords[] = {"password", "secret", "confidential", "credit card"};
    char* non_sensitive_keywords[] = {"information", "system", "server", "file"};
    int instances_sensitive[MAX_ENTRIES], instances_non_sensitive[MAX_ENTRIES];

    FILE *fp;
    fp = fopen("log.txt", "r"); //input log file name

    if(fp == NULL){
        printf("Error opening file");
        return 0;
    }

    while(fgets(log_line, MAX_LENGTH, fp) != NULL){ //Read log line by line
        index += 1;
        instances_sensitive[index] = 0;
        instances_non_sensitive[index] = 0;

        //Check for sensitive keywords
        for(i=0;i<sizeof(sensitive_keywords)/sizeof(sensitive_keywords[0]);i++){
            char *res;
            res = strstr(log_line, sensitive_keywords[i]);
            if(res != NULL){
                count_sensitive_entries += 1;
                instances_sensitive[index] += 1;
            }
        }

        //Check for non-sensitive keywords
        for(j=0;j<sizeof(non_sensitive_keywords)/sizeof(non_sensitive_keywords[0]);j++){
            char *res;
            res = strstr(log_line, non_sensitive_keywords[j]);
            if(res != NULL){
                count_non_sensitive_entries += 1;
                instances_non_sensitive[index] += 1;
            }
        }

        //Remove any sensitive data
        for(i=0;i<strlen(log_line);i++){
            for(j=0;j<sizeof(sensitive_keywords)/sizeof(sensitive_keywords[0]);j++){
                if(log_line[i] == sensitive_keywords[j][0]){
                    char* temp = malloc(sizeof(char) * strlen(log_line));
                    strcpy(temp, log_line);
                    char* replaced = malloc(sizeof(char) * strlen(log_line));
                    replaced = strstr(temp, sensitive_keywords[j]);
                    int k;
                    for(k=0;k<strlen(sensitive_keywords[j]);k++){
                        replaced[k] = 'x';
                    }
                    strcpy(log_line, temp);
                }
            }
        }

        printf("%s", log_line); //Print the log entry

        if(instances_sensitive[index] > 0){
            printf("\nALERT! Sensitive information detected in log entry #: %d", index);
        }

    }

    fclose(fp);

    //Output Analysis
    printf("\nTotal sensitive log entries: %d", count_sensitive_entries);
    printf("\nTotal non-sensitive log entries: %d", count_non_sensitive_entries);

    return 0;
}