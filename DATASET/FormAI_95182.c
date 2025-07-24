//FormAI DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main() {
    char message[100]; // Input message to be encrypted
    int key, i; // Key for encryption and loop counter
    srand(time(NULL)); // Seed for random key generation
    printf("Hark! Friend, what message dost thou desire to encrypt? "); // Medieval style input prompt
    fgets(message, 100, stdin); // Get input message from user
    printf("Very well. And what shall be thy key for encryption? (A number betwixt 1 and 100) ");
    scanf("%d", &key); // Get key input from user
    getchar(); // Remove extra newline from input buffer
    
    // Ensure key is within valid range
    while(key <= 0 || key > 100) {
        printf("By my lady, thy key must be betwixt 1 and 100. Choose again: ");
        scanf("%d", &key);
        getchar();
    }
    
    printf("Verily! Thy encrypted message is: ");
    for(i = 0; i < strlen(message); i++) {
        if(message[i] == '\n') { // Ignore newline character from input
            continue;
        }
        int random = rand() % 100 + 1; // Generate random number betwixt 1 and 100 for each letter
        int encrypted = (int)message[i] + key + random; // Encryption formula
        printf("%c", (char)encrypted); // Print encrypted character
    }
    printf("\n");
    return 0;
}