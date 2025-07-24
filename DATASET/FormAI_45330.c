//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>

void sanitizeUrl(char url[]){
    char temp[strlen(url)]; //create a temporary string to hold the sanitized url
    int i, j;
    int flag = 0; //flag to track whether the url has http or https at the beginning
    
    //loop through each character of the url
    for(i=0; i<strlen(url); i++){
        //if the current character is a space, replace it with %20
        if(url[i]==' '){
            strcat(temp, "%20"); //add %20 to the temporary string
        }
        //if the current character is a forward slash, replace it with a hyphen
        else if(url[i]=='/'){
            strcat(temp, "-"); //add hyphen to the temporary string
        }
        //if the current character is a colon, check if the next characters are "http" or "https"
        else if(url[i]==':'){
            if(url[i+1]=='/' && url[i+2]=='/' && url[i+3]=='w' && url[i+4]=='w' && url[i+5]=='w'){
                flag = 1; //set the flag to 1 if "http" or "https" is found
                strcat(temp, ":"); //add the colon to the temporary string
            }
            else{
                strcat(temp, "-"); //if no valid protocol is found, replace the colon with a hyphen
            }
        }
        //if the current character is not a special character, add it to the temporary string
        else{
            char temp2[2]; //temporary string to hold the current character
            temp2[0] = url[i]; //add the current character to the temporary string
            temp2[1] = '\0'; //terminate the temporary string with null character
            strcat(temp, temp2); //add the temporary string to the main temporary string
        }
    }
    
    //if the flag is still 0, add "https://" to the beginning of the sanitized url
    if(flag==0){
        char final[strlen(temp)+8]; //create a final string to hold the complete sanitized url
        strcpy(final, "https://"); //add "https://" at the beginning of the final string
        strcat(final, temp); //add the sanitized url to the final string
        printf("Sanitized URL: %s\n", final); //print the final sanitized url
    }
    //if the flag is 1, no need to add any protocol at the beginning
    else{
        printf("Sanitized URL: %s\n", temp); //print the sanitized url
    }
}

int main(){
    char url[] = "http://www.example.com/this is a test.html"; //sample url with spaces and forward slashes
    sanitizeUrl(url); //call the function to sanitize the url
    
    char url2[] = "ftp://www.example.com/this/is/another-test"; //sample url with different protocol
    sanitizeUrl(url2); //call the function to sanitize the url
    
    char url3[] = "www.example.com/test with spaces"; //sample url without any protocol
    sanitizeUrl(url3); //call the function to sanitize the url
    
    return 0;
}