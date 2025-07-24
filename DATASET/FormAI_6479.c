//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *sanitize_url(char *url){
    int len = strlen(url);
    char *new_url = (char*) malloc(len + 1);
    if(!new_url){
        printf("Out of memory!\n");
        return NULL;
    }
    char *p = url, *q = new_url;
    int is_first_query_param = 1;
    while(*p != '\0'){
        if(*p == '?'){
            if(is_first_query_param){
                *q = *p;
                q++;
                is_first_query_param = 0;
            }
            else{
                p++;
                continue;
            }
        }
        else if(isalpha(*p) || isdigit(*p) || *p == '.' || *p == '/' 
                || *p == '#' || *p == '&' || *p == ':' || *p == '='){
            *q = tolower(*p);
            q++;
        }
        p++;
    }
    *q = '\0';
    return new_url;
}

int main(){
    char *url = "https://www.example.com?name=John&age=25&search=URL+Sanitizer";
    char *new_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", new_url);
    free(new_url);
    return 0;
}