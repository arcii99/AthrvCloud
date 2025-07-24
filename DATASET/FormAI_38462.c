//FormAI DATASET v1.0 Category: System administration ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]) {

  int option;
  char command[100];

  while ((option = getopt(argc, argv, "a:b:")) != -1) { //taking command line arguments
    switch (option) {
      case 'a':
        if(strcmp(optarg,"memory")==0){ //checking if user wants to check memory usage
          printf("Current memory usage is:\n");
          system("free -m");
        }
        else if(strcmp(optarg,"process")==0){ //checking if user wants to check running processes
          printf("List of running processes:\n");
          system("ps aux");
        }
        else{
          printf("Unknown argument\n");
        }
        break;
        
      case 'b':
        if(strcmp(optarg,"start")==0){ //checking if user wants to start a service
          printf("Which service do you want to start?\n");
          scanf("%s",command);
          sprintf(command,"systemctl start %s.service",command); //creating command string to start the service
          system(command);
        }
        else if(strcmp(optarg,"stop")==0){ //checking if user wants to stop a service
          printf("Which service do you want to stop?\n");
          scanf("%s",command);
          sprintf(command,"systemctl stop %s.service",command); //creating command string to stop the service
          system(command);
        }
        else if(strcmp(optarg,"restart")==0){ //checking if user wants to restart a service
          printf("Which service do you want to restart?\n");
          scanf("%s",command);
          sprintf(command,"systemctl restart %s.service",command); //creating command string to restart the service
          system(command);
        }
        else{
          printf("Unknown argument\n");
        }
        break;

      case '?':
        printf("Unknown option\n");
        break;
    }
  }

  return 0;
}