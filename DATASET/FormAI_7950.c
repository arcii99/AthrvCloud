//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

/* Function to detect intrusions */
void detect_intrusions(char* log_file) {
    FILE* fp;
    char line[MAX_LINE];
    char* token;
    int line_num = 0;
    
    /* Open the log file for reading */
    fp = fopen(log_file, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    /* Process each line of the log file */
    while (fgets(line, MAX_LINE, fp) != NULL) {
        line_num++;
        
        /* Check if the line contains the keyword "attack" */
        if (strstr(line, "attack") != NULL) {
            
            /* Split the line into tokens */
            token = strtok(line, " ");
            while (token != NULL) {
                
                /* Check if the token is an IP address */
                if (strstr(token, ".") != NULL) {
                    printf("Intrusion detected on line %d from IP address %s\n", line_num, token);
                    break;
                }
                
                token = strtok(NULL, " ");
            }
        }
    }
    
    /* Close the log file */
    fclose(fp);
}

int main() {
    char* log_file = "system.log";
    
    detect_intrusions(log_file);
    
    return 0;
}