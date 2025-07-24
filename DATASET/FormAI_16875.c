//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include<stdio.h>
#include<string.h>

void recurseStr(char* str, int i){
    // base condition: if we reach the end of the string
    if(str[i] == '\0') return;
    
    // recursive call to print the input string in reverse order
    recurseStr(str, i+1);
    
    // print the current character
    printf("%c", str[i]);
}

int main(){
    char str[100];
    
    // take user input of a string
    printf("Enter a string: ");
    scanf("%s", str);
    
    // call the recursive function to print the input string in reverse order
    recurseStr(str, 0);
    
    return 0;
}