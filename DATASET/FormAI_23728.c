//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complete
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
  
char possible_attack[] = "ATK"; 

void detect_intrusion(char *command) 
{ 
    char attack[4]; 
    int i; 
  
    for(i = 0; i < strlen(command) - 2; i++) 
    { 
        strncpy(attack, command + i, 3); 
        attack[3] = '\0'; 
  
        if(strcmp(attack, possible_attack) == 0) 
        { 
            printf("Intrusion detected!\n"); 
            exit(0); 
        } 
    } 
} 
  
int main() 
{ 
    char command[100]; 
    printf("Enter the command:\n"); 
    scanf("%[^\n]s", command); 
    detect_intrusion(command); 
    printf("Command Executed Successfully\n"); 
    return 0; 
}