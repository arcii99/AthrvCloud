//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random key of given length
char* generateKey(int len){
    char* key=(char*)malloc((len+1)*sizeof(char));
    int i;
    for(i=0;i<len;i++){
        key[i]=(char)('a'+(rand()%26)); //assuming only lowercase letters are allowed
    }
    key[len]='\0';
    return key;
}

//Function to perform XOR operation between two strings
char* xorStrings(char* str1, char* str2){
    int len=strlen(str1);
    char* xorOutput=(char*)malloc((len+1)*sizeof(char));
    int i;
    for(i=0;i<len;i++){
        xorOutput[i]=(char)(str1[i]^str2[i]);
    }
    xorOutput[i]='\0';
    return xorOutput;
}

int main(){
    //Reading input plaintext and key from user
    char str[100];
    printf("Enter the plaintext to be encrypted: ");
    scanf("%s", str);
    int strLen=strlen(str);
    char* key=generateKey(strLen);

    //Printing key and plaintext
    printf("The key generated is: %s\n", key);
    printf("The plaintext is: %s\n", str);

    //Generating cipher text by XORing the plaintext and key
    char* cipher=xorStrings(str, key);

    //Printing the cipher text
    printf("The cipher text is: %s\n", cipher);

    return 0;
}