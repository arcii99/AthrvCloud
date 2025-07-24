//FormAI DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

int wordCount(char *str);

int main() {
    char str[MAX_BUFFER_SIZE];
    int count;

    printf("Enter a string: ");
    fgets(str, MAX_BUFFER_SIZE, stdin);
    
    count = wordCount(str);
    
    printf("The number of words in the string is %d.", count);
    
    return 0;
}

int wordCount(char *str){
    int count = 0;
    int isWord = 0;
    
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r') {
            if(isWord == 1) {
                count++;
                isWord = 0;
            }
        }
        else {
            isWord = 1;
        }
    }
    
    if(isWord == 1) {
        count++;
    }
    
    return count;
}