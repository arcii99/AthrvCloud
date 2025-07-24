//FormAI DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1024 //Maximum length of input string.

char *compress(char *str){ //Function to compress the string.
    int len = strlen(str);
    char *output = calloc(MAX_LEN,sizeof(char)); //Dynamic allocation of memory.
    int count; //variable for counting identical continuous characters.
    int j=0; //variable for indexing compressed string.
    for(int i=0;i<len;i++){ //Traversing string.
        count = 1; //Initializing count to 1 for each character.
        while(str[i] == str[i+1] && i<len){ //Counting identical continuous characters.
            count++;
            i++;
        }
        output[j++] = str[i]; //Copying current character.
        if(count>1){ //Checking if continuous identical characters are present or not.
            output[j++] = count+'0'; //Adding count as an integer in compressed string.
        }
    }
    output[j] = '\0'; //Adding null character for termination of string.
    return output;
}

int main(){
    char str[MAX_LEN];
    printf("Enter a string to compress: ");
    fgets(str,sizeof(str),stdin); //Getting input string from user.
    str[strcspn(str,"\n")] = '\0'; //Removing newline character from input string.
    char *compressed = compress(str); //Calling compress function.
    printf("\nCompressed String: %s",compressed);
    free(compressed); //Freeing the memory allocated for compressed string.
    return 0;
}