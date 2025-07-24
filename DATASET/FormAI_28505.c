//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_HISTORY_LENGTH 10

char history[MAX_HISTORY_LENGTH][MAX_COMMAND_LENGTH];
int history_count = 0;

void* execute_command(void* cmd);

int main() {
    pthread_t thread;
    char command[MAX_COMMAND_LENGTH];
    printf("Unix-like Shell\n");
    
    while(1) {
        printf(">> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // remove newline character
        
        strcpy(history[history_count], command);
        history_count = (history_count + 1) % MAX_HISTORY_LENGTH;
        
        if(strcmp(command, "exit") == 0) {
            printf("Exiting Shell...\n");
            break;
        } else if(strcmp(command, "history") == 0) {
            printf("Command History:\n");
            for(int i = 0; i < MAX_HISTORY_LENGTH; i++) {
                printf("%d. %s\n", i+1, history[i]);
            }
        } else {
            pthread_create(&thread, NULL, execute_command, (void*) command);
            pthread_join(thread, NULL);
        }
    }

    return 0;
}

void* execute_command(void* cmd) {
    printf("Executing Command: %s\n", (char*) cmd);
    system((char*) cmd);
    return NULL;
}