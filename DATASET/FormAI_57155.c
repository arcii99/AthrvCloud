//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define MAX_SIZE 100

char string[MAX_SIZE];
int is_palindrome;

void *check_palindrome(void *arg) {
    int len = strlen(string);
    for (int i = 0; i < len/2; i++) {
        if (string[i] != string[len-i-1]) {
            is_palindrome = 0;
            return NULL;
        }
    }
    is_palindrome = 1;
    return NULL;
}

int main() {
    pthread_t thread;
    
    printf("Enter a string to check if it is a palindrome: ");
    scanf("%[^\n]", string);

    pthread_create(&thread, NULL, check_palindrome, NULL);
    pthread_join(thread, NULL);

    if (is_palindrome)
        printf("%s is a palindrome.\n", string);
    else
        printf("%s is not a palindrome.\n", string);
    
    return 0;
}