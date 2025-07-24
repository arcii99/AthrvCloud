//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void detect_intrusion(char* message) {
    char* blacklisted_words[] = {"hack", "exploit", "password", "backdoor", "virus"};

    int num_blacklisted = sizeof(blacklisted_words)/sizeof(*blacklisted_words);

    // Check if any of the blacklisted words is present in the message
    for(int i=0; i<num_blacklisted; i++) {
        if(strstr(message, blacklisted_words[i])) {
            printf("Intrusion detected: message contains the word '%s'\n", blacklisted_words[i]);
            exit(1); // Exit the program due to intrusion
        }
    }
}

int main() {
    char message[100];

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    printf("Checking for intrusion...\n");
    detect_intrusion(message);

    printf("No intrusion detected. Message sent successfully!\n");

    return 0;
}