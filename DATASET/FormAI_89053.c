//FormAI DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *fp;
    char c;
    char message[50] = "The quick brown fox jumps over the lazy dog.";

    // Encrypt message
    for(int i = 0; i < strlen(message); i++) {
        message[i] = message[i] + 5;
    }

    // Write encrypted message to file
    fp = fopen("secret_message.txt", "w");
    fputs(message, fp);
    fclose(fp);

    // Read encrypted message from file
    fp = fopen("data.txt", "r");
    while((c = getc(fp)) != EOF) {
        printf("%c", (char)((int)c - 5));
    }
    fclose(fp);

    return 0;
}