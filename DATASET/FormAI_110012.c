//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function to check if a character is alphanumeric or not
int is_alphanumeric(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

//function to sanitize the URL by removing all non-alphanumeric characters except '/'
char* sanitize_url(char* input_url){
    int len = strlen(input_url);
    char* output_url = (char*)malloc((len+1)*sizeof(char)); //allocate memory for output url
    int j = 0;
    for(int i=0; i<len; i++){
        if(input_url[i]=='/') //allow '/'
            output_url[j++] = input_url[i];
        else if(is_alphanumeric(input_url[i])) //allow only alphanumeric characters
            output_url[j++] = input_url[i];
    }
    output_url[j] = '\0'; //add null character at the end
    return output_url;
}

int main(){
    //test cases
    char* test_url_1 = "http://www.example.com/index.html?id=1&name=john"; //should become http://www.example.com/index.htmlid1namejohn
    char* test_url_2 = "https://www.google.com/search?q=programming"; //should become https://www.google.com/searchqprogramming
    char* test_url_3 = "ftp://ftp.example.com/important_document.pdf"; //should become ftp://ftp.example.com/important_document.pdf

    //sanitize URLs and print them
    printf("Sanitized URL 1: %s\n", sanitize_url(test_url_1));
    printf("Sanitized URL 2: %s\n", sanitize_url(test_url_2));
    printf("Sanitized URL 3: %s\n", sanitize_url(test_url_3));

    return 0;
}