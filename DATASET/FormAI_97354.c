//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define ESC 27 // ASCII value for escape key

int main() {
  struct termios orig, new;
  tcgetattr(STDIN_FILENO, &orig);
  new = orig;
  new.c_lflag &= ~(ICANON|ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new);
  char c;

  printf("Drone Remote Control\n");
  printf("--------------------\n");
  printf("Press the following keys to control the drone:\n");
  printf("w - move forward\n");
  printf("a - move left\n");
  printf("s - move backward\n");
  printf("d - move right\n");
  printf("q - turn left\n");
  printf("e - turn right\n");
  printf("z - move up\n");
  printf("x - move down\n");

  while(1) {
    c = getchar();
    switch(c) {
      case 'w':
        printf("Drone moving forward\n");
        break;
      case 'a':
        printf("Drone moving left\n");
        break;
      case 's':
        printf("Drone moving backward\n");
        break;
      case 'd':
        printf("Drone moving right\n");
        break;
      case 'q':
        printf("Drone turning left\n");
        break;
      case 'e':
        printf("Drone turning right\n");
        break;
      case 'z':
        printf("Drone moving up\n");
        break;
      case 'x':
        printf("Drone moving down\n");
        break;
      case ESC:
        printf("Exiting program...\n");
        tcsetattr(STDIN_FILENO, TCSANOW, &orig);
        exit(0);
        break;
      default:
        printf("Invalid input\n");
        break;
    }
  }
  
  return 0;
}