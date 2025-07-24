//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

//Structure to hold XML tag data
struct XMLTag{
    char name[MAX_SIZE];
    char attributes[MAX_SIZE];
};

//Function to extract the XML tag name from a given string
void getTagName(char* str, int* index, char* tagName){
    int i=0;
    while(str[*index]!=' ' && str[*index]!='>' && str[*index]!='\0'){
        tagName[i++]=str[(*index)++];
    }
    tagName[i]='\0';
}

//Function to extract the XML tag attributes from a given string
void getAttributes(char* str, int* index, char* attributes){
    int i=0;
    while(str[*index]!='>' && str[*index]!='\0'){
        attributes[i++]=str[(*index)++];
    }
    attributes[i]='\0';
}

//Function to parse the XML string and extract the tags and attributes
void parseXML(char* xmlString, struct XMLTag* tagArray, int* tagCount){
    int index=0, i=0;
    char tagName[MAX_SIZE], attributes[MAX_SIZE];
    
    while(xmlString[index]!='\0'){
        //Ignore whitespace characters
        if(xmlString[index]==' ' || xmlString[index]=='\t' || xmlString[index]=='\n'){
            index++;
            continue;
        }
        //If opening tag is encountered
        if(xmlString[index]=='<' && xmlString[index+1]!='/'){
            index++;
            //Get the tag name
            getTagName(xmlString, &index, tagName);
            strcpy(tagArray[i].name, tagName);
            //Get the tag attributes
            getAttributes(xmlString, &index, attributes);
            strcpy(tagArray[i].attributes, attributes);
            i++;
            (*tagCount)++;
        }
        //If closing tag is encountered
        else if(xmlString[index]=='<' && xmlString[index+1]=='/'){
            index+=2;
            while(xmlString[index]!='>'){
                index++;
            }
        }
        //If it's just a text node, ignore it
        else{
            index++;
        }
    }
}

//Function to print the extracted tags and their attributes
void printTags(struct XMLTag* tagArray, int tagCount){
    printf("\nParsed tags:\n");
    for(int i=0; i<tagCount; i++){
        printf("Tag name: %s\n", tagArray[i].name);
        printf("Tag attributes: %s\n", tagArray[i].attributes);
    }
}

int main(){
    char xmlString[MAX_SIZE] = "<bookstore>\n<book category=\"cooking\">\n<title lang=\"en\">Everyday Italian</title>\n<author>Giada De Laurentiis</author>\n<year>2005</year>\n<price>30.00</price>\n</book>\n<book category=\"children\">\n<title lang=\"en\">Harry Potter</title>\n<author>J.K. Rowling</author>\n<year>2005</year>\n<price>29.99</price>\n</book>\n<book category=\"web\">\n<title lang=\"en\">Learning XML</title>\n<author>Erik T. Ray</author>\n<year>2003</year>\n<price>39.95</price>\n</book>\n</bookstore>\n";
    struct XMLTag tagArray[MAX_SIZE];
    int tagCount=0;
    
    parseXML(xmlString, tagArray, &tagCount);
    
    printTags(tagArray, tagCount);
    
    return 0;
}