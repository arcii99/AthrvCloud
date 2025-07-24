//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *str;
    int i,l,flag=0;

    str=(char*)malloc(sizeof(char));  //Dynamically allocate memory to the string.
    printf("Enter a string: ");
    scanf("%s",str);

    l=strlen(str);
    for(i=0;i<l;i++){
        if(str[i]!=str[l-i-1]){   //If both sides of the string are not equal, then it is not a palindrome.
            flag=1;
            break;
        }
    }

    if(flag)
        printf("%s is not a palindrome\n",str);
    else
        printf("%s is a palindrome\n",str);

    free(str);   //Free the memory allocated to the string.

    return 0;
}