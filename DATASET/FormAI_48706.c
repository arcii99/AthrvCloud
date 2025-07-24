//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ACTIONS 10

typedef struct Action{
   char actionName[20];
   char keyShortcut[5];
}Action;

Action actions[MAX_ACTIONS];

void runAction(char* key){
   for(int i = 0; i < MAX_ACTIONS; i++){
       if(strcmp(actions[i].keyShortcut, key) == 0){
           printf("Running %s action\n", actions[i].actionName);
           return;
       }
   }
   printf("Invalid key pressed\n");
}

void printMenu(){
   printf("DRONE REMOTE CONTROL\n");
   printf("--------------------\n");
   for(int i = 0; i < MAX_ACTIONS; i++){
       printf("%s (%s)\n", actions[i].actionName, actions[i].keyShortcut);
   }
}

int main(){
   strcpy(actions[0].actionName, "Take off");
   strcpy(actions[0].keyShortcut, "T");

   strcpy(actions[1].actionName, "Land");
   strcpy(actions[1].keyShortcut, "L");

   strcpy(actions[2].actionName, "Move Forward");
   strcpy(actions[2].keyShortcut, "F");

   strcpy(actions[3].actionName, "Move Backward");
   strcpy(actions[3].keyShortcut, "B");

   strcpy(actions[4].actionName, "Move Left");
   strcpy(actions[4].keyShortcut, "L");

   strcpy(actions[5].actionName, "Move Right");
   strcpy(actions[5].keyShortcut, "R");

   strcpy(actions[6].actionName, "Increase Altitude");
   strcpy(actions[6].keyShortcut, "+");

   strcpy(actions[7].actionName, "Decrease Altitude");
   strcpy(actions[7].keyShortcut, "-");

   strcpy(actions[8].actionName, "Take Picture");
   strcpy(actions[8].keyShortcut, "P");

   strcpy(actions[9].actionName, "Exit");
   strcpy(actions[9].keyShortcut, "Q");

   bool running = true;
   char key[5];

   while(running){
       printMenu();
       printf("Press a key: ");
       scanf("%s", key);
       runAction(key);
       if(strcmp(key, "Q") == 0){
           running = false;
       }
   }

   printf("Exiting drone remote control...\n");

   return 0;
}