//FormAI DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char* str)
{
    char newStr[strlen(str)];
    int count = 1;
    int k = 0;

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == str[i + 1]){
            count++;
        }else{
            newStr[k++] = str[i];
            if(count > 1){
                char numStr[4];
                sprintf(numStr, "%d", count);
                for(int j = 0; j < strlen(numStr); j++){
                    newStr[k++] = numStr[j];
                }
                count = 1;
            }
        }
    }
    newStr[k] = '\0';
    printf("Compressed string: %s\n", newStr);
}

int main()
{
    char input[100];
    printf("Enter the string to be compressed: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Original string: %s\n", input);
    compress(input);

    return 0;
}