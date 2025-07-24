//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *word) {
    int length = strlen(word);
    for(int i = 0; i < length/2; i++) {
        if(word[i] != word[length - i - 1]) {
            return false;
        }
    }
    return true;
}

void capitalize(char *word) {
    int length = strlen(word);
    for(int i = 0; i < length; i++) {
        if(i == 0) {
            if(word[i] >= 'a' && word[i] <= 'z') {
                word[i] -= 32;
            }
        }
        else if(word[i - 1] == ' ') {
            if(word[i] >= 'a' && word[i] <= 'z') {
                word[i] -= 32;
            }
        }
    }
}

void reverseWords(char *sentence) {
    int length = strlen(sentence);
    int start = 0;
    int end = length - 1;
    char temp;

    while(start < end) {
        temp = sentence[start];
        sentence[start] = sentence[end];
        sentence[end] = temp;
        start++;
        end--;
    }

    start = 0;
    while(sentence[start]) {
        if(sentence[start] == ' ') {
            start++;
            continue;
        }
        end = start + 1;
        while(sentence[end] != ' ' && sentence[end] != '\0') {
            end++;
        }
        end--;

        int wordStart = start;
        int wordEnd = end;
        while(wordStart < wordEnd) {
            temp = sentence[wordStart];
            sentence[wordStart] = sentence[wordEnd];
            sentence[wordEnd] = temp;
            wordStart++;
            wordEnd--;
        }
        start = end + 1;
    }
}

int main() {
    char input[100], copy[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    strcpy(copy, input);

    if(isPalindrome(copy)) {
        printf("%s is a palindrome\n", input);
    }
    else {
        printf("%s is not a palindrome\n", input);
    }

    capitalize(input);
    printf("Capitalized string: %s\n", input);

    reverseWords(input);
    printf("Reversed word string: %s", input);

    return 0;
}