//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1024

//function to check if a character is a symbol
bool isSymbol(char ch) {
    int i;
    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', '[', ']', '{', '}', '\\', '|', ';', ':', '\'', '\"', ',', '.', '/', '<', '>', '?', '`', '~'};
    for(i=0; i<35; i++) {
        if(ch == symbols[i])
            return true;
    }
    return false;
}

//function to remove symbols from the URL
void removeSymbols(char *url) {
    int i, j;
    int len = strlen(url);
    for(i=0; i<len; i++) {
        if(isSymbol(url[i])) {
            for(j=i; j<len-1; j++)
                url[j] = url[j+1];
            url[len-1] = '\0';
            i--;
            len--;
        }
    }
}

//function to add "http://" prefix to the URL
void addPrefix(char *url) {
    int i, j;
    int len = strlen(url);
    if(len < 7) {
        char temp[len+1];
        strcpy(temp, url);
        for(i=0; i<len; i++)
            url[i+7-len] = temp[i];
        for(j=0; j<7-len; j++)
            url[j] = 'h';   //fill remaining spaces with 'h'
        url[7] = 't';       //add 't' after 'h'
        url[8] = 't';       //add 't' after previous 't'
        url[9] = 'p';       //add 'p' after previous 't'
        url[10] = ':';      //add ':' after 'p'
        url[11] = '/';      //add '/' after ':'
        url[12] = '/';      //add '/' after previous '/'
        url[len+6] = '\0';  //add null character at the end
    }
}

//function to remove consecutive slashes from the URL
void removeConsecutiveSlashes(char *url) {
    int i, j;
    int len = strlen(url);
    for(i=0; i<len; i++) {
        if(url[i] == '/') {
            for(j=i+1; url[j] == '/'; j++);
            if(j-i > 1) {
                int k;
                for(k=j-1; k<len-j+i; k++)
                    url[k-j+i+1] = url[k];
                url[len-j+i+1] = '\0';
                len = strlen(url);
                i--;
            }
        }
    }
}

int main() {
    char url[MAX_SIZE];
    printf("Enter a URL: ");
    scanf("%[^\n]%*c", url);
    removeSymbols(url);
    addPrefix(url);
    removeConsecutiveSlashes(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}