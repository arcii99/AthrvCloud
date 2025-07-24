//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include <stdio.h>

int main() {
    char message[100];
    int checksum = 0;

    printf("Greetings Human! I am the Checksum Calculator 3000!\n");
    printf("Please enter a message for me to calculate the sum of each byte: ");
    fgets(message, 100, stdin);
    
    for(int i = 0; message[i] != '\0'; i++) {
        checksum += message[i];
    }

    printf("The checksum for your message is: %d\n", checksum);
    printf("Have a great day!\n");

    return 0;
}