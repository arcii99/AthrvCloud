//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 100
#define MAX_STR_LEN 50

struct LogData {
    char str[MAX_STR_LEN];
    int count;
};

struct LogData log_data[MAX_LOG_SIZE];
int log_count = 0;

/*
 * This is the function to detect intrusions in the system.
 * It will check if any of the input strings contains known malicious keywords
 * and update the log_data with the frequency of occurence.
 * Returns 1 if a match is found, 0 otherwise.
 */
int detect_intrusion(char* str) {
    char* malicious_keywords[] = {"hack", "password", "root", "spyware", "virus", "malware"};
    int num_keywords = sizeof(malicious_keywords) / sizeof(char*);
    
    int i, j, len, match;
    len = strlen(str);
    match = 0;
    
    for(i = 0; i < num_keywords; i++) {
        if(strstr(str, malicious_keywords[i]) != NULL) {
            match = 1;
            break;
        }
    }
    
    if(match == 0) {
        return 0;
    }
    
    // Update log data
    for(i = 0; i < log_count; i++) {
        if(strcmp(log_data[i].str, str) == 0) {
            log_data[i].count++;
            return 1;
        }
    }
    
    if(log_count < MAX_LOG_SIZE) {
        strcpy(log_data[log_count].str, str);
        log_data[log_count].count = 1;
        log_count++;
        return 1;
    }
    
    return 1;
}

int main() {
    char input_str[MAX_STR_LEN];
    int i;
    
    printf("Enter a string: ");
    fgets(input_str, MAX_STR_LEN, stdin);
    
    int result = detect_intrusion(input_str);
    if(result == 1) {
        printf("Match found!\n");
    } else {
        printf("No match found.\n");
    }
    
    printf("Log data:\n");
    for(i = 0; i < log_count; i++) {
        printf(" %s: %d\n", log_data[i].str, log_data[i].count);
    }
    
    return 0;
}