//FormAI DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>

/* Our kingdom is facing a great danger from our neighboring realm. We need to send important messages to our allies 
to plan our defense strategies, but we don't want to risk them falling into the enemy's hands. Thus, we must use a code 
that only we can decipher, an encryption technique that can only be understood by the most skilled of our kingdom's 
knights, using techniques they learned in the ancient times of King Arthur. */

// We begin by declaring our encryption function, which takes in a plaintext message and a key
void encrypt(char message[], int key) {
    int i = 0;

    // Here, we encrypt the message using a simple substitution algorithm
    while (message[i] != '\0') {
        message[i] = message[i] + key;
        i++;
    }

    printf("Your encrypted message is: %s\n", message);
}

int main() {
    char message[100];
    int key;

    printf("Welcome, brave knight. What message would you like to send to our allies?\n");
    fgets(message, sizeof(message), stdin);
    printf("And what shall be your secret key, my lord?\n");
    scanf("%d", &key);

    // We pass the message and key as arguments to our encryption function
    encrypt(message, key);

    printf("May the heavens protect our message and deliver it safely to our allies.\n");
    return 0;
}