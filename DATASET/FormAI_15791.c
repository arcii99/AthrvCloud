//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<pthread.h>

char command[100];
pthread_t tid[2];
int status;


void* run_shell_command(void *arg) {
    pthread_t id = pthread_self();

    if(pthread_equal(id, tid[0])){
        printf("Type exit to exit the shell\n");
        
        do {
            printf("> ");
            fgets(command, sizeof(command), stdin);
            system(command);
        } while (strcmp(command, "exit\n") != 0);
        status = 0;
    }
    else{
        while(status){
            printf("Shell Status Running...\n");
            sleep(1);
        }
    }
}

int main(void) {
    int i = 0;
    status = 1;

    while(i < 2){
        pthread_create(&(tid[i]), NULL, &run_shell_command, NULL);
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    printf("Shell Terminated.\n");
    return 0;
}