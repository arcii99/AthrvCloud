//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <termios.h>

#define MAX_CHARS 100 // maximum number of characters to convert
#define DOT_DURATION 200000 // duration of a "." in microseconds
#define DASH_DURATION 600000 // duration of a "-" in microseconds
#define SPACE_DURATION 1200000 // duration of a space in microseconds

void write_morse_code(int fd, char c);
void send_symbol(int fd, char symbol);

int main(void) {
  char text[MAX_CHARS];
  char *device = "/dev/ttyUSB0"; // The USB/serial device
  int fd;

  // Open the device for output
  fd = open(device, O_WRONLY | O_NONBLOCK);
  if (fd == -1) {
    perror(device);
    exit(1);
  }

  // Set up input for noncanonical mode
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  // Set up signal handling for SIGINT (Ctrl-C)
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = SIG_IGN;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART;
  if (sigaction(SIGINT, &sa, NULL) == -1) {
    perror("sigaction");
    exit(1);
  }

  // Read input from the user and convert to morse code
  while (1) {
    int c = getchar();
    if (c == EOF) {
      usleep(SPACE_DURATION);
      continue;
    }

    write_morse_code(fd, tolower(c));
  }

  // Restore terminal settings and close device
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  close(fd);

  return 0;
}

void write_morse_code(int fd, char c) {
  switch (c) {
    case 'a':
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      break;
    case 'b':
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case 'c':
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      break;
    case 'd':
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case 'e':
      send_symbol(fd, '.');
      break;
    case 'f':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      break;
    case 'g':
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      break;
    case 'h':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case 'i':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case 'j':
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      break;
    case 'k':
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      break;
    case 'l':
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case 'm':
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      break;
    case 'n':
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      break;
    case 'o':
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      break;
    case 'p':
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      break;
    case 'q':
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      break;
    case 'r':
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      break;
    case 's':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case 't':
      send_symbol(fd, '-');
      break;
    case 'u':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      break;
    case 'v':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      break;
    case 'w':
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      break;
    case 'x':
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      break;
    case 'y':
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      break;
    case 'z':
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case '0':
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      break;
    case '1':
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      break;
    case '2':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      break;
    case '3':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      break;
    case '4':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '-');
      break;
    case '5':
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case '6':
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case '7':
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case '8':
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      send_symbol(fd, '.');
      break;
    case '9':
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '-');
      send_symbol(fd, '.');
      break;
    case ' ':
      usleep(SPACE_DURATION);
      break;
    default:
      break;
  }
}

void send_symbol(int fd, char symbol) {
  usleep(DOT_DURATION); // Pause before the symbol
  write(fd, &symbol, 1); // Send the symbol
  usleep(DASH_DURATION - DOT_DURATION); // Pause after the symbol
  write(fd, " ", 1); // Send a space after the symbol
}