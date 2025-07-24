//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char message[] = "Peace begins with a smile";
    char new_message[100];

    printf("Original Message: %s\n", message);

    // Reversing the message
    for(int i=0; i<strlen(message); i++) {
        new_message[i] = message[strlen(message)-1-i];
    }
    new_message[strlen(message)] = '\0';

    printf("Reversed Message: %s\n", new_message);

    // Converting all characters to lowercase
    for(int i=0; i<strlen(new_message); i++) {
        if(new_message[i]>='A' && new_message[i]<='Z') {
            new_message[i] = new_message[i] + 32;
        }
    }

    printf("Lowercase Message: %s\n", new_message);

    // Replacing spaces with underscores
    for(int i=0; i<strlen(new_message); i++) {
        if(new_message[i]==' ') {
            new_message[i] = '_';
        }
    }

    printf("Replaced Message: %s\n", new_message);

    // Removing vowels from the message
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int count = 0;
    for(int i=0; i<strlen(new_message); i++) {
        int flag = 0;
        for(int j=0; j<10; j++) {
            if(new_message[i] == vowels[j]) {
                flag = 1;
                count++;
                break;
            }
        }
        if(flag == 0) {
            new_message[i-count] = new_message[i];
        }
    }
    new_message[strlen(new_message)-count] = '\0';

    printf("Vowels Removed Message: %s\n", new_message);

    return 0;
}