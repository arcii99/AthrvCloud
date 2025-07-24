//FormAI DATASET v1.0 Category: modern Encryption ; Style: recursive
#include<stdio.h>
#include<string.h>

void encrypt(char *str, int key);

int main(){
    
    char string[1000];
    int key;
    
    printf("Enter a string: ");
    fgets(string, 1000, stdin);
    printf("Enter a key (integer): ");
    scanf("%d", &key);
    
    encrypt(string, key);
    
    printf("The encrypted string is: %s", string);
    
    return 0;
}

void encrypt(char *str, int key){
    
    int len = strlen(str);
    
    if(len == 1){   // base case for recursion
        str[0] = str[0] + key;
        return;
    }
    
    encrypt(str + 1, key);  // recursive call
    
    str[0] = str[0] + key;
    
    return;
}