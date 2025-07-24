//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024 // Maximum buffer size for input

int main() {
    char buffer[MAX_BUFFER_SIZE], alert_message[MAX_BUFFER_SIZE];
    char* keywords[] = {"system", "passwd", "sudo"}; // keywords to detect

    while(1) { // infinite loop to check for intrusion
        printf("Enter your command: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        for(int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
            if(strstr(buffer, keywords[i])) { // check if keyword exists in command
                sprintf(alert_message, "Intrusion detected on keyword: %s", keywords[i]);
                printf("%s\n", alert_message);
                // code to send alert via email or other means can be added here
                break; // exit loop after first keyword is detected
            }
        }
    }

    return 0;
}