//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LENGTH 200 // maximum input length

const char *morse_code_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A to I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J to R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S to Z
};

void *convert_text_to_morse_code(void *arg) {
    char *text = (char *)arg; // cast void pointer to char pointer
    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        if (text[i] == ' ') { // check for space
            printf(" ");
        } else if (text[i] >= 'A' && text[i] <= 'Z') { // check for uppercase alphabet
            printf("%s ", morse_code_table[text[i] - 'A']);
        } else if (text[i] >= 'a' && text[i] <= 'z') { // check for lowercase alphabet
            printf("%s ", morse_code_table[text[i] - 'a']);
        }
    }

    printf("\n");

    pthread_exit(NULL);
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter text to convert to Morse code:\n");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character from input

    pthread_t tid[2];

    int err1 = pthread_create(&(tid[0]), NULL, &convert_text_to_morse_code, (void *)input);

    if(err1 != 0) {
        printf("Thread creation error\n");
        exit(EXIT_FAILURE);
    }

    int err2 = pthread_create(&(tid[1]), NULL, &convert_text_to_morse_code, (void *)input);

    if(err2 != 0) {
        printf("Thread creation error\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(tid[0], (void **)NULL);
    pthread_join(tid[1], (void **)NULL);

    return 0;
}