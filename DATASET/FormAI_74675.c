//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    char inputString[MAX_STRING_LENGTH];
    int len, i, count = 0;
    printf("Enter a string: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin);
    len = strlen(inputString);
    for(i = 0; i < len; i++){
        if(inputString[i] == '('){
            count++;
        }
        else if(inputString[i] == ')'){
            count--;
        }
        if(count < 0){
            printf("Intrusion detected!\n");
            return 0;
        }
    }
    if(count == 0){
        printf("No intrusion detected.\n");
    }
    else{
        printf("Intrusion detected!\n");
    }
    return 0;
}