//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void log_event(char *event_type, char *status){
    FILE *fp;
    fp = fopen("log.txt", "a");
    
    if(!fp){
        printf("\nError: Could not log event!");
        return;
    }
    
    fprintf(fp, "%s - %s\n", event_type, status);
    fclose(fp);
}

int main(){
    int attempts = 0;
    
    while(attempts < 3){
        char password[10] = {0};
        printf("\nPlease enter the password: ");
        scanf("%s", password);
        
        if(strcmp(password, "password123") == 0){
            printf("\nAccess granted!\n");
            log_event("LOGIN", "SUCCESS");
            return 0;
        }
        else{
            printf("\nIncorrect password. Please try again.\n");
            log_event("LOGIN", "FAILURE");
            attempts++;
        }
    }
    
    printf("\nYou have exceeded the maximum number of attempts.\n");
    log_event("LOGIN", "MAX ATTEMPTS REACHED");
    
    return 0;
}