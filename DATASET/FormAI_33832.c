//FormAI DATASET v1.0 Category: Word Count Tool ; Style: excited
#include<stdio.h>
#include<string.h>
#define MAX 1000

int countWords(char* c) {
    int count = 0;
    for(int i=0; c[i]!='\0';i++) {
        if(c[i] == ' ' || c[i] == '\n' || c[i] == '\t') {
            count++;
        }
    }
    count++;
    return count;
}

int main(){
    char code[MAX];
    int words;

    printf("Enter your C code here:\n");
    fgets(code, MAX, stdin);

    words = countWords(code);

    printf("Total number of words in your C code: %d\n", words);

    return 0;
}