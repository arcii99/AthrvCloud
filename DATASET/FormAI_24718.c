//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to generate a random key for encryption
int generateKey(){
    srand(time(NULL));
    int key=rand()%26+1;//generates random key in the range of 1-26
    return key;
}

// function to encrypt a given string using Caesar Cipher algorithm
char* encrypt(char* str,int key){
    int i=0;//index variable
    while(str[i]!='\0'){//loops through each character of the string until NULL character is encountered
        if(str[i]>='a' && str[i]<='z'){//if character is lowercase alphabet
            str[i]=(str[i]-'a'+key)%26+'a';//apply the encryption formula
        }
        else if(str[i]>='A' && str[i]<='Z'){//if character is uppercase alphabet
            str[i]=(str[i]-'A'+key)%26+'A';
        }
        i++;
    }
    return str;//return the encrypted string
}

int main(){
    char str[100];//string input
    int key=generateKey();//generate random key
    printf("Enter a string to be encrypted: ");
    fgets(str,100,stdin);//reads string input from user
    printf("The generated key is %d\n",key);
    char* encryptedStr=encrypt(str,key);//call encrypt function to encrypt the given string
    printf("The encrypted string is: %s",encryptedStr);
    return 0;
}