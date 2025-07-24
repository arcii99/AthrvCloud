//FormAI DATASET v1.0 Category: Encryption ; Style: retro
#include<stdio.h>
#include<string.h>

char* encrypt(char* str, int key){
    int len = strlen(str);
    int i;
    char* res = (char*)malloc((len+1)*sizeof(char));
    for(i=0;i<len;i++){
        res[i] = ((str[i]+key)%26)+'a';
    }
    res[len] = '\0';
    return res;
}

int main(){
    char str[100];
    int key;
    printf("Enter a string to encrypt: ");
    scanf("%s", str);
    printf("Enter a key value to encrypt with: ");
    scanf("%d", &key);
    char* res = encrypt(str, key);
    printf("The encrypted string is: %s", res);
    free(res);
    return 0;
}