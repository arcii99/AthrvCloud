//FormAI DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>

int main() {
    char logMessage[50] = "";
    int numErrors = 0;
    
    printf("Welcome to the Log Analysis Program!\n");
    printf("Please input your log messages below:\n\n");
    
    while (1) {
        printf("> ");
        scanf("%[^\n]%*c", logMessage);
        
        if (strstr(logMessage, "ERROR") != NULL) {
            numErrors++;
            
            if (numErrors >= 3) {
                printf("\nOh no, it seems like the system has reached its limit for errors!\n");
                printf("Initiating emergency shutdown...\n");
                printf("...");
                printf("...");
                printf("...\n");
                printf("Shutdown successful!\n");
                
                break;
            }
        }
        
        printf("\nProcessing log message...\n");
        printf("Log message successfully processed!\n\n");
    }
    
    printf("\nThank you for using the Log Analysis Program!\n");
    printf("Total number of errors detected: %d\n", numErrors);
    
    return 0;
}