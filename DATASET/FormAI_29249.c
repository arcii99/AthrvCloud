//FormAI DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear(char s[]){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        s[i] = '\0';
    }
}

int main() {
    char str1[20], str2[20], str3[40];
    int len_str1, len_str2;
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);
    
    len_str1 = strlen(str1);
    len_str2 = strlen(str2);
    
    strcpy(str3, str1);
    strcat(str3, str2);
    
    printf("\nString 1: %s", str1);
    printf("\nString 2: %s", str2);
    printf("\nString length of String 1: %d", len_str1);
    printf("\nString length of String 2: %d", len_str2);
    printf("\nConcatenated String: %s\n", str3);
    
    printf("\nCopying last 5 characters of String 3: ");
    clear(str1);
    strncpy(str1, &str3[strlen(str3) - 5], 5);
    printf("%s\n", str1);

    printf("\nReversing String 1: ");
    clear(str2);
    for (int i = len_str1-1; i >= 0; i--){
        str2[len_str1-1-i] = str1[i];
    }
    printf("%s\n", str2);
    
    return 0;
}