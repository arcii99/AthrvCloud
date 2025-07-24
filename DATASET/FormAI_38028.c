//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 1000

char* sanitize_url(char* url) {
    char* sanitized_url = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    int sanitized_index = 0;
    
    for (int i = 0; i < strlen(url); i++) {
        char current_char = url[i];
        
        if (current_char == ' ') {
            sanitized_url[sanitized_index++] = '+';
        }
        else if ((current_char >= 'A' && current_char <= 'Z') || 
            (current_char >= 'a' && current_char <= 'z') || 
            (current_char >= '0' && current_char <= '9') || 
            current_char == '.' || current_char == '-' || current_char == '_' || current_char == '~') {
            
            sanitized_url[sanitized_index++] = current_char;
        }
        else {
            sanitized_index += sprintf(sanitized_url + sanitized_index, "%%%02X", current_char);
        }
    }
    
    sanitized_url[sanitized_index] = '\0';
    
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH] = "https://www.example.com/My First File.html?argument1=value1&argument2=value 2";
    
    char* sanitized_url = sanitize_url(url);
    
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    
    free(sanitized_url);
    
    return 0;
}