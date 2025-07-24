//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

/*Function to get the next character from the string*/
char getNextCharacter(char* jsonString, int* index){
    return jsonString[(*index)++]; 
}

/*Function to parse the JSON string*/
void parseJsonString(char* jsonString){
    int index = 0;
    char c = getNextCharacter(jsonString, &index);
    while(c){
        if(isspace(c)){
            // Do nothing, it is a space
        }
        else if(c == '{'){
            printf("{\n");
        }
        else if(c == '['){
            printf("[\n");
        }
        else if(c == '}'){
            printf("}\n");
        }
        else if(c == ']'){
            printf("]\n");
        }
        else if(c == ':'){
            printf(": ");
        }
        else if(c == ','){
            printf(",\n");
        }
        else if(c == '\"'){
            printf("\"");
            char nextChar = getNextCharacter(jsonString, &index);
            while(nextChar && nextChar != '\"'){
                printf("%c", nextChar);
                nextChar = getNextCharacter(jsonString, &index);
            }
            printf("\"");
        }
        else if(isdigit(c) || c == '-'){
            char num[MAX];
            int i = 0;
            num[i++] = c;
            c = getNextCharacter(jsonString, &index);
            while(c && (isdigit(c) || c == '.')){
                num[i++] = c;
                c = getNextCharacter(jsonString, &index);
            }
            num[i] = '\0';
            printf("%s", num);
            index--;
        }
        c = getNextCharacter(jsonString, &index);
    }
}

/*Main function*/
int main(){
    char* jsonString = "{\"name\":\"John Doe\",\"age\":25,\"city\":\"New York\"}";
    parseJsonString(jsonString);
    return 0;
}