//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main() {
    char input[MAX_LEN];
    char* detection_keywords[] = {"hack", "attack", "intrude", "breach", "compromise", "exploit", "unauthorized", "malicious"};

    printf("Welcome to the Intrusion Detection System!\n");

    while(1) {
        printf("\nEnter input: ");
        fgets(input, MAX_LEN, stdin);

        for(int i = 0; i < sizeof(detection_keywords)/sizeof(detection_keywords[0]); i++) {
            if(strstr(input, detection_keywords[i])) {
                printf("\nINTRUSION DETECTED! Suspicious keyword found: %s\n", detection_keywords[i]);
            }
        }
    }

    return 0;
}