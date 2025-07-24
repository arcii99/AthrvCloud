//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    char message[100];
    int checksum = 0;
    
    printf("What is your message, my dear Watson? ");
    fgets(message, 100, stdin);
    
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == ' ') {
            continue;
        }
        else if (message[i] >= 'a' && message[i] <= 'z') {
            checksum += message[i] - 'a' + 1;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            checksum += message[i] - 'A' + 1;
        }
        else {
            checksum += (int) message[i];
        }
    }
    
    printf("The checksum for your message is %d, my dear Watson.\n", checksum);
    
    return 0;
}