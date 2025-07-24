//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

void reverse(char *str, int start, int end) {
    if(start >= end)
        return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverse(str, start+1, end-1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    reverse(str, 0, strlen(str)-1);
    printf("Reversed string: %s", str);
    return 0;
}