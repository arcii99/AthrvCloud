//FormAI DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <string.h>

char* reverseString(char* str) {
    int length = strlen(str);
    char reversed[length+1];
    for (int i=0; i<length; i++) {
        reversed[i] = str[length-i-1];
    }
    reversed[length] = '\0';
    return reversed;
}

void countVowels(char* str) {
    int length = strlen(str);
    int vowelCount = 0;
    for (int i=0; i<length; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
        }
    }
    printf("Number of vowels in \"%s\": %d\n", str, vowelCount);
}

void concatenateStrings(char* str1, char* str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    char combined[length1+length2+1];
    for (int i=0; i<length1; i++) {
        combined[i] = str1[i];
    }
    for (int i=0; i<length2; i++) {
        combined[length1+i] = str2[i];
    }
    combined[length1+length2] = '\0';
    printf("Concatenated string: %s\n", combined);
}

void removeDuplicates(char* str) {
    int length = strlen(str);
    char result[length+1];
    int k = 0;
    for (int i=0; i<length; i++) {
        int j;
        for (j=0; j<i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == i) {
            result[k++] = str[i];
        }
    }
    result[k] = '\0';
    printf("String with duplicates removed: %s\n", result);
}

void capitalizeString(char* str) {
    int length = strlen(str);
    char capitalized[length+1];
    for (int i=0; i<length; i++) {
        capitalized[i] = toupper(str[i]);
    }
    capitalized[length] = '\0';
    printf("Capitalized string: %s\n", capitalized);
}

int main() {
    char input[100] = "";
    printf("Enter a string of at most 100 characters: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("\n");

    printf("Original string: %s\n", input);
    printf("\n");

    char* reversed = reverseString(input);
    printf("Reversed string: %s\n", reversed);
    printf("\n");

    countVowels(input);
    printf("\n");

    char* append = " is awesome!";
    concatenateStrings(input, append);
    printf("\n");

    removeDuplicates(input);
    printf("\n");

    capitalizeString(input);
    printf("\n");

    return 0;
}