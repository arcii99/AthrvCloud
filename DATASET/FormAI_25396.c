//FormAI DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char str[]) {
    int n = strlen(str);
    for(int i=0; i<n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

// Function to convert all characters to uppercase
void toUpper(char str[]) {
    int n = strlen(str);
    for(int i=0; i<n; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Reverse the string
    reverseString(str);
    
    // Convert all characters to uppercase
    toUpper(str);
    
    // Compute the length of the string
    int len = strlen(str);
    
    // Print the string in a puzzling way
    printf("The string is: ");
    for(int i=0; i<len; i++) {
        if(i % 2 == 0) {
            printf("%c", str[i] - 1);
        } else {
            printf("%c", str[i] + 1);
        }
    }
    
    return 0;
}