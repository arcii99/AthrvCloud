//FormAI DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include <stdio.h>
#include <string.h>
#define MAX 100

int main(){

    char text[MAX];
    printf("Hello there! Let's count some words today! Enter the text:\n");
    fgets(text, MAX, stdin);
    int length = strlen(text);

    while(text[length-1] == '\n'){
        text[length-1] = '\0';
        length--;
    }

    int words = 1;
    for(int i=0;i<length;i++){
        if(text[i] == ' ' || text[i] == '\t' || text[i] == '\n'){
            words++;
        }
    }

    printf("\nAwesome! Your text has %d words in it! How cool is that? Stay awesome!", words);
    return 0;
}