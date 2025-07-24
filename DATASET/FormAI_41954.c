//FormAI DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cheer(char *name){
    printf("Hey %s! You're amazing!\n", name);
}

int main(){
    char str[100];
    char *token;
    printf("Enter a sentence:\n");
    fgets(str, 100, stdin);
    printf("You entered: %s\n", str);
    printf("Let's process it!\n");

    token = strtok(str, " ");
    while(token != NULL){
        cheer(token);
        token = strtok(NULL, " ");
    }

    return 0;
}