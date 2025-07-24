//FormAI DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toUpperCase(char *str);
void calculateFrequency(char *data);
void replaceString(char *str, char *target, char *replacement);

int main() {
    char input[100];
    printf("Enter some text: ");
    fgets(input, 100, stdin);
    toUpperCase(input);
    printf("Upper case text: %s\n", input);
    calculateFrequency(input);
    char target[20], replacement[20];
    printf("Enter the string you want to replace: ");
    fgets(target, 20, stdin);
    printf("Enter the replacement string: ");
    fgets(replacement, 20, stdin);
    replaceString(input, target, replacement);
    printf("New string: %s\n", input);
    return 0;
}

void toUpperCase(char *str) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

void calculateFrequency(char *data) {
    int frequency[26] = {0};
    for(int i=0; i<strlen(data); i++) {
        if(data[i] >= 'A' && data[i] <= 'Z') {
            frequency[data[i] - 'A']++;
        }
    }
    printf("Frequency of each character:\n");
    for(int i=0; i<26; i++) {
        printf("%c: %d\n", 'A'+i, frequency[i]);
    }
}

void replaceString(char *str, char *target, char *replacement) {
    char *ptr = strstr(str, target);
    while(ptr != NULL) {
        int len = strlen(target);
        memmove(ptr+len, ptr, strlen(ptr)+1-len);
        memcpy(ptr, replacement, strlen(replacement));
        ptr = strstr(ptr+strlen(replacement), target);
    }
}