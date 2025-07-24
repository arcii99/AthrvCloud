//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include<stdio.h>
#include<string.h>

void printSubstr(char str[], int idx, int len){
    for(int i = idx; i < idx+len; i++){
        printf("%c", str[i]);
    }
    printf("\n");
}

int main(){

    char str[]="Welcome to the world of imagination!";
    char key[]="imagination";
    int keyLen = strlen(key);

    int strLen = strlen(str);

    // check if key exists in str
    for(int i = 0; i <= strLen-keyLen; i++){
        int match = 1;
        for(int j = 0; j < keyLen; j++){
            if(str[i+j] != key[j]){
                match = 0;
                break;
            }
        }
        if(match == 1){
            printf("Key found at index %d\n", i);
            printSubstr(str, i, keyLen);
        }
    }

    return 0;
}