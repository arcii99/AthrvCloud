//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

void str_replace(char *buffer, char *search, char *replace);
int str_count(char *string, char letter);
int word_count(char *string);

int main(){

    char string[] = "The quick brown fox jumps over the lazy dog.";
    char search[] = "fox";
    char replace[] = "cat";

    printf("Original string: %s\n", string);

    str_replace(string, search, replace);

    printf("Replaced string: %s\n", string);

    printf("Letter count of 'o': %d\n", str_count(string, 'o'));

    printf("Word count: %d\n", word_count(string));

    return 0;
}

void str_replace(char *buffer, char *search, char *replace){

    char* pos = strstr(buffer, search);

    while(pos){
        size_t search_len = strlen(search);
        size_t replace_len = strlen(replace);
        memmove(pos + replace_len, pos + search_len, strlen(pos + search_len) + 1);
        memcpy(pos, replace, replace_len);
        pos = strstr(pos + replace_len, search);
    }
}

int str_count(char *string, char letter){

    int count = 0;

    for(int i = 0; i < strlen(string); i++){
        if(string[i] == letter){
            count++;
        }
    }

    return count;
}

int word_count(char *string){

    int count = 1;

    for(int i = 0; i < strlen(string); i++){
        if(string[i] == ' '){
            count++;
        }
    }

    return count;
}