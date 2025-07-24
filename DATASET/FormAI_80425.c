//FormAI DATASET v1.0 Category: Text processing ; Style: sophisticated
#include<stdio.h>
#include<string.h>

int main(){
    char str[1000], key[100];
    int count=0, len1, len2;
    printf("Enter the string: ");
    fgets(str, 1000, stdin);
    printf("Enter the keyword: ");
    scanf("%s", key);
    len1 = strlen(str);
    len2 = strlen(key);
    for(int i=0; i<=len1-len2; i++){
        int j;
        for(j=0; j<len2; j++){
            if(str[i+j] != key[j])
                break;
        }
        if(j == len2){
            count++;
            printf("\nKeyword found at index %d", i);
        }
    }
    if(count == 0){
        printf("\nKeyword not found.");
    }
    return 0;
}