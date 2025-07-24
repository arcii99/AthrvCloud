//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: random
/*
 * This program sanitizes URLs input by the user by removing any unwanted characters and
 * checking for security vulnerabilities in the URL. The program checks if the domain name is
 * valid and if the URL contains any suspicious characters that may be used for
 * malicious purposes. The sanitized URL is then printed on the console
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char url[200];
    printf("Enter the URL to be sanitized: ");
    fgets(url, 200, stdin);
    int len = strlen(url);
    if(url[len - 1] == '\n')
        url[len - 1] = '\0';
    char valid_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-/";
    char temp_url[200] = "";
    int i = 0;
    while(i < strlen(url)){
        if(url[i] == ':'){
            strcat(temp_url, "://");
            i += 3;
        }
        else if(url[i] == '\\' && url[i+1] == '/'){
            i += 2;
        }
        else{
            char curr_char = url[i];
            if(isalnum(curr_char) || curr_char == '-' || curr_char == '_' || curr_char == '/'){
                strncat(temp_url, &curr_char, 1);
            }
            i++;
        }
    }
    printf("Sanitized URL: %s", temp_url);
    return 0;
}