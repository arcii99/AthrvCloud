//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
//Hooray! It's time to demonstrate a happy, unique C Interprocess Communication example!!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
   printf("Welcome to the happiest interprocess communication program ever!\n\n");

   //creating shared memory
   key_t shm_key = ftok("shmfile",65);
   int shm_id = shmget(shm_key,1024,0666|IPC_CREAT);
   char *shm_addr = (char*) shmat(shm_id,(void*)0,0);

   //forking to create child process
   pid_t pid = fork();

   if (pid == -1) { //error handling
      printf("Oops! Something went wrong. Couldn't create child process.\n");
      exit(1);
   }

   if (pid == 0) {  //child process
      printf("Hello from the child process! I have just received a happy message: %s\n",shm_addr);
      sprintf(shm_addr,"Yay! I got a message from my sibling process!");
      printf("Child process sending a happy message back to parent process!\n");
      printf("Mission accomplished, peace out!\n");
      exit(0);
   }

   else {  //parent process
      printf("Hello from the parent process! I am sending a happy message to my child process...\n");
      sprintf(shm_addr,"Hello my dear child! I hope you're having a great day!");
      wait(NULL);
      printf("Parent process received a happy message from child process: %s\n",shm_addr);
      printf("Mission accomplished, peace out!\n");
   }

   //detaching shared memory
   shmdt(shm_addr);
   shmctl(shm_id,IPC_RMID,NULL);

   return 0;
}