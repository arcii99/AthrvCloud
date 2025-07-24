//FormAI DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include<stdio.h>

//defining function to check if the character is an alphabet 
int isAlphabet(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
    }
    return 0;
}

int main(){

    //declaring variables to store input string and length of string
    char str[100];
    int len;

    //taking input from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    //getting length of input string
    len = strlen(str);

    //iterating through the string
    for(int i=0; i<len; i++){

        //checking if the character is an alphabet
        if(isAlphabet(str[i])){

            //printing the character in uppercase
            printf("%c", toupper(str[i]));
        }
        else{

            //printing the character as it is
            printf("%c", str[i]);
        }

    }

    return 0;
}