//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <string.h>

void reverse_string(char* s, int start, int end) {
    // Reverses the characters in a substring of s from start to end, inclusive
    int i = start, j = end;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

void reverse_words(char* s) {
    // Reverses each word in the string s in place, while leaving the order of the words intact
    int n = strlen(s);
    int start = 0, end = 0;
    while (end < n) {
        if (s[end] == ' ') {
            // Found the end of a word
            reverse_string(s, start, end - 1);
            start = end + 1;
            end = start;
        } else {
            // Continue scanning for word end
            end++;
        }
    }
    // Reverse the last word in the string
    reverse_string(s, start, end - 1);
}

int main() {
    char s[] = "Hello world, this is a test!";
    reverse_words(s);
    printf("%s\n", s);  // Expected output: "olleH dlrow, siht si a !tset"
    return 0;
}