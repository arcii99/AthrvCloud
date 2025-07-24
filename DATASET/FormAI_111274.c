//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Morse code dictionary
char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Alphabet dictionary
char *alphabet = "abcdefghijklmnopqrstuvwxyz";

// Function that converts a single character to morse code
void *convert_to_morse(void *arg) {
    char *letter = (char *) arg;

    int index = strchr(alphabet, *letter) - alphabet;

    if(index >= 0) {
        printf("%s ", morse_codes[index]);
    } else {
        printf(" ");
    }

    pthread_exit(NULL);
}

int main() {
    char message[100];

    printf("Enter a message: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;

    pthread_t threads[strlen(message)];

    for(int i = 0; i < strlen(message); i++) {
        pthread_create(&threads[i], NULL, convert_to_morse, &message[i]);
    }

    for(int i = 0; i < strlen(message); i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n");

    return 0;
}