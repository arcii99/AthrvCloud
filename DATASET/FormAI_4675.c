//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_SIZE 100
#define MAX_ITERATIONS 1000000

//Function to asynchronously convert a string to uppercase
void to_uppercase_async(char* str) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

//Function to asynchronously convert a string to lowercase
void to_lowercase_async(char* str) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

//Function to asynchronously append two strings
char* str_append_async(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = (char*)malloc((len1+len2+1)*sizeof(char));
    for(int i=0; i<len1; i++) {
        result[i] = str1[i];
    }
    for(int i=0; i<len2; i++) {
        result[len1+i] = str2[i];
    }
    result[len1+len2] = '\0';
    return result;
}

//Main function to test the asynchronous string manipulation functions
int main() {
    char str1[MAX_STRING_SIZE];
    char str2[MAX_STRING_SIZE];
    char* result;
    srand(time(NULL));
    for(int i=0; i<MAX_ITERATIONS; i++) {
        strcpy(str1, "Hello, World!");
        strcpy(str2, "Welcome to the world of C programming!");
        int random_num = rand() % 3;
        if(random_num == 0) {
            to_uppercase_async(str1);
        } else if(random_num == 1) {
            to_lowercase_async(str1);
        }
        random_num = rand() % 3;
        if(random_num == 0) {
            to_uppercase_async(str2);
        } else if(random_num == 1) {
            to_lowercase_async(str2);
        }
        result = str_append_async(str1, str2);
        printf("%s\n", result);
        free(result);
    }
    return 0;
}