//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include<stdio.h>
#include<string.h>

int detectDangers(char inputStr[]){
    // detects the presence of keywords that may indicate danger
    if(strstr(inputStr, "attack") || strstr(inputStr, "destroy") || strstr(inputStr, "kill")){
        return 1;
    }
    else if(strstr(inputStr, "infiltrate") || strstr(inputStr, "subvert") || strstr(inputStr, "sabotage")){
        return 2;
    }
    else{
        return 0;
    }
}

void translateToEnglish(char inputStr[]){
    // translates alien language to English
    if(strstr(inputStr, "xenob")){
        printf("Enemy");
    }
    else if(strstr(inputStr, "nmkldh")){
        printf("Alliance");
    }
    else if(strstr(inputStr, "thrvk")){
        printf("Planet");
    }
    else if(strstr(inputStr, "vgsfr")){
        printf("Spaceship");
    }
    else{
        printf("Unknown word: %s", inputStr);
    }
}

int main(){
    char alienStr[100];
    printf("Enter Alien Language: ");
    fgets(alienStr, 100, stdin);

    // check for danger keywords
    int dangerLevel = detectDangers(alienStr);
    if(dangerLevel > 0){
        printf("WARNING: Possible threat detected.\n");
    }
    if(dangerLevel == 1){
        printf("ACTION: Initiate defensive protocol.\n");
    }
    else if(dangerLevel == 2){
        printf("ACTION: Initiate covert operation.\n");
    }

    // translate to English
    printf("Translation: ");
    char *token = strtok(alienStr, " ");
    while(token != NULL){
        translateToEnglish(token);
        token = strtok(NULL, " ");
    }
    return 0;
}