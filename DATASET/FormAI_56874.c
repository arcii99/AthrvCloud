//FormAI DATASET v1.0 Category: String manipulation ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[100] = "Hello, ";
    char str2[50] = "world!";
    
    // Concatenating two strings
    strcat(str1, str2);
    
    // Converting all characters to uppercase
    for(int i=0; i<strlen(str1); i++){
        if(str1[i] >= 'a' && str1[i] <= 'z'){
            str1[i] = str1[i] - 32;
        }
    }
    
    // Reversing the entire string
    int len = strlen(str1);
    for(int i=0; i<len/2; i++){
        char temp = str1[i];
        str1[i] = str1[len-i-1];
        str1[len-i-1] = temp;
    }
    
    // Printing the final output in bold style
    printf("\033[1m%s\033[0m", str1);
    
    return 0;
}