//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long int power(int base, int exp){
    unsigned long int res = 1;
    for(int i=0; i<exp; i++){
        res *= base;
    }
    return res;
}

unsigned long int stringToNum(char* str){
    unsigned long int res = 0;
    int len = strlen(str);
    for(int i=0; i<len; i++){
        res += (str[i]-'0')*power(10, len-i-1);
    }
    return res;
}

unsigned long int hash(char* str){
    unsigned long int num = stringToNum(str);
    unsigned long int hash = num*num+num+101;
    return hash;
}

int main(){
    char str[100];
    printf("Enter the string to be hashed: ");
    scanf("%s", str);
    unsigned long int hashed = hash(str);
    printf("The hash code for \"%s\" is %lu\n", str, hashed);
    return 0;
}