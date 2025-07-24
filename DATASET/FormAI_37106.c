//FormAI DATASET v1.0 Category: modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* s, int key) {
    // return empty string if input is null
    if (s == NULL) {
        char* res = "";
        return res;
    }
    int len = strlen(s);
    // allocate a new string with the same length as the input string
    char* res = (char*) malloc((len + 1) * sizeof(char));
    strcpy(res, s);

    if (key != 0) {
        // recursive part
        char* tmp = encrypt(res, key - 1);
        free(res);
        res = tmp;
    }

    // perform the encryption by shifting each character by the key
    for (int i = 0; i < len; i++) {
        res[i] += key;
    }
    return res;
}

int main() {
    char s[] = "hello world";
    int key = 3;
    char* encrypted = encrypt(s, key);
    printf("Encrypted string: %s\n", encrypted);
    free(encrypted);
    return 0;
}