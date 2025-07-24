//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

int str_len(char* str) {
    int len = 0;
    while (*str++ != '\0') {
        len++;
    }
    return len;
}

void reverse_string(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

void* async_reverse(void* arg) {
    char* str = (char*) arg;
    int length = str_len(str);
    reverse_string(str, length);
}

int main() {
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);
    pthread_t thread;
    pthread_create(&thread, NULL, async_reverse, str);
    pthread_join(thread, NULL);
    printf("Reversed string: %s\n", str);
    return 0;
}