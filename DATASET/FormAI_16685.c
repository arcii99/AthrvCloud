//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: creative
#include<stdio.h>
#include<string.h>

void sanitizeURL(char *url){
    int i, j;
    char temp[strlen(url)+1];
    for(i=0,j=0;i<strlen(url);i++){
        if(url[i]==' ' || url[i]=='\''){
            temp[j]='+';
            j++;
        }
        else if(url[i]=='<' || url[i]=='>'){
            temp[j]='-';
            j++;
        }
        else if(url[i]=='^' || url[i]=='~'){
            temp[j]='*';
            j++;
        }
        else if(url[i]==';' || url[i]=='`'){
            temp[j]=':';
            j++;
        }
        else{
            temp[j]=url[i];
            j++;
        }
    }
    temp[j]='\0';
    strcpy(url,temp);
}

int main(){
    char url[1000];
    printf("Enter a URL to sanitize:\n");
    fgets(url,1000,stdin);
    sanitizeURL(url);
    printf("The sanitized URL is: %s",url);
    return 0;
}