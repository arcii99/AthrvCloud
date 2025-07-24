//FormAI DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LENGTH 1000
#define MAX_WORD_LENGTH 100

char* dictionary[] = {"hello", "world", "this", "is", "a", "test"};

int main() 
{
    char input[MAX_STR_LENGTH];
    printf("Enter the string to check for spelling errors:\n");
    fgets(input, MAX_STR_LENGTH, stdin);

    char* token = strtok(input, " \t\n");
    while(token != NULL) {
        int flag = 0;
        if(strlen(token) > MAX_WORD_LENGTH) {
            printf("Error: Word is too long\n");
            flag = 1;
        }
        for(int i = 0; i < sizeof(dictionary) / sizeof(char*); i++) {
            if(strcmp(token, dictionary[i]) == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("Error: Spelling mistake in word - %s\n", token);
        }
        token = strtok(NULL, " \t\n");
    }
    return 0;
}