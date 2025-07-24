//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define ALERT_THRESHOLD 10

int main()
{
    char buffer[BUF_SIZE];
    int alert_count = 0;
    int buffer_size = 0;
    int buffer_index = 0;
    
    printf("Enter input:\n");
    while(1)
    {
        // read input
        char c = getchar();
        
        // exit loop if user enters EOF
        if(c == EOF)
            break;
        
        // add character to buffer
        buffer[buffer_index++] = c;
        buffer_size++;
        
        // check if buffer is full
        if(buffer_size == BUF_SIZE)
        {
            printf("Paranoid mode enabled: buffer full.\n");
            alert_count++;
            
            // reset buffer
            memset(buffer, 0, BUF_SIZE);
            buffer_size = 0;
            buffer_index = 0;
        }
        
        // check for suspicious characters
        if(c == '\\' || c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == '<' || c == '>' || c == '&' || c == '|' || c == '`' || c == '$' || c == '@' || c == '[' || c == ']')
        {
            printf("Paranoid mode enabled: suspicious character found.\n");
            alert_count++;
        }
        
        // check for suspicious strings
        if(strstr(buffer, "system(") != NULL)
        {
            printf("Paranoid mode enabled: system() function found. Potential intrusion attempt.\n");
            alert_count++;
            
            // reset buffer
            memset(buffer, 0, BUF_SIZE);
            buffer_size = 0;
            buffer_index = 0;
        }
        
        // check alert threshold
        if(alert_count >= ALERT_THRESHOLD)
        {
            printf("Paranoid mode enabled: alert threshold reached. Shutting down program.\n");
            exit(1);
        }
    }
    
    return 0;
}