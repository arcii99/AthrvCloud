//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: multivariable
#include<stdio.h>
#include<string.h>

int main(){

    char input[100];
    int len,i,j,flag=0;  
    
    printf("Enter a string: ");
    scanf("%s",input);
    
    len=strlen(input); 
    
    for(i=0,j=len-1;i<len/2;i++,j--){
        if(input[i]!=input[j]){
            flag=1;
            break;
        }
    }
    
    if(flag){
        printf("%s is not a palindrome.",input);
    }else{
        printf("%s is a palindrome.",input);
    }
    
    return 0;
}