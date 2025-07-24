//FormAI DATASET v1.0 Category: Text processing ; Style: portable
#include<stdio.h>
#include<string.h>

int main(){

    char str[1000], unique[1000];
    int count=0;

    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    for(int i=0; i<strlen(str); i++){
        int j;
        for(j=0; j<count; j++){
            if(str[i] == unique[j]){ //if already in unique[] array, skip
                break;
            }
        }
        if(j==count){ //if not in unique[] array, add to unique[] array
            unique[count++] = str[i];
        }
    }

    printf("Unique characters in the entered string: ");
    for(int i=0; i<count; i++){
        printf("%c ", unique[i]);
    }

    return 0;
}