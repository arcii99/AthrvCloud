//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: automated
#include <stdio.h>
#include <string.h>

void detectIntrusion(char* userInput);

int main(){
    char userInput[100];
    printf("Enter some text: ");
    fgets(userInput, 100, stdin);
    detectIntrusion(userInput);
    return 0;
}

void detectIntrusion(char* userInput){
    char* keywords[] = {"hacker", "attack", "exploit", "malware", "virus", "trojan"};
    int keywordCount = sizeof(keywords)/sizeof(keywords[0]);
    char* delimiters = " .,:;?!()\n";
    char* token;
    token = strtok(userInput, delimiters);
    while(token != NULL){
        for(int i=0; i<keywordCount; i++){
            if(strcmp(token, keywords[i]) == 0){
                printf("Intrusion detected! Suspicious keyword '%s' found in user input.\n", token);
                return;
            }
        }
        token = strtok(NULL, delimiters);
    }
    printf("No potential intrusions detected.\n");
}