//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>

//Function that checks if a given character is a special character
int isSpecialChar(char c){
    char specialChars[] = {'<', '>', '&', '\'', '\"', '#'};

    for(int i = 0; i < 6; i++){
        if(c == specialChars[i]){
            return 1;
        }
    }

    return 0;
}

//Function to sanitize a given URL by removing special characters and replacing them with their respective HTML entity codes
char* sanitizeURL(char* url){
    int length = strlen(url);
    char result[length*6];
    int index = 0;

    for(int i = 0; i < length; i++){
        if(isSpecialChar(url[i])){
            if(url[i] == '<'){
                result[index++] = '&';
                result[index++] = 'l';
                result[index++] = 't';
                result[index++] = ';';
            }
            else if(url[i] == '>'){
                result[index++] = '&';
                result[index++] = 'g';
                result[index++] = 't';
                result[index++] = ';';
            }
            else if(url[i] == '&'){
                result[index++] = '&';
                result[index++] = 'a';
                result[index++] = 'm';
                result[index++] = 'p';
                result[index++] = ';';
            }
            else if(url[i] == '\''){
                result[index++] = '&';
                result[index++] = '#';
                result[index++] = '3';
                result[index++] = '9';
                result[index++] = ';';
            }
            else if(url[i] == '\"'){
                result[index++] = '&';
                result[index++] = '#';
                result[index++] = '3';
                result[index++] = '4';
                result[index++] = ';';
            }
            else if(url[i] == '#'){
                result[index++] = '&';
                result[index++] = '#';
                result[index++] = '3';
                result[index++] = '5';
                result[index++] = ';';
            }
        }
        else{
            result[index++] = url[i];
        }
    }

    result[index] = '\0';

    return result;
}

int main(){
    char url[] = "<script>alert('Hello World')</script>";
    char* sanitizedURL = sanitizeURL(url);

    printf("Sanitized URL: %s\n", sanitizedURL);

    return 0;
}