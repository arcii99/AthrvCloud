//FormAI DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define ARSZ 100

int main(){

    pid_t pid;
    int shmid, fd1[2], fd2[2], sz;
    char *shm, *s, buff[ARSZ];

    if((shmid = shmget(IPC_PRIVATE, ARSZ*sizeof(int), IPC_CREAT|0666))<0){
        perror("shmget");
        exit(1);
    }

    if(pipe(fd1) == -1){
        perror("pipe 1");
        exit(EXIT_FAILURE);
    }

    if(pipe(fd2) == -1){
        perror("pipe 2");
        exit(EXIT_FAILURE);
    }

    switch(pid=fork()){
        case -1: perror("fork");
                 exit(1);
        case 0: close(fd1[1]);
                close(fd2[0]);

                if((shm = shmat(shmid, NULL, 0))==(char *)-1){
                    perror("shmat");
                    exit(1);
                }

                while(1){
                    if(read(fd1[0], buff, ARSZ) > 0){
                        if(strncmp(buff, "stop", 4) == 0){
                            shmdt(shm);
                            exit(0);
                        }
                        sprintf(shm, "%s", buff);
                        sprintf(buff, "%s", "");

                        write(fd2[1], "received", 8);
                    }
                }

        default: close(fd1[0]);
                 close(fd2[1]);

                 printf("Enter message: ");

                 while(fgets(buff, ARSZ, stdin) != NULL){
                   
                     write(fd1[1], buff, strlen(buff));
                     usleep(100);

                     read(fd2[0], buff, ARSZ);

                     printf("%s\nEnter message: ", buff);
                 }
                 strcpy(buff, "stop");
                 write(fd1[1], buff, strlen(buff));
                 wait(NULL);
    }


    return 0;
}