//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: futuristic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// future tech used to sanitize a URL
char* sanitize(char* url){
    int len = strlen(url);
    int flag = 0;
    char* temp = (char*)malloc(len * sizeof(char));
    int j=0;
    for(int i=0; i<len; i++)
    {
        if(url[i] == '.' && flag==0)
        {
            temp[j++] = url[i];
            flag = 1;
        }
        else if((url[i]>='a' && url[i]<='z') || (url[i]>='A' && url[i]<='Z') || (url[i]>='0' && url[i]<='9') || url[i]=='.' || url[i]=='-' || url[i]=='/' || url[i]==':' || url[i]=='?' || url[i]=='=')
        {
            temp[j++] = url[i];
            flag=0;
        }
    }
    temp[j] = '\0';
    return temp;
}

int main()
{
    printf("Welcome to unique URL Sanitizer!\n");
    printf("Please enter a URL to sanitize: \n");
    char url[100];
    scanf("%s", url);
    char* sanitized_url = sanitize(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    printf("Thank you for using unique URL Sanitizer!\n");
    return 0;
}