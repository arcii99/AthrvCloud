//FormAI DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    char str[1000];

    printf("Enter the string: ");
    fgets(str,1000,stdin);

    int len=strlen(str);
    int count=0,flag=0;

    for(int i=0;i<len-1;i++) {
        if(str[i]==' ') {
            flag=0;
        }
        else {
            if(flag==0) {
                flag=1;
                count++;
            }
        }
    }

    if(count==0) {
        printf("The string is empty.");
    }
    else {
        printf("The total number of words in the string is %d.",count);
    }

    return 0;
}