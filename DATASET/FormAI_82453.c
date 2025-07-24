//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include<stdio.h>
#include<string.h>

int main(){
    char C_cat_language[] = "Meow purr purr meow hiss";
    char english_language[] = "";
    
    printf("C Cat Language: %s\n", C_cat_language);
    
    char* token = strtok(C_cat_language, " ");
    
    while(token != NULL){
        
        if(strcmp(token, "Meow") == 0){
            strcat(english_language, "Hello ");
        }
        
        else if(strcmp(token, "purr") == 0){
            strcat(english_language, "Good ");
        }
        
        else if(strcmp(token, "hiss") == 0){
            strcat(english_language, "Bye ");
        }
        
        else{
            strcat(english_language, " ");
        }
        
        token = strtok(NULL, " ");
    }
    
    printf("English Language: %s\n", english_language);
    
    return 0;
}