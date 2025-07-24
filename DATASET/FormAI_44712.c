//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int i;
    printf("Welcome to the C String Manipulation Program!\n");
    printf("Please enter a string:\n");
    scanf("%s", str);
    printf("You entered: %s\n", str);
    printf("The length of your string is: %d\n", strlen(str));
    printf("The reversed string is: ");
    for(i=strlen(str)-1;i>=0;i--){
        printf("%c", str[i]);
    }
    printf("\n");
    printf("The uppercase string is: ");
    for(i=0;i<strlen(str);i++){
        printf("%c", toupper(str[i]));
    }
    printf("\n");
    printf("The lowercase string is: ");
    for(i=0;i<strlen(str);i++){
        printf("%c", tolower(str[i]));
    }
    printf("\n");
    printf("The substring 'manipulation' occurs at index: %d\n", strstr(str,"manipulation")-str);
    printf("The character 'e' occurs at index: %d\n", strchr(str,'e')-str);
    printf("The string 'C String' occurs at index: %d\n", strstr(str,"C String")-str);
    printf("The string after removing the first 3 characters is: %s\n", str+3);
    printf("The string after removing the last 2 characters is: ");
    str[strlen(str)-2]='\0';
    printf("%s\n", str);
    printf("Thank you for using the C String Manipulation Program!\n");
    return 0;
}