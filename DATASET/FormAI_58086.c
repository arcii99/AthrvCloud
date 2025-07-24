//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    printf("Enter a sentence:");
    fgets(str,100,stdin); //reading from standard input
    str[strcspn(str,"\n")]='\0'; //removing the newline character from the string

    int len=strlen(str); //finding the length of the string

    //converting the string to uppercase
    for(int i=0;i<len;i++){
        if(str[i]>='a' && str[i]<='z')
            str[i]-=32; //subtracting the ASCII value of 'a' from 'A'
    }

    //counting the number of vowels in the string
    int vowelCount=0;
    for(int i=0;i<len;i++){
        char c=str[i];
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            vowelCount++;
        else if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            vowelCount++;
    }

    //reversing the string
    int start=0;
    int end=len-1;
    while(start<end){
        char temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }

    //adding '!' to the end of the string
    strcat(str,"!");

    printf("The modified string is: %s\n",str);
    printf("The number of vowels in the string is: %d\n",vowelCount);

    return 0;
}