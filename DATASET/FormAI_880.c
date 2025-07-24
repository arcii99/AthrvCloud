//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: energetic
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    char buffer[BUFFER_SIZE];
    char keywords[] = {'hack', 'crack', 'exploit', 'virus', 'trojan', 'worm', 'backdoor', 'payload', 'rootkit'};
    int count = 0;
    
    printf("Enter a sentence to check for intrusion: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    
    char *word = strtok(buffer, " ");
    
    while (word != NULL) {
        for (int i = 0; i < sizeof(keywords)/sizeof(char); i++) {
            if (strstr(word, keywords[i])) {
                count++;
                printf("Intrusion detected: %s\n", keywords[i]);
            }
        }
        word = strtok(NULL, " ");
    }
    
    if (count == 0) {
        printf("No intrusion detected.\n");
    }
    
    return 0;
}