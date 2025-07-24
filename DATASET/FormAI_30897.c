//FormAI DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

void swap(char *s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void s_camel_case(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '_') {
            swap(s, i, i+1);
            s[i+1] = s[i+1] - 32;
        }
    }
}

void s_snake_case(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
            if (i > 0) {
                s[i-1] = '_';
            }
        }
    }
}

void s_title_case(char *s) {
    int len = strlen(s);
    s[0] = s[0] - 32;
    for (int i = 1; i < len; i++) {
        if (s[i-1] == ' ') {
            s[i] = s[i] - 32;
        }
    }
}

void s_rot13(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + 13) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + 13) % 26;
        }
        s[i] = c;
    }
}

void s_reverse_words(char *s) {
    reverse(s, 0, strlen(s)-1);
    int len = strlen(s);
    int start = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            reverse(s, start, i-1);
            start = i+1;
        }
    }
    reverse(s, start, len-1);
}

int main() {
    char s[100] = "hello_world";
    s_camel_case(s);
    printf("%s\n", s); // should print "helloWorld"

    strcpy(s, "HelloWorld");
    s_snake_case(s);
    printf("%s\n", s); // should print "hello_world"

    strcpy(s, "the quick brown fox jumps over the lazy dog");
    s_title_case(s);
    printf("%s\n", s); // should print "The Quick Brown Fox Jumps Over The Lazy Dog"

    strcpy(s, "hello");
    s_rot13(s);
    printf("%s\n", s); // should print "uryyb"

    strcpy(s, "the quick brown fox");
    s_reverse_words(s);
    printf("%s\n", s); // should print "fox brown quick the"
    
    return 0;
}