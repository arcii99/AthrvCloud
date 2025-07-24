//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void reverse(char *str, int start, int end) {
    if(start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverse(str, start+1, end-1);
}

int length(char *str) {
    if(*str == '\0') return 0;
    return 1 + length(str+1);
}

int compareTo(char *str1, char *str2) {
    if(*str1 == '\0' && *str2 == '\0') return 0;
    if(*str1 == *str2) return compareTo(str1+1, str2+1);
    if(*str1 < *str2) return -1;
    if(*str1 > *str2) return 1;
}

void append(char *str1, char *str2) {
    if(*str1 == '\0') {
        *str1 = *str2;
        return;
    }
    append(str1+1, str2);
}

int main() {
    char str1[100], str2[100];
    printf("Enter string 1: ");
    fgets(str1, 100, stdin);
    printf("Enter string 2: ");
    fgets(str2, 100, stdin);
    printf("String 1 length: %d\n", length(str1));
    printf("String 2 length: %d\n", length(str2));
    int cmp = compareTo(str1, str2);
    if(cmp == 0) printf("String 1 and string 2 are equal.\n");
    else if(cmp < 0) printf("String 1 is less than string 2.\n");
    else printf("String 1 is greater than string 2.\n");
    reverse(str1, 0, length(str1)-1);
    printf("Reverse of string 1: %s", str1);
    append(str1, str2);
    printf("Concatenated string: %s", str1);
    return 0;
}