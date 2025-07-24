//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

pthread_mutex_t mutex;

void sanitize(char *input_str) {
    int len = strlen(input_str);
    int i, s = 0;
    for(i = 0; input_str[i] != '\0'; ++i) {
        if(input_str[i] == '<' || input_str[i] == '>') {
            continue;
        }
        input_str[s++] = input_str[i];
    }
    input_str[s] = '\0';
}

void *thread_func(void *arg) {
    char *input_str = (char *)arg;
    pthread_mutex_lock(&mutex);
    printf("Input before sanitation: %s\n", input_str);
    sanitize(input_str);
    printf("Input after sanitation: %s\n", input_str);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    char input_str1[100], input_str2[100];
    printf("Enter input string 1: ");
    fgets(input_str1, 100, stdin);
    printf("Enter input string 2: ");
    fgets(input_str2, 100, stdin);
    
    pthread_mutex_init(&mutex, NULL);
    
    pthread_create(&thread1, NULL, thread_func, (void *)input_str1);
    pthread_create(&thread2, NULL, thread_func, (void *)input_str2);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}