//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

//Function to check if a character is a valid alphabet or not
int isAlphabet(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to check if a character is a valid digit or not
int isDigit(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to check if a character is a valid special symbol or not
int isSpecialSymbol(char c){
    if(c == '<' || c == '>' || c == '/' || c == '"' || c == '='){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to check if a given string is a valid XML tag or not
int isTag(char* tag){
    int i;
    for(i=0; i<strlen(tag); i++){
        if(!isAlphabet(tag[i]) && !isDigit(tag[i]) && !isSpecialSymbol(tag[i])){
            return 0;
        }
    }
    return 1;
}

//Function to parse a given XML document
void parseXML(char* xml){
    int i, j, k, isAttributeStarted = 0, isTagStarted = 0, isValueStarted = 0;
    char temp[MAX_SIZE], tag[MAX_SIZE], attribute[MAX_SIZE], value[MAX_SIZE];
    for(i=0; i<strlen(xml); i++){
        //check if a tag is started
        if(xml[i] == '<' && !isAttributeStarted){
            isTagStarted = 1;
            k = 0;
        }
        //check if an attribute is started
        else if(xml[i] == ' ' && isTagStarted){
            isAttributeStarted = 1;
            k = 0;
        }
        //check if a value is started
        else if(xml[i] == '"' && isAttributeStarted && !isValueStarted){
            isValueStarted = 1;
            k = 0;
        }
        //check if an attribute or value is ended
        else if((xml[i] == '"' || xml[i] == ' ') && isValueStarted){
            isAttributeStarted = 0;
            isValueStarted = 0;
            printf("Attribute: %s, Value: %s\n", attribute, value);
            memset(attribute, 0, sizeof(attribute)); //clear the attribute array
            memset(value, 0, sizeof(value)); //clear the value array
            k = 0;
        }
        else if(xml[i] == '>' && isTagStarted){
            isTagStarted = 0;
            if(!isTag(temp)){ //check if the tag is valid or not
                printf("Invalid Tag: %s\n", temp);
                memset(temp, 0, sizeof(temp)); //clear the temp array
            }
            else{
                strcpy(tag, temp); //copy the tag to the tag array
                memset(temp, 0, sizeof(temp)); //clear the temp array
            }
        }
        //store the characters in temporary arrays based on the parsing rules
        else if(isTagStarted || isValueStarted || isAttributeStarted){
            temp[k++] = xml[i];
        }
    }
}

int main(){
    char xml[] = "<person name=\"John Doe\" age=\"45\"></person>";
    parseXML(xml);
    return 0;
}