//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <string.h>

int spamDetect(char str[], int index, int count) {

    // Base case
    if (index >= strlen(str)) {
        return count;
    }

    // Check if word "buy" is found
    if (str[index] == 'b' && str[index+1] == 'u' && str[index+2] == 'y') {
        count++;
        return spamDetect(str, index+3, count);
    }

    // Check if word "discount" is found
    if (str[index] == 'd' && str[index+1] == 'i' && str[index+2] == 's'
       && str[index+3] == 'c' && str[index+4] == 'o' && str[index+5] == 'u' 
       && str[index+6] == 'n' && str[index+7] == 't') {
        count++;
        return spamDetect(str, index+8, count);
    }

    // Check if word "free" is found
    if (str[index] == 'f' && str[index+1] == 'r' && str[index+2] == 'e' && str[index+3] == 'e') {
        count++;
        return spamDetect(str, index+4, count);
    }

    // Check if word "offer" is found
    if (str[index] == 'o' && str[index+1] == 'f' && str[index+2] == 'f' && str[index+3] == 'e' 
       && str[index+4] == 'r') {
        count++;
        return spamDetect(str, index+5, count);
    }

    // Check if word "win" is found
    if (str[index] == 'w' && str[index+1] == 'i' && str[index+2] == 'n') {
        count++;
        return spamDetect(str, index+3, count);
    }

    return spamDetect(str, index+1, count); // Recursive call
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    int count = spamDetect(str, 0, 0);
    if (count > 0) {
        printf("\nThis string is classified as spam.\n");
    } else {
        printf("\nThis string is not classified as spam.\n");
    }
    return 0;
}