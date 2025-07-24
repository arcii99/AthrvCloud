//FormAI DATASET v1.0 Category: String manipulation ; Style: rigorous
#include<stdio.h>
#include<string.h>

int main(){

char string[100]="This is a sample program to test string manipulation in C";
int stringLength= strlen(string);

    //Converting all characters to uppercase
    for(int i=0;i<stringLength;i++){
        if(string[i]>='a' && string[i]<='z'){
            string[i]=string[i]-32;
            
        }
    }

    printf("After converting all characters to uppercase:\n");
    printf("%s\n",string);

    //Finding the number of vowels in the string
    int vowels=0;
    for(int i=0;i<stringLength;i++){
        if(string[i]=='A' || string[i]=='E' || string[i]=='I' || string[i]=='O' || string[i]=='U'){
            vowels++;
        }
    }

    printf("Number of vowels in the string:%d\n",vowels);

    //Replacing all occurrences of 'a' with '$'
    for(int i=0;i<stringLength;i++){
        if(string[i]=='a' || string[i]=='A'){
            string[i]='$';
        }
    }

    printf("After replacing all occurrences of 'a' with '$':\n");
    printf("%s\n",string);

    printf("After splitting the string and printing each word:\n");

    char* token= strtok(string," ");
    while(token!=NULL){
        printf("%s\n",token);
        token = strtok(NULL, " ");
    }

return 0;
}