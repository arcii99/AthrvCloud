//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {
  char start[10]; // to store user input when adventure starts
  char answer[100]; // to store user's answers to questions
  
  printf("Welcome to The Haunted Mansion! Are you ready to start your adventure?\n");
  printf("Type 'yes' to start or 'no' to quit: ");
  
  fgets(start, 10, stdin); // get user input
  
  if (strcmp(start, "yes\n") == 0) { //if user input is 'yes'
    printf("\nGreat! You find yourself standing in front of the gates of The Haunted Mansion. The gates creak open as you approach.\n");
    printf("You step inside and the gates slam shut behind you. You're now in the courtyard.\n");
    printf("You hear strange voices coming from the mansion. Do you want to enter the mansion? (yes or no): ");
    fgets(answer, 100, stdin);

    // Depending on the user's answer, they will have different experiences
    if (strcmp(answer, "yes\n") == 0) { // if user wants to enter the mansion
      
      printf("\nAs you step inside, the door slams shut behind you. You see a figure standing in front of you.\n");
      printf("It's a ghost! It beckons you to follow it. Do you follow the ghost? (yes or no): ");
      fgets(answer, 100, stdin);
      
      if (strcmp(answer, "yes\n") == 0) { // if user decides to follow the ghost
        printf("\nYou follow the ghost through the halls. As you turn a corner, you see a group of ghosts gathered in front of you.\n");
        printf("One of them speaks to you, 'Welcome to The Haunted Mansion. You may join us...'\n");
        printf("Do you join the ghosts? (yes or no): ");
        fgets(answer, 100, stdin);
        
        if (strcmp(answer, "yes\n") == 0) { // if user decides to join the ghosts
          printf("\nYou join the ghosts and become one of them. You will haunt this mansion forever...\n");
        } 
        else { // if user doesn't join the ghosts
          printf("\nYou run away from the ghosts and escape the mansion. You're safe now!\n");
        }
      }
      else { // if user decides not to follow the ghost
        printf("\nThe ghost disappears and you're left alone in the mansion. You hear strange noises coming from every direction.\n");
        printf("Do you continue to explore the mansion or try to find your way out? (explore or escape): ");
        fgets(answer, 100, stdin);
        
        if (strcmp(answer, "explore\n") == 0) { // if user decides to explore the mansion
          printf("\nYou explore the mansion and find yourself in the maze. It's dark and you can't see anything.\n");
          printf("You hear footsteps behind you. Do you run or stay put? (run or stay): ");
          fgets(answer, 100, stdin);
          
          if (strcmp(answer, "run\n") == 0) { // if user decides to run
            printf("\nYou run blindly through the maze and come to a dead end. You're trapped.\n");
            printf("You hear the footsteps getting closer and closer... The end.\n");
          }
          else { // if user decides to stay put
            printf("\nYou stay still and hold your breath. The footsteps fade away. You're safe for now!\n");
          }
        }
        else { // if user decides to escape the mansion
          printf("\nYou try to find your way out of the mansion. The walls seem to move and the doors won't open.\n");
          printf("You hear a voice telling you to give up and stay forever. Do you listen to it? (yes or no): ");
          fgets(answer, 100, stdin);
          
          if (strcmp(answer, "yes\n") == 0) { // if user decides to listen to the voice
            printf("\nYou give up and become trapped in the mansion forever. The end.\n");
          }
          else { // if user decides not to listen to the voice
            printf("\nYou keep trying to escape and eventually find a way out. You're safe now!\n");
          }
        }
      }
    }
    else { // if user decides not to enter the mansion
      printf("\nYou turn around and leave the mansion. You're safe now!\n");
    }
  }
  else { // if user decides not to start the adventure
    printf("\nGoodbye! Come back when you're ready for an adventure.\n");
  }
  
  return 0;
}