//FormAI DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_LENGTH 100

int main(){
    char string[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);
    for(int i=0; i<strlen(string); i++){
        string[i] = toupper(string[i]);
    }
    printf("Uppercased string: %s", string);
    return 0;
}