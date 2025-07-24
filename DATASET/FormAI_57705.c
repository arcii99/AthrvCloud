//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countWords(char str[]) {
    int count = 0;  // To keep track of the number of words
    int i;
    int len = strlen(str);
    int prevCharType = 0;  // To keep track of the previously encountered character type. 0=other, 1=letter, 2=digit
    for (i = 0; i < len; i++) {
        int charType = 0;
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            charType = 1;  // If letter, set charType = 1
        } else if (str[i] >= '0' && str[i] <= '9') {
            charType = 2;  // If digit, set charType = 2
        }
        // Check if the character type changes from non-letter to letter or non-digit to digit
        if ((prevCharType != charType) && (charType == 1 || charType == 2)) {
            count++;
        }
        prevCharType = charType;
    }
    // Check if the last character is a letter or digit
    if (prevCharType == 1 || prevCharType == 2) {
        count++;
    }
    return count;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);  // Read input string from user
    printf("The number of words in the string is: %d", countWords(str));
    return 0;
}