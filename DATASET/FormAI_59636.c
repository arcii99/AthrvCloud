//FormAI DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 50

char* recursive_compress(char* str, int len, int cur, int count){
    
    // If current index is past the length of string, free memory and return compressed string
    if(cur == len){
        char* compressed = (char*) malloc(sizeof(char) * (len + 1));
        sprintf(compressed, "%s%d", str, count);
        free(str);
        return compressed;
    }
    
    // If current character is same as previous character, increase count and go to next index
    else if(cur > 0 && str[cur] == str[cur-1]){
        return recursive_compress(str, len, cur+1, count+1);
    }
    
    // If current character is different from previous character, insert count before current character and go to next index
    else{
        char* temp = (char*) malloc(sizeof(char) * (len + count + 1));
        strncpy(temp, str, cur);
        sprintf(temp+cur, "%d%c", count, str[cur]);
        strncpy(temp+cur+2, str+cur+1, len-cur-1);
        free(str);
        return  recursive_compress(temp, len+count+1, cur+2, 1);
    }
}

int main(){
    
    char* input = (char*) malloc(sizeof(char) * MAX_STR_LEN);
    printf("Enter a string: ");
    fgets(input, MAX_STR_LEN, stdin);
    input[strcspn(input, "\n")] = 0;  // remove newline character
    
    char* compressed = recursive_compress(input, strlen(input), 0, 1);
    printf("Compressed string: %s\n", compressed);
    
    free(compressed);
    return 0;
}