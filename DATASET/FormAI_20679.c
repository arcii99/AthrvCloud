//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void urlSanitizer(char *url){
    int i, j;
    char temp[strlen(url)+1];
    char *punc = "~()'.!*_-";
    for(i=0, j=0; url[i]!='\0'; i++){
        if(!isspace(url[i])){
            temp[j] = url[i]; 
            j++; 
        }
    }
    temp[j] = '\0';
    strcpy(url,temp);
    for(i = 0, j = 0; url[i]!='\0'; i++, j++){
        while(strchr(punc, url[i])!=NULL && url[i+1]!='\0'){ 
            temp[j] = '%'; 
            j++; 
            sprintf(&temp[j], "%02X", url[i]); 
            j+=2; 
            i++; 
        }
        temp[j] = url[i];
    }
    temp[j] = '\0';
    strcpy(url,temp);
}
 
int main(int argc, char *argv[]){
    if(argc<2){
        printf("Error: no URL provided.\n");
        return 1;
    }
    char *url = argv[1];
    printf("Input URL: %s\n",url);
    urlSanitizer(url);
    printf("Output URL: %s\n",url);
    return 0;
}