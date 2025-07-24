//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* detect_intrusion(char* input_string){

    int i, len, flag = 0;
    char *intrusion_msg = "No intrusion detected!";

    len = strlen(input_string);

    for(i = 0; i < len - 2; i++){ // Checking for potential malicious inputs

        if(input_string[i] == 'p' && input_string[i+1] == 's' && input_string[i+2] == 'e'){
            intrusion_msg = "Intrusion detected! Potential SQL injection attack!"; // SQL injection detected
            flag = 1;
            break;
        }
        else if(input_string[i] == '<' && input_string[i+1] == 's' && input_string[i+2] == 'c'){
            intrusion_msg = "Intrusion detected! Potential XSS attack!"; // Cross-site scripting attack detected
            flag = 1;
            break;
        }
        else if(input_string[i] == ';' && input_string[i+1] == ' ' && input_string[i+2] == 'r'){
            intrusion_msg = "Intrusion detected! Potential Remote Code Execution attack!"; // Remote code execution attack detected
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        len = strlen(input_string);
        for(i = 0; i < len; i++){ // Checking for other potential malicious inputs
            if(input_string[i] == '(' || input_string[i] == ')' || input_string[i] == '{' || 
               input_string[i] == '}' || input_string[i] == '|' || input_string[i] == '&'){
                intrusion_msg = "Intrusion detected! Potential Command Injection or Code Injection attack!"; // Code injection attack detected
                flag = 1;
                break;
            }
        }
    }

    if(flag == 0){ // Checking for potential buffer overflow attacks
        char buffer[10];
        strcpy(buffer, input_string);
        intrusion_msg = "No intrusion detected!";
    }

    return intrusion_msg;
}

int main(){

    char input_string[100];

    printf("Enter the input string: ");
    scanf("%[^\n]s", input_string);

    char* result = detect_intrusion(input_string);

    printf("%s\n", result);

    return 0;
}