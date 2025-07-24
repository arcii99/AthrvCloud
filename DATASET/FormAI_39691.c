//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

void countWords(char *str, int *count){
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int i=0, j=0, k=0, l=0;

    while(*(str+i)){
        if(isspace(*(str+i))){
            words[j][k] = '\0';
            j++;
            k = 0;
        }
        else{
            words[j][k++] = tolower(*(str+i));
        }
        i++;
    }

    words[j][k] = '\0';
    int n = j;
    for(i=0;i<=n;i++){
        count[i] = 1;
        for(j=i+1;j<=n;j++){
            if(strcmp(words[i], words[j]) == 0){
                count[i]++;
                for(k=j;k<=n;k++){
                    strcpy(words[k], words[k+1]);
                }
                n--;
                j--;
            }
        }
    }

    for(i=0;i<=n;i++){
        printf("%s : %d\n", words[i], count[i]);
    }
}

int main(){
    char str[10000];
    int count[MAX_WORDS];

    printf("Enter a string: ");
    fgets(str, 10000, stdin);

    countWords(str, count);

    return 0;
}