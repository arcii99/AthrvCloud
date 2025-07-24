//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  char usage[15], usage2[15], usage3[15]; //strings to hold the RAM usage
  int i = 0; //index for string
  char ch; //character to read from command line output
  FILE *fp; //pointer to file for reading command line output
  
  while(1) { //infinite loop to continuously monitor RAM usage
    fp = popen("free -m | awk 'NR==2{printf \"%s/%sMB (%.2f%%)\", $3,$2,$3*100/$2 }'", "r"); //execute command line command to get RAM usage
    if (fp == NULL) { //if there was an error with the command
      printf("Error: Failed to run command.\n");
      exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) { //while there is still output to read
      if (ch != '\n' && ch != ' ') { //if the character is not a space or newline
        usage[i] = ch; //add the character to the current RAM usage string
        i++; //increment index
      }
    }
    pclose(fp); //close file pointer
    i = 0; //reset index
    
    fp = popen("free -m | awk 'NR==3{printf \"%s/%sMB (%.2f%%)\", $3,$2,$3*100/$2 }'", "r"); //execute command line command to get swap usage
    if (fp == NULL) { //if there was an error with the command
      printf("Error: Failed to run command.\n");
      exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) { //while there is still output to read
      if (ch != '\n' && ch != ' ') { //if the character is not a space or newline
        usage2[i] = ch; //add the character to the current swap usage string
        i++; //increment index
      }
    }
    pclose(fp); //close file pointer
    i = 0; //reset index
    
    fp = popen("vmstat -s | awk 'NR==1{printf \"%sMB\", $1 }'", "r"); //execute command line command to get total available memory
    if (fp == NULL) { //if there was an error with the command
      printf("Error: Failed to run command.\n");
      exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) { //while there is still output to read
      if (ch != '\n' && ch != ' ') { //if the character is not a space or newline
        usage3[i] = ch; //add the character to the current total memory string
        i++; //increment index
      }
    }
    pclose(fp); //close file pointer
    i = 0; //reset index
    
    printf("RAM usage: %s\n", usage); //print current RAM usage
    printf("Swap usage: %s\n", usage2); //print current swap usage
    printf("Total memory: %s\n", usage3); //print total available memory
    sleep(1); //wait one second before checking again
    system("clear"); //clear console window before printing next set of usage data
  }
  return 0; //end program
}