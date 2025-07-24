//FormAI DATASET v1.0 Category: String manipulation ; Style: scalable
#include <stdio.h>
#include <string.h>

void reverse_string(char* str, int len) {
    int i = 0, j = len - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char string[100];
    printf("Enter the string to reverse: ");
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';
    int len = strlen(string);
    reverse_string(string, len);
    printf("Reversed string: %s", string);
    return 0;
}