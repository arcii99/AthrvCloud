//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
#include<stdio.h>

//Function to check if a string is a valid identifier or not
int isValidIdentifier(char *str){
    int len=0, i;

    while(str[len]!='\0'){
        len++;
    }
    //Check if first character is a letter or an underscore
    if(!(str[0]=='_' || (str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z'))){
        return 0;
    }
    //Check if the remaining characters are letters, digits or underscores
    for(i=1;i<len;i++){
        if(!(str[i]=='_' || (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9'))){
            return 0;
        }
    }
    return 1;
}

//Main function
int main(){
    char identifier[100];

    //Prompt user to enter an identifier
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    //Check if the entered string is a valid identifier
    if(isValidIdentifier(identifier)){
        printf("%s is a valid identifier.", identifier);
    }
    else{
        printf("%s is not a valid identifier.", identifier);
    }

    return 0;
}