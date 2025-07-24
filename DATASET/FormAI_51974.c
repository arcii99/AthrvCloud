//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>
#include <string.h>

int recursiveChecksum(char *str, int len, int sum) {
    if (len == 0) { // If empty string
        return sum;
    } 
    else {
        // Recursively call the function and add the ASCII value of the current character to the sum
        return recursiveChecksum(str+1, len-1, sum + (int)*str);
    }
}

int main() {
    char inputString[100];
    printf("Enter a string to calculate checksum: ");
    scanf("%s", inputString);
    
    int length = strlen(inputString);
    int result = recursiveChecksum(inputString, length, 0);
    
    printf("Checksum of the string %s is %d", inputString, result);
    
    return 0;
}