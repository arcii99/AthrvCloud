//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *runLengthEncoding(char *string){
    int length = strlen(string);
    char *result = (char *)malloc(sizeof(char) * (2 * length + 1));
    int index = 0, count = 1;
    
    for(int i = 1; i < length; i++){
        if(string[i] == string[i - 1]){
            count++;
        }
        else{
            result[index++] = count + '0';
            result[index++] = string[i - 1];
            count = 1;
        }
    }
    
    result[index++] = count + '0';
    result[index++] = string[length - 1];
    result[index] = '\0';
    
    return result;
}

int main(){
    char inputString[1000], *resultString;
    
    printf("Enter the string to be compressed: ");
    scanf("%[^\n]s", inputString);
    
    resultString = runLengthEncoding(inputString);
    
    printf("The compressed string is: %s\n", resultString);
    
    free(resultString);
    
    return 0;
}