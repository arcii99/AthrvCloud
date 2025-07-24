//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* s) {
    int arr[26] = {0};
    int length = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (length + 1));
    int j = 0;
    for(int i = 0; i < length; i++) {
        arr[s[i] - 'a']++;
    }
    for(int i = 0; i < length; i++) {
        if(arr[s[i] - 'a'] != 0 && s[i] != ' ') {
            result[j++] = s[i];
            result[j++] = '0' + arr[s[i] - 'a'];
            arr[s[i] - 'a'] = 0;
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char* s = "abccdeefggghhiiijjjkkk";
    printf("Original string: %s\n", s);
    char* compressed = compress(s);
    printf("Compressed string: %s\n", compressed);
    free(compressed);
    return 0;
}