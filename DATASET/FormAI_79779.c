//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: detailed
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <ctype.h>  
  
char *keywords[] = {"login", "password", "sudo", "access"}; //list of keywords to search for in input  

void log_in(char *params) {  
    //code to log in user  
}  
  
void execute_command(char *command) {  
    //code to execute command  
}  
  
void detect_intrusion(char *input) {  
    int i, j;  
    
    for(i=0; i<strlen(input); i++) {  
        if(isalpha(input[i])) { //if character is alphabetic  
            char temp[20] = {'\0'};  
            int k = 0;  

            for(j=i; j<strlen(input); j++) {  
                if(isalpha(input[j]))  
                    temp[k++] = input[j];  
                else  
                    break;  
            }  

            for(j=0; j<sizeof(keywords)/sizeof(keywords[0]); j++) {  
                if(!strcasecmp(temp, keywords[j])) {  
                    printf("Intrusion detected: \"%s\" keyword found\n", keywords[j]);  
                    //code to log intrusion  
                }  
            }  
        }  
    }  
}  
  
int main() {  
    printf("Enter command: ");  
    char input[100] = {'\0'};  
    fgets(input, sizeof(input), stdin);  
    input[strlen(input)-1] = '\0'; //removes new line character  
    detect_intrusion(input);  
    execute_command(input);  
    return 0;  
}