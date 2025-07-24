//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter your sentence in C Cat language: ");
    fgets(input, 100, stdin);
    printf("-------------------------\n");
    printf("Translation to English:\n");

    char *token = strtok(input, " ");
    while (token != NULL) {
        if(strcmp(token,"MEOW")==0) {
            printf("I ");
        } else if(strcmp(token,"PURR")==0) {
            printf("love ");
        } else if(strcmp(token,"HISS")==0) {
            printf("hate ");
        } else if(strcmp(token,"SCRATCH")==0) {
            printf("attack ");
        } else if(strcmp(token,"NAP")==0) {
            printf("sleep ");
        } else if(strcmp(token,"HUNT")==0) {
            printf("chase ");
        } else if(strcmp(token,"WALK")==0) {
            printf("run ");
        } else {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    printf("\n-------------------------\n");
    return 0;
}