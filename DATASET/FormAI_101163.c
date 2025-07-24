//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//function to remove punctuations from the input string
void remove_punctuations(char *str) {
    for(int i = 0; str[i] != '\0'; ++i) {
        while(!(isalnum(str[i]) || str[i]==' ')) {
            for(int j = i; str[j] != '\0'; ++j) {
                str[j] = str[j+1];
            }
            str[strlen(str)] = '\0';
        }
    }
}

int main() {
    char input_str[100];
    printf("Enter the input string: ");
    fgets(input_str,100,stdin);

    //removing the '\n' character from the input string entered using fgets
    if (input_str[strlen(input_str)-1] == '\n') {
        input_str[strlen(input_str)-1] = '\0';
    }
    
    //removing punctuations from the input string
    remove_punctuations(input_str);

    printf("The input string after removing punctuations: %s\n", input_str);
    return 0;
}