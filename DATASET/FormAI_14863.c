//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int is_alpha_num(char ch){
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
        return 1;
    }
    return 0;
}

void add_http(char *url){
    char https[10] = "https://";
    char http[10] = "http://";
    char *start_with = &(*url);
    if(strncmp(start_with, https, 8) != 0 && strncmp(start_with, http, 7) != 0) {
        char temp[50] = "http://";
        strcat(temp, url);
        strcpy(url, temp);
    }
}

void sanitize_url(char *url) {
    char *sanitized_url;
    int i = 0, j = 0;
    while(url[i]){
        if(is_alpha_num(url[i]) || url[i] == ':' || url[i] == '/' || url[i] == '.'){
            sanitized_url[j++] = url[i];
            if(url[i] == ':'){
                add_http(sanitized_url);
            }
        }
        i++;
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
}

int main(){
    char url[1000] = "example.com/?<><>\\&quot";
    printf("Original URL:\n%s\n", url);
    sanitize_url(url);
    printf("Sanitized URL:\n%s\n", url);
    return 0;
}