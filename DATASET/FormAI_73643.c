//FormAI DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    char str[1000];
    int count=0, i=0;

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    if(strlen(str)==1){
        printf("The string is empty.\n");
        exit(0);
    }

    while(str[i]!='\0'){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            count++;
            while(str[i]!=' ' && str[i]!='\n' && str[i]!='\0')
                i++;
        }
        else
            i++;
    }

    printf("The word count in the string is: %d\n", count);

    return 0;
}