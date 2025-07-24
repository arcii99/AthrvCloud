//FormAI DATASET v1.0 Category: Word Count Tool ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[1000], word[1000];
    int count = 0, i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the word to count: ");
    scanf("%s", word);

    for(i=0; i<strlen(str); i++){
        if(str[i] == word[0]){
            int flag = 0;
            for(j=0; j<strlen(word); j++){
                if(str[i+j] != word[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                count++;
            }
        }
    }

    printf("The count of word '%s' in the given string is: %d", word, count);

    return 0;
}