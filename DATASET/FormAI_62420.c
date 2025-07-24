//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer
int getRandomInt(int max) {
    return rand() % max;
}

// Function to randomly shuffle a string
void shuffleString(char* str) {
    int len = strlen(str);
    
    // Randomly shuffle each character
    for (int i = 0; i < len; i++) {
        int j = getRandomInt(len);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to count the number of occurrences of a character in a string
int countChar(char* str, char c) {
    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    // Specify the string to manipulate
    char str[] = "hello world";
    int len = strlen(str);
    
    // Output the original string
    printf("Original string: %s\n", str);
    
    // Randomly shuffle the string
    srand(time(NULL));
    shuffleString(str);
    printf("The received message : %s\n", str);
    
    // Count the number of occurrences of each character
    for (char c = 'a'; c <= 'z'; c++) {
        int count = countChar(str, c);
        if (count > 0) {
            printf("The Character %c occurs %d times.\n", c, count);
        }
    }
    return 0;
}