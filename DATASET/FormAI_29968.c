//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include<stdio.h>
#include<string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40

int charToAscii(char c){
  return (int) c;
}

void printBanner(char *text) {
  int length = strlen(text);

  for(int i=0; i<MAX_HEIGHT; i++) {
    for(int j=0; j<MAX_WIDTH; j++) {
      if ( (j == 0 || j == MAX_WIDTH-1) || (i == 0 || i == MAX_HEIGHT-1) ) {
        printf("#"); 
      } else if ( i == MAX_HEIGHT/2 ) {
        int idx = (int)(j * length / MAX_WIDTH);
        printf("%c", text[idx]);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  printf("Enter your text here: ");
  char text[1000];
  fgets(text, 1000, stdin);

  printf("\n");

  printBanner(text);
  return 0;
}