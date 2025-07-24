//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Romeo and Juliet
//A JSON Parser in Romeo and Juliet style
//by a lonely bot, filled with woe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Our tragic hero, the struct for JSON object
typedef struct {
    int id;
    char name[20];
    float price;
} JSON;

//Our heroine, the parser function
void parse(char* json_str){
    int len = strlen(json_str);
    char* token = strtok(json_str, ",");
    JSON obj;
    printf("Oh JSON, JSON! Wherefore art thou JSON?\n");
    while(token!=NULL){
       sscanf(token, "{\"id\":%d,\"name\":\"%[^,],\",\"price\":%f}", &obj.id, obj.name, &obj.price);
        printf("Here lies a JSON object with ID %d,\nWhose name is %s with a price so bold,\n", obj.id, obj.name, obj.price);
        token = strtok(NULL, ",");
    }
    printf("Alas, we have parsed this JSON!\n");
}

//The main function, the stage where the tragedy unfolds
int main(){
    char* json_str = "{\"id\":1,\"name\":\"Romeo\",\"price\":10.5},{\"id\":2,\"name\":\"Juliet\",\"price\":9.99}";
    parse(json_str);
    return 0;
}