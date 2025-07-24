//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <math.h>

#define MAX_DRONE_SPEED 50 // maximum speed of the drone
#define MIN_DRONE_SPEED -50 // minimum speed of the drone

int fd; // file descriptor for reading/writing to serial port

int droneSpeed = 0; // initial speed of the drone

struct termios options; // structure for modifying terminal attributes

void setupSerial() {
  fd = open("/dev/cu.usbmodem1411", O_RDWR | O_NOCTTY | O_NDELAY); // open the serial port
  if (fd == -1) {
    printf("Error: cannot open serial port\n");
    exit(1);
  }
  
  tcgetattr(fd, &options); // get the current terminal attributes

  cfsetispeed(&options, B9600); // set the input baud rate to 9600
  cfsetospeed(&options, B9600); // set the output baud rate to 9600
  
  options.c_cflag |= (CLOCAL | CREAD); // enable receiver and set local mode
  options.c_cflag &= ~CSIZE; // clear the character size bits
  options.c_cflag |= CS8; // set the character size to 8 bits
  options.c_cflag &= ~PARENB; // disable parity bit
  options.c_cflag &= ~CSTOPB; // set the number of stop bits to 1
  options.c_cflag &= ~CRTSCTS; // disable hardware flow control
  
  tcsetattr(fd, TCSANOW, &options); // apply the new terminal attributes
}

void sendCommand(char* command) {
  int len = strlen(command);
  write(fd, command, len); // write the command to the serial port
}

void takeOff() {
  printf("Taking off...\n");
  sendCommand("takeoff"); // send the takeoff command to the drone
}

void land() {
  printf("Landing...\n");
  sendCommand("land"); // send the land command to the drone
}

void moveForward() {
  printf("Moving forward...\n");
  sendCommand("forward 50"); // send the forward command with a speed of 50 to the drone
  droneSpeed = MAX_DRONE_SPEED; // set the drone speed to the max speed
}

void moveBackward() {
  printf("Moving backward...\n");
  sendCommand("back 50"); // send the backward command with a speed of 50 to the drone
  droneSpeed = MIN_DRONE_SPEED; // set the drone speed to the min speed
}

void moveLeft() {
  printf("Moving left...\n");
  sendCommand("left 50"); // send the left command with a speed of 50 to the drone
  droneSpeed = (int)(0.5 * (float)MAX_DRONE_SPEED); // set the drone speed to half of max speed
}

void moveRight() {
  printf("Moving right...\n");
  sendCommand("right 50"); // send the right command with a speed of 50 to the drone
  droneSpeed = (int)(0.5 * (float)MAX_DRONE_SPEED); // set the drone speed to half of max speed
}

void moveUp() {
  printf("Moving up...\n");
  sendCommand("up 50"); // send the up command with a speed of 50 to the drone
}

void moveDown() {
  printf("Moving down...\n");
  sendCommand("down 50"); // send the down command with a speed of 50 to the drone
}

void rotateLeft() {
  printf("Rotating left...\n");
  sendCommand("counter-clockwise 50"); // send the counter-clockwise command with a speed of 50 to the drone
}

void rotateRight() {
  printf("Rotating right...\n");
  sendCommand("clockwise 50"); // send the clockwise command with a speed of 50 to the drone
}

void stopMovement() {
  printf("Stopping movement...\n");
  sendCommand("stop"); // send the stop command to the drone
  droneSpeed = 0; // set the drone speed to zero
}

void adjustSpeed(int amount) {
  int newSpeed = droneSpeed + amount; // calculate the new speed

  if (newSpeed > MAX_DRONE_SPEED) {
    newSpeed = MAX_DRONE_SPEED; // set the speed to the max speed if it's too high
  } else if (newSpeed < MIN_DRONE_SPEED) {
    newSpeed = MIN_DRONE_SPEED; // set the speed to the min speed if it's too low
  }

  printf("Adjusting speed to %d...\n", newSpeed);
  char command[100];
  sprintf(command, "speed %d", newSpeed); // create the speed command based on the new speed
  sendCommand(command); // send the speed command to the drone
  droneSpeed = newSpeed; // set the drone speed to the new speed
}

int main() {
  setupSerial(); // setup the serial connection
  printf("Welcome to the ultraprecise C Drone Remote Control program!\n");
  printf("Press 't' to take off, 'l' to land, 'f' to move forward, 'b' to move backward,\n");
  printf("'s' to stop, 'u' to move up, 'd' to move down, 'r' to rotate right,\n");
  printf("'q' to rotate left, 'a' to move left, 'e' to move right, '+' to increase speed,\n");
  printf("and '-' to decrease speed.\n\n");

  while(1) {
    char input = getchar(); // get user input

    switch(input) {
      case 't': // take off
        takeOff();
        break;
      case 'l': // land
        land();
        break;
      case 'f': // move forward
        moveForward();
        break;
      case 'b': // move backward
        moveBackward();
        break;
      case 's': // stop movement
        stopMovement();
        break;
      case 'u': // move up
        moveUp();
        break;
      case 'd': // move down
        moveDown();
        break;
      case 'r': // rotate right
        rotateRight();
        break;
      case 'q': // rotate left
        rotateLeft();
        break;
      case 'a': // move left
        moveLeft();
        break;
      case 'e': // move right
        moveRight();
        break;
      case '+': // increase speed
        adjustSpeed(10);
        break;
      case '-': // decrease speed
        adjustSpeed(-10);
        break;
      default:
        printf("Unknown command: %c\n", input);
        break;
    }
  }

  return 0;
}