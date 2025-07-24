//FormAI DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    int len = strlen(str);
    for(int i=0;i<len/2;i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

void capitalize(char* str) {
    int len = strlen(str);
    for(int i=0;i<len;i++) {
        if(str[i]>='a' && str[i]<='z') {
            str[i] = str[i] - 32;
        }
    }
}

void removeVowels(char* str) {
    int len = strlen(str);
    for(int i=0;i<len;i++) {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
            for(int j=i;j<len-1;j++) {
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);
    printf("Original string: %s\n", str);
    
    // Reversing the string
    reverse(str);
    printf("Reversed string: %s\n", str);
    
    // Capitalizing the string
    capitalize(str);
    printf("Capitalized string: %s\n", str);
    
    // Removing vowels from the string
    removeVowels(str);
    printf("String after removing vowels: %s\n", str);
    
    return 0;
}