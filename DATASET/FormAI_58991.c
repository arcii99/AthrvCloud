//FormAI DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *reverse_string(void *str) {
    char *s = (char *)str;
    int len = strlen(s), i;
    char temp;

    for (i = 0; i < len / 2; i++) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    char string1[100], string2[100];

    // input first string
    printf("Enter first string: ");
    scanf("%s", string1);

    // input second string
    printf("Enter second string: ");
    scanf("%s", string2);

    // create threads to reverse the strings
    pthread_create(&thread1, NULL, reverse_string, (void *)string1);
    pthread_create(&thread2, NULL, reverse_string, (void *)string2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // print the reversed strings
    printf("Reversed string 1: %s\n", string1);
    printf("Reversed string 2: %s\n", string2);

    // concatenate the reversed strings
    strcat(string1, string2);

    // print the concatenated string
    printf("Concatenated string: %s\n", string1);

    return 0;
}