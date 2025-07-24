//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to detect intrusion
void detect_intrusion(char* message) {
    // list of known intrusion keywords
    char* intrusion_keywords[] = {"hack", "attack", "virus", "malware", "trojan", "exploit", "phishing"};

    for (int i = 0; i < sizeof(intrusion_keywords)/sizeof(intrusion_keywords[0]); i++) {
        if (strstr(message, intrusion_keywords[i])) {
            printf("Intrusion alert: \"%s\" detected!\n", intrusion_keywords[i]);
            return;
        }
    }
    printf("No intrusion detected.\n");
}

int main(void) {
    // prompt user for input
    printf("Enter message: ");
    char input[100];
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    // detect intrusion
    detect_intrusion(input);

    return 0;
}