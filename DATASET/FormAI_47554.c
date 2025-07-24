//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000        //Maximum size of input text
#define WORD_LENGTH 100 //Maximum length of each word in the text

char* capitalize(char* word) {  //Function to capitalize first letter of a word
    word[0] = word[0] >= 'a' && word[0] <= 'z' ? word[0] - 32 : word[0];
    return word;
}

int main() {
    char text[MAX], temp[MAX], word[WORD_LENGTH];  //Initializing all the variables
    int i, j, k, n, len;
    char delim[] = " ,.:?!;\n\r\t\v\f";  //Initializing the delimiters

    printf("Enter the text: ");
    fgets(text, MAX, stdin);  //Getting input from user

    n = strlen(text);  //Finding the length of the input text

    for(i = 0; i < n; i++) {   //Removing all the extra spaces in the text
        if(text[i] == ' ' && text[i + 1] == ' ') {
            for(j = i; j < n; j++) {
                text[j] = text[j + 1];
            }
        }
    }

    strcpy(temp, text);  //Copying original text to a temporary variable
    len = strlen(temp);

    printf("\n*************************************\n");

    printf("Processed Text:\n\n");

    for(i = 0, j = 0; i <= len; i++) {  //Processing text word by word
        if(text[i] == '*' && text[i + 1] == '*') {   //Checking for bold formatting
            printf("\033[1m");   //Setting bold attribute
            i += 2;
            while(text[i] != '*' || text[i + 1] != '*') {
                printf("%c", text[i]);
                i++;
            }
            printf("\033[0m");   //Removing the bold attribute
            i += 1;
        }
        else if(text[i] == '_' && text[i + 1] == '_') {  //Checking for underline formatting
            printf("\033[4m");   //Setting underline attribute
            i += 2;
            while(text[i] != '_' || text[i + 1] != '_') {
                printf("%c", text[i]);
                i++;
            }
            printf("\033[0m");
            i += 1;
        }
        else if(text[i] == '`' && text[i + 1] == '`') {  //Checking for code formatting
            printf("\033[7m");  //Setting background color to reverse
            i += 2;
            while(text[i] != '`' || text[i + 1] != '`') {
                printf("%c", text[i]);
                i++;
            }
            printf("\033[0m");
            i += 1;
        }
        else if(text[i] == '\n' || text[i] == '\r' || i == len) {   //Formating the paragraphs
            if(j > 0) {
                printf("\n\n");
            }
            j++;
        }
        else if(strchr(delim, text[i])) {
            if(strcmp(word, "") != 0 && word[0] != ' ') {  //Capitalizing the first letter of a word
                printf("%s ", capitalize(word));
            }
            strcpy(word, "");   //Clearing the word buffer
        }
        else {
            strncat(word, &text[i], 1);  //Concatenating each character to the word buffer
        }
    }

    return 0;
}