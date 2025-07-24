//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void palindromeChecker(char str[]){
    // Remove special characters and spaces
    int index=0;
    char temp[100];
    for(int i=0;i<strlen(str);i++){
        if(isalnum(str[i])){
            temp[index++]=tolower(str[i]);
        }
    }
    temp[index]='\0';
    int len=strlen(temp);
    // Check for palindrome
    int flag=1;
    for(int i=0;i<=len/2;i++){
        if(temp[i]!=temp[len-i-1]){
            flag=0;
            break;
        }
    }
    if(flag==1){
        printf("%s is Palindrome!\n",str);
    }else{
        printf("%s is not Palindrome!\n",str);
    }
}

int main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str,100,stdin);
    palindromeChecker(str);
    return 0;
}