//FormAI DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

int main() {
    char message[MAX_SIZE];
    int i, count = 0;

    printf("Enter a message: ");
    fgets(message, MAX_SIZE, stdin);

    for(i = 0; i < strlen(message); i++) {
        if(message[i] == 'c' || message[i] == 'C') {
            count++;
            if(count == 3) {
                printf("SPAM DETECTED\n");
                break;
            }
        }
        else {
            count = 0;
        }
    }

    if(count < 3) {
        printf("Message is not spam.\n");
    }

    return 0;
}