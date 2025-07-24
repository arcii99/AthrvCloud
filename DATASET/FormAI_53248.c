//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

int main() {
    char input[MAX_LENGTH];
    int intrusion_detected = 0;
    
    while(1) {
        printf("Enter command: ");
        fgets(input, MAX_LENGTH, stdin);  // read user input
        
        if(strncmp(input, "rm -rf", 6) == 0) {  // check for dangerous command
            printf("DANGEROUS COMMAND DETECTED: %s", input);
            intrusion_detected = 1;
        }
        
        if(intrusion_detected) {  // take action if intrusion detected
            printf("INTRUSION DETECTED! Terminating program...\n");
            exit(0);
        }
    }
    
    return 0;
}