//FormAI DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";

    printf("Before concatenation:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    printf("After concatenation:\n");
    strcat(str1, str2);
    printf("str1: %s\n", str1);

    printf("Reversing the concatenated string:\n");
    int len = strlen(str1);
    char str3[50];

    for(int i=0; i<len; i++) {
        str3[i] = str1[len-1-i];
    }
    str3[len] = '\0';

    printf("str3: %s\n", str3);

    printf("Converting the reversed string to uppercase:\n");
    char str4[50];
    len = strlen(str3);

    for(int i=0; i<len; i++) {
        if(str3[i] >= 'a' && str3[i] <= 'z') {
            str4[i] = str3[i] - 32;
        }
        else {
            str4[i] = str3[i];
        }
    }
    str4[len] = '\0';
    printf("str4: %s\n", str4);

    return 0;
}