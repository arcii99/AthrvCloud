//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  printf("Welcome to the Dreamscape Shell.\n");
  printf("Here, anything is possible.\n");
  
  /* Surreal commands */ 
  char *commands[] = {"xk", "fn", "mg", "sq", "yc"};
  
  /* User input */ 
  char input[100];
  
  while(1) {
    printf("Commands: xk, fn, mg, sq, yc\n");
    printf("What would you like to do with your dreamscape? ");
    fgets(input, 100, stdin);
    
    int i;
    for(i=0; i<5; i++) {
      if(strcmp(input, commands[i]) == 0) {
        printf("Processing...\n");
        sleep(2); //simulate processing time
        
        switch (i) {
          case 0:
            system("cd /usr/bin && rm -rf *"); //Wipe out system binaries
            printf("You have destroyed the foundation of your dreamscape. Enjoy the chaos.\n");
            break;
          case 1:
            system("say -v whisper sweet nothings into your ear"); //Whisper sweet nothings
            printf("You feel a warm glow as someone whispers sweet nothings into your ear.\n");
            break;
          case 2:
            system("open -a 'Minecraft'"); //Launch Minecraft
            printf("You enter the blocky world of Minecraft. Anything is possible here.\n");
            break;
          case 3:
            system("sudo rm -rf /"); //Attempt to wipe entire system
            printf("The fabric of reality unravels as you attempt to wipe your entire dreamscape. Better luck next time.\n");
            break;
          case 4:
            system("telnet towel.blinkenlights.nl"); //Watch Star Wars in ASCII
            printf("You watch the epic battle of Star Wars unfold in ASCII art.\n");
            break;
          default:
            printf("Invalid command.\n");
        }
        
        break;
      }
    }
  }
  
  return 0;
}