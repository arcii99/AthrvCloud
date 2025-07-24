//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char str[1000], temp[1000];
    int i, j, len, flag;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    for(i=0; i<len; i++){
        if(str[i] == ' '){
            flag = 1;
        }
        if(str[i] == ',' || str[i] == '.' || str[i] == '\n' || str[i] == '\0'){
            if(flag == 0){
                printf("%c", str[i]);
                printf(" ");
            }
            else{
                printf("%c", str[i]);
            }
            flag = 0;
        }
        else{
            if(flag == 1){
                printf("%c", str[i]-32);
            }
            else{
                printf("%c", str[i]);
            }
        }
    }

    return 0;
}