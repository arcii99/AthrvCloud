//FormAI DATASET v1.0 Category: String manipulation ; Style: optimized
#include<stdio.h>
#include<string.h>

int main() {
    char str[100];
    int i, n, j;

    printf("Enter a string: ");
    scanf("%s", str);

    n = strlen(str);

    printf("Original string: %s\n", str);

    for(i = 0; i < n; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // converting lowercase to uppercase
        }
    }
    printf("Converted string: %s\n", str);

    for(i = 0, j = n-1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp; // reversing the string
    }
    printf("Reversed string: %s\n", str);

    char sub[50];
    printf("Enter a substring to search: ");
    scanf("%s", sub);

    int sub_len = strlen(sub);
    int count = 0;
    for(i = 0; i < n - sub_len; i++) {
        if(strncmp(&str[i], sub, sub_len) == 0) { // searching for the substring
            count++;
            printf("Substring found at index %d\n", i);
        }
    }
    if(count == 0) {
        printf("Substring not found in the string.\n");
    } else {
        printf("Total occurrences of the substring: %d\n", count);
    }

    return 0;
}