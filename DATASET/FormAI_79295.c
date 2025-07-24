//FormAI DATASET v1.0 Category: Data validation ; Style: sophisticated
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int isNumber(char *str){
    int i, n = strlen(str);
    for(i=0 ; i<n ; i++){
        if(!isdigit(str[i])){
            return 0;
        }
    }
    return 1;
}

int main(){
    char name[20], age[3], contact[12];
    int valid = 1;
    
    printf("Enter your name: ");
    scanf("%s", name);
    if(!isalpha(name[0])){
        valid = 0;
    }
    
    printf("Enter your age: ");
    scanf("%s", age);
    if(!isNumber(age)){
        valid = 0;
    }
    
    printf("Enter your contact number: ");
    scanf("%s", contact);
    if(!isNumber(contact) || strlen(contact)!=10){
        valid = 0;
    }
    
    if(valid){
        printf("\nValid Input!\n");
        printf("Name: %s\n", name);
        printf("Age: %s\n", age);
        printf("Contact: %s\n", contact);
    }else{
        printf("\nInvalid Input!\n");
    }
    return 0;
}