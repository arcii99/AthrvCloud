//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

int is_in_attack_mode = FALSE;

void alert(char* message) {
    if(is_in_attack_mode) {
        printf("INTRUSION!!! %s\n", message);
        exit(1);
    } else {
        printf("ALERT!!! %s\n", message);
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    while(TRUE) {
        printf("Please enter a command:\n");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        if(strncmp(buffer, "attack", strlen("attack")) == 0) {
            is_in_attack_mode = TRUE;
            printf("Attack mode enabled!\n");
        } else if(strncmp(buffer, "defend", strlen("defend")) == 0) {
            is_in_attack_mode = FALSE;
            printf("Attack mode disabled!\n");
        } else if(strncmp(buffer, "exit", strlen("exit")) == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            alert("Unknown command entered!");
        }
    }
    
    return 0;
}