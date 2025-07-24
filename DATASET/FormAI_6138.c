//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Claude Shannon
#include<stdio.h>
#include<string.h>

int main(){
    char input[100];
    int i, j, flag=0;
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    j=strlen(input)-1;
    
    for(i=0; i<strlen(input); i++){
        if(input[i]!=input[j]){
           flag=1;
           break;
        }
        j--;
    }
    
    if(flag==0){
        printf("%s is a palindrome", input);
    }
    else{
        printf("%s is not a palindrome", input);
    }
    
    return 0;
}