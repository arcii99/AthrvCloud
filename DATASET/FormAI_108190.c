//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include<stdio.h>

int main(){
    char str[100];
    int i,words=1;

    printf("Enter any string: ");
    gets(str);

    for(i=0; str[i]!='\0'; i++){
        if(str[i]==' ' || str[i]=='\n' || str[i]=='\t'){
            words++;
        }
    }

    printf("Total word count is: %d\n",words);

    return 0;
}