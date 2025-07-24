//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

void cipher(char *key, char *message, char *output) {
    int key_len = strlen(key);
    int message_len = strlen(message);
    int i, j;

    for (i = 0, j = 0; i < message_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        output[i] = message[i] ^ key[j];
    }
    output[i] = '\0'; // terminating character
}

void shapeshift(char *input, char *output) {
    int input_len = strlen(input);
    int i;

    for (i = 0; i < input_len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = input[i] + ('A' - 'a');
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = input[i] + ('a' - 'A');
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0'; // terminating character
}

int main() {
    char key[BUFF_SIZE], message[BUFF_SIZE], output[BUFF_SIZE], shape[BUFF_SIZE];
    char *filename = "output.txt";
    FILE *file;

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // remove the newline character

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // remove the newline character

    cipher(key, message, output);
    shapeshift(output, shape);

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", output);
    printf("Shape Shifted message: %s\n", shape);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%s", shape);
    printf("Message saved to file: %s\n", filename);

    fclose(file);
    return 0;
}