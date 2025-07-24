//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_LOGS 1000

int main()
{
    char logs[MAX_LOGS][100]; // store logs in memory
    int num_logs = 0; // start with no logs
    int num_failures = 0; // count number of detection failures
    char* attack_keywords[4] = {"attack", "intrusion", "hack", "malware"}; // list of possible attack keywords
    
    while (1) // infinitely loop to prompt for input and check for attacks
    {
        char input[100]; // assume inputs are no longer than 100 characters
        
        printf("Please enter a log message: ");
        fgets(input, 100, stdin); // get user input
        
        if (strstr(input, "quit") != NULL) // check if user wants to exit the program
        {
            printf("Exiting the program...\n");
            break;
        }
        
        strncpy(logs[num_logs], input, 100); // copy input to log array
        
        // check if input contains any attack keywords
        for (int i = 0; i < 4; i++)
        {
            if (strstr(input, attack_keywords[i]) != NULL)
            {
                num_failures++;
                printf("Warning: Detected possible attack!\n");
                break; // no need to check for more attack keywords
            }
        }
        
        num_logs++; // increment number of logs
        
        if (num_logs == MAX_LOGS) // check if maximum number of logs is reached
        {
            for (int i = 0; i < MAX_LOGS; i++)
            {
                printf("%s", logs[i]); // print all logs
            }
            
            printf("Maximum number of logs reached. Clearing logs...\n");
            num_logs = 0; // reset number of logs to 0
        }
    }
    
    printf("Total number of detection failures: %d\n", num_failures);
    
    return 0;
}