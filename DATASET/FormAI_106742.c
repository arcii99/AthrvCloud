//FormAI DATASET v1.0 Category: Data validation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
    char input[10];
    int flag_alpha=0,flag_digit=0,flag_special=0;
    int length,i;
    printf("Enter the string to Validate: ");
    scanf("%s",input);
    length=strlen(input);
    if(length<8||length>20){//Checking length of string
        printf("Length of string should be between 8 to 20 characters\n");
    }
    else{
        for(i=0;i<length;i++){
            if(isalpha(input[i])){//Checking for alphabets
                flag_alpha=1;
            }
            else if(isdigit(input[i])){//Checking for digits
                flag_digit=1;
            }
            else{//Checking for special characters
                flag_special=1;
            }
        }
        if(flag_alpha==1&&flag_digit==1&&flag_special==1){
            printf("String is Valid\n");//String with atleast one Alphabet, one digit and one special character is Valid
        }
        else{
            printf("String is not Valid\n");//If only two or one of three flags is set then String is not valid
        }
    }
    return 0;
}