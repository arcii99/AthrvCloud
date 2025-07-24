//FormAI DATASET v1.0 Category: modern Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This encryption program uses a modified substitution cipher combined with a transposition cipher for added complexity

int main()
{
    char msg[100];
    printf("Enter the message to encrypt: ");
    fgets(msg, 100, stdin); 

    // removing newline character
    if ((strlen(msg) > 0) && (msg[strlen(msg) - 1] == '\n'))
        msg[strlen(msg) - 1] = '\0';

    char key[26];
    printf("Enter the encryption key (26 letters in any order): ");
    fgets(key, 26, stdin); 

    // removing newline character
    if ((strlen(key) > 0) && (key[strlen(key) - 1] == '\n'))
        key[strlen(key) - 1] = '\0';

    int keyMap[26];
    int i, j, tmp;

    // creating a map for the key
    for (i = 0; i < 26; i++) {
        keyMap[i] = i;
    }

    // shuffling the map based on the key
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (key[i] == ('A' + j)) {
                tmp = keyMap[i];
                keyMap[i] = keyMap[j];
                keyMap[j] = tmp;
                break;
            }
        }
    }

    // applying the substitution cipher
    for (i = 0; i < strlen(msg); i++) {
        if (msg[i] != ' ') {
            msg[i] = 'A' + keyMap[msg[i] - 'A'];
        }
    }

    int rows = strlen(msg) / 5 + ((strlen(msg) % 5 == 0) ? 0 : 1);
    char matrix[rows][5];

    // filling the matrix with the encrypted message
    int k = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 5; j++) {
            if (k < strlen(msg)) {
                matrix[i][j] = msg[k++];
            } else {
                matrix[i][j] = 'X';
            }
        }
    }

    // applying the transposition cipher
    char transposedMatrix[rows][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < rows; j++) {
            transposedMatrix[j][i] = matrix[j][i];
        }
    }

    char encryptedMsg[strlen(msg) + 1];

    // reading the encrypted message from the transposed matrix
    k = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < rows; j++) {
            if (transposedMatrix[j][i] != 'X') {
                encryptedMsg[k++] = transposedMatrix[j][i];
            }
        }
    }

    encryptedMsg[k] = '\0';

    printf("The encrypted message is: %s\n", encryptedMsg);

    return 0;
}