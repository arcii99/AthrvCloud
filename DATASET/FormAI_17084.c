//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main() {
    char message[1000];

    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    int count = 0;

    for(int i = 0; message[i] != '\0'; i++) {
        if(message[i] == 'p' && message[i+1] == 'i' && message[i+2] == 'l'
           && message[i+3] == 'l' && message[i+4] == 's') {
            count++;
        }
    }

    if(count > 0) {
        printf("Possible spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}