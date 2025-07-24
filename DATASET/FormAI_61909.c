//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define HISTORY_SIZE 10

int numOfParams(char* line){
    int n = 0;
    for(int i = 0; i < strlen(line); i++){
        if(line[i] == ' '){
            n++;
        }
    }
    return n+1;
}

void clearArgs(char args[MAX_LINE][MAX_LINE], int size){
    for(int i = 0; i < size; i++){
        memset(args[i], '\0', MAX_LINE);
    }
}

void printHistory(char history[HISTORY_SIZE][MAX_LINE], int size){
    for(int i = 0; i < size; i++){
        if(history[i][0] != '\0'){
            printf("%d. %s\n", i+1, history[i]);
        }
    }
}

int main(void){
    char* args[MAX_LINE/2 + 1];
    char history[HISTORY_SIZE][MAX_LINE];
    char line[MAX_LINE];
    int should_run = 1, argSize, historyIdx = 0;

    while (should_run){
        printf("C Shell > ");
        fflush(stdout);
        fgets(line, MAX_LINE, stdin);
        line[strcspn(line, "\n")] = 0;
        if(strcmp(line, "exit") == 0){
            break;
        }
        if(strcmp(line, "history") == 0){
            printHistory(history, HISTORY_SIZE);
            continue;
        }
        argSize = numOfParams(line);
        if(argSize == 0){
            continue;
        }
        char argsBuf[MAX_LINE*(argSize+1)];
        clearArgs(args, argSize);
        strcat(line, " ");
        strcpy(argsBuf, line);
        char* token = strtok(line, " ");
        int i = 0;
        while(token != NULL){
            strcpy(args[i], token);
            token = strtok(NULL, " ");
            i++;
        }
        if(historyIdx >= HISTORY_SIZE){
            historyIdx = 0;
        }
        strcpy(history[historyIdx], argsBuf);
        historyIdx++;

        pid_t pid;
        pid = fork();
        if(pid < 0){
            printf("Fork Failed\n");
            exit(1);
        }
        else if(pid == 0){
            if(execvp(args[0], args) == -1){
                printf("Command Failed\n");
            }
        }
        else{
            wait(NULL);
        }
    }
    return 0;
}