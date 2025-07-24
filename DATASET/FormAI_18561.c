//FormAI DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char c[] = "int x = 5;";
    char *token = strtok(c, " ");
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    return 0;
}