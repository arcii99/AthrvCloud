//FormAI DATASET v1.0 Category: Browser Plugin ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

char* plugin(char* url) {
    char* result = malloc(1024);
    int i = 0;
    int j = 0;
    while (url[i] != '\0') {
        if (url[i] == 'h' && url[i+1] == 't' && url[i+2] == 't' && url[i+3] == 'p') {
            result[j++] = 'h';
            result[j++] = 't';
            result[j++] = 't';
            result[j++] = 'p';
            result[j++] = 's';
            i += 4;
        } else if (isDigit(url[i]) && !isDigit(url[i+1])) {
            result[j++] = url[i++];
            result[j++] = ',';
        } else {
            result[j++] = url[i++];
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char* url = "http://www.example.com?id=1234";
    printf("Original URL: %s\n", url);
    char* result = plugin(url);
    printf("Plugin URL: %s\n", result);

    free(result);
    return 0;
}