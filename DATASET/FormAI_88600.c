//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void detect_intrusion(char *input) {
    // This function will detect any intrusion in the input and print the result to the console
    char *intrusion_keywords[] = {"sudo", "rm", "mv", "mkdir", "wget", "curl", "ssh", "su", "passwd"};
    // List of keywords that are commonly used in intrusion attempts
    
    int intrusion_detected = 0;
    for (int i = 0; i < sizeof(intrusion_keywords)/sizeof(intrusion_keywords[0]); i++) {
        if (strstr(input, intrusion_keywords[i]) != NULL) {
            intrusion_detected = 1;
            break;
        }
    }
    
    if (intrusion_detected) {
        printf("INTRUSION DETECTED: The following input contains potential intrusion attempt(s):\n%s\n", input);
    } else {
        printf("No intrusion detected.\n");
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    
    printf("Enter some input:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    detect_intrusion(input);
    
    return 0;
}