//FormAI DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char* compress(char* str);

int main()
{
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    
    char* compressed = compress(str);
    printf("Compressed string: %s\n", compressed);
    
    free(compressed);
    return 0;
}

char* compress(char* str)
{
    int count = 1;
    char curr_char = str[0];
    int len = strlen(str);
    char* compressed = (char*) malloc(sizeof(char) * (len + 1));
    int index = 0;
    
    for(int i = 1; i < len; i++){
    
        if(str[i] == curr_char){
            count++;
        }
        else{
            compressed[index++] = curr_char;
            compressed[index++] = '0' + count;
            
            curr_char = str[i];
            count = 1;
        }
    }
    
    compressed[index++] = curr_char;
    compressed[index++] = '0' + count;
    compressed[index] = '\0';
    
    return compressed;
}