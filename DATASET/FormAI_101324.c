//FormAI DATASET v1.0 Category: String manipulation ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50], result[100];
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    // Concatenate the two strings
    strcat(result, str1);
    strcat(result, str2);
    
    printf("Concatenated string: %s\n", result);
    
    // Get the length of the first string
    int length = strlen(str1);
    
    printf("Length of first string: %d\n", length);
    
    // Reverse the first string
    char reverse[50];
    int j = 0;
    for(int i=length-1; i>=0; i--) {
        reverse[j++] = str1[i];
    }
    reverse[j] = '\0';
    
    printf("Reversed string: %s\n", reverse);
    
    // Check if the first string contains a substring
    char sub[20];
    printf("Enter the sub string: ");
    scanf("%s", sub);
    
    char *ptr = strstr(str1, sub);
    if(ptr) {
        printf("Substring found at position: %d\n", ptr-str1+1);
    } else {
        printf("Substring not found\n");
    }
    
    return 0;
}