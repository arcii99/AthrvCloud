//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// function to check if a given character is a valid URL character
int isValidChar(char ch) {
    if(isalpha(ch) || isdigit(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~')
        return 1;
    else
        return 0;
}

// function to sanitize a given URL
void sanitizeURL(char* url) {
    int i, j, len;
    len = strlen(url);
    char* temp = (char*)malloc(sizeof(char)*(len+1));
    j = 0;
    for(i=0; i<len; i++) {
        if(isValidChar(url[i])) {
            temp[j++] = url[i];
        }
        else if(url[i] == ' ') {
            temp[j++] = '+';
        }
        else {
            sprintf(&temp[j], "%%%02X", url[i]);
            j += 3;
        }
    }
    temp[j] = '\0';
    strcpy(url, temp);
    free(temp);
}

// function to check if a given character sequence is a valid URL
int isValidURL(char* url) {
    int i, len;
    len = strlen(url);
    if(len < 5)
        return 0;
    if(strncmp(url, "http:", 5) == 0)
        return 1;
    if(strncmp(url, "https:", 6) == 0)
        return 1;
    if(strncmp(url, "ftp:", 4) == 0)
        return 1;
    return 0;
}

// function to sanitize all URLs in a string recursively
void sanitizeAllURLs(char* str) {
    int i, len, s;
    len = strlen(str);
    char* temp = (char*)malloc(sizeof(char)*(len+1));
    s = 0;
    for(i=0; i<len; i++) {
        if(str[i] == '<') {
            int j;
            for(j=i+1; j<len; j++) {
                if(str[j] == '>') {
                    break;
                }
                else if(str[j] == '"' || str[j] == '\'') {
                    int k;
                    for(k=j+1; k<len; k++) {
                        if(str[k] == str[j]) {
                            break;
                        }
                    }
                    if(k < len) {
                        j = k;
                    }
                }
            }
            if(j < len) {
                int k;
                for(k=s; k<i; k++) {
                    temp[k-s] = str[k];
                }
                temp[k-s] = '<';
                s = j+1;
                i = j;
            }
        }
        else if(str[i] == '"' || str[i] == '\'') {
            int j;
            for(j=i+1; j<len; j++) {
                if(str[j] == str[i]) {
                    break;
                }
            }
            if(j < len) {
                int k;
                for(k=s; k<i; k++) {
                    temp[k-s] = str[k];
                }
                temp[k-s] = str[i];
                s = j+1;
                i = j;
            }
        }
        else if(str[i] == 'h' || str[i] == 'H') {
            if(i+4 < len) {
                char* check = (char*)malloc(sizeof(char)*5);
                strncpy(check, &str[i], 4);
                check[4] = '\0';
                if(isValidURL(check)) {
                    int j;
                    for(j=i+4; j<len; j++) {
                        if(!isalpha(str[j]) && !isdigit(str[j]) && str[j] != ':' && str[j] != '/' && str[j] != '?' && str[j] != '#' && str[j] != '[' && str[j] != ']' && str[j] != '@' && str[j] != '!' && str[j] != '$' && str[j] != '&' && str[j] != '\'' && str[j] != '(' && str[j] != ')' && str[j] != '*' && str[j] != '+' && str[j] != ',' && str[j] != ';' && str[j] != '=' && str[j] != '~') {
                            break;
                        }
                    }
                    if(j <= len) {
                        int k;
                        for(k=s; k<i; k++) {
                            temp[k-s] = str[k];
                        }
                        sanitizeURL(&str[i]);
                        k = i;
                        while(str[k] != '\0' && str[k] != ' ' && str[k] != '\'' && str[k] != '"' && str[k] != '<' && str[k] != '>') {
                            k++;
                        }
                        s = k;
                        i = k-1;
                    }
                }
                free(check);
            }
        }
    }
    int k;
    for(k=s; k<len; k++) {
        temp[k-s] = str[k];
    }
    temp[k-s] = '\0';
    strcpy(str, temp);
    free(temp);
}

int main() {
    char* str = "<p>Check out this <a href=\"http://www.google.com\">Google</a> link</p><p>Here is an <a href='https://www.yahoo.com'>Yahoo!</a> link</p><p>And another <a href=\"javascript:alert('XSS attack!')\">malicious link</a> to be removed</p>";
    printf("Original string: %s\n", str);
    sanitizeAllURLs(str);
    printf("Sanitized string: %s\n", str);
    return 0;
}