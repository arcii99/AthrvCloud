//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include<stdio.h>
#include<ctype.h>

//function to count words in string
int wordCount(char *str) {
    int count = 0, state = 0;
    while (*str) {
        if (isspace(*str)) {
            state = 0; //previously a word
        }
        else if (state == 0) {
            state = 1;
            count++;
        }
        ++str;
    }
    return count;
}

int main() {
    char str[1000];
    printf("Enter a string: \n");
    fgets(str, sizeof(str), stdin);
    printf("The string entered is: %s", str);
    int count = wordCount(str);
    printf("Number of words in the string: %d", count);
    return 0;
}