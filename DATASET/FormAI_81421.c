//FormAI DATASET v1.0 Category: Fractal Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define XSIZE 40
#define YSIZE 40

int map[YSIZE+1][2*XSIZE+2];         // Map data (0 or 1) for each pixel (x,y)
int x=0, y=0;                        // Pixel coordinates
int dir=0;                           // Direction (0-3)
int len=1;                           // Current segment length
int count=0;                         // Count of segments drawn
int threshold=4;                     // How many times to draw each pixel
int totalPixels=(YSIZE+1)*(2*XSIZE+2);// Total pixels in the map
int *pixelsDrawn;                    

// Draw a straight line of length len, updating map[] in the process
void drawLine() {
  int i,j;
  for (i=1; i<=len; i++) {
    count++;
    switch (dir) {
      case 0: // right
        x++;
        break;
      case 1: // down
        y++;
        break;
      case 2: // left
        x--;
        break;
      case 3: // up
        y--;
        break;
      default:
        printf("Invalid dir: %d\n",dir);
        exit(1);
    }
    map[y][x]=1;
    if (count % threshold == 0) {
      // Store the pixel coordinates to be drawn later by main()
      *pixelsDrawn++ = x*YSIZE+y;
    }
  }
}

// Turn 90 degrees to the right
void turnRight() {
  dir++;
  if (dir > 3) {
    dir = 0;
  }
}

// Generate the fractal using the L-system algorithm
void generateFractal() {
  static char* ls = "1[0&&&0111&&0]&&1&&&&0[1&&0&&0[^[^1[[^1[1///0]^]1]11]1]0]01110^^1[010///111[^^^0[1[[^1[^1[^^1[0^^0]1]^]11]1]1]11/^]0";
  int level=9;       // L-system recursion level
  char* rs;          // L-system result string
  int i;
  rs = (char*) malloc(strlen(ls)*(int)pow(6,level));
  strcpy(rs,ls);
  for (i=0; i<level; i++) {
    // Implement L-system rules (see http://paulbourke.net/fractals/lsys/)
    char *p = rs;
    while (*p != '\0') {
      switch (*p) {
        case '0':
        case '1':
        case '[':
        case ']':
          // Leave these characters alone
          break;
        case '&':
          // Turn left by 90 degrees
          turnRight();
          turnRight();
          turnRight();
          break;
        case '^':
          // Turn right by 90 degrees
          turnRight();
          break;
        case '/':
          // Reverse direction
          turnRight();
          turnRight();
          break;
        default:
          printf("Invalid L-system char: %c\n",*p);
          exit(1);
      }
      p++;
    }
  }
  // Once L-system result is obtained, draw the fractal
  for (i=0; i<strlen(rs); i++) {
    if (rs[i] == '0') {
      drawLine();
    }
    else if (rs[i] == '1') {
      drawLine();
      turnRight();
    }
    else if (rs[i] == '[') {
      // Save current state
      *pixelsDrawn++ = -1;
      *pixelsDrawn++ = x*YSIZE+y;
      *pixelsDrawn++ = dir;
      *pixelsDrawn++ = len;
      len /= 2;
    }
    else if (rs[i] == ']') {
      // Restore last state
      len = *(--pixelsDrawn);
      dir = *(--pixelsDrawn);
      y = *(--pixelsDrawn);
      x = *(--pixelsDrawn)/YSIZE;
      pixelsDrawn += 4;
    }
    else {
      printf("Invalid L-system char: %c\n",rs[i]);
      exit(1);
    }
  }
  free(rs);
}

int main(int argc, char** argv) {
  int i,j;
  pixelsDrawn = (int*) malloc(totalPixels*sizeof(int));
  for (i=0; i<=YSIZE; i++) {
    for (j=0; j<=2*XSIZE+1; j++) {
      map[i][j] = 0;
    }
  }
  map[0][XSIZE] = 1;
  generateFractal();
  // Draw all the pixels that were stored earlier during line drawing
  for (i=totalPixels-1; i>=0; i--) {
    if (pixelsDrawn[i] == -1) {
      continue;
    }
    if (pixelsDrawn[i] < 0 || pixelsDrawn[i] >= totalPixels) {
      printf("Invalid pixel index: %d\n",pixelsDrawn[i]);
      exit(1);
    }
    int x = pixelsDrawn[i] / YSIZE;
    int y = pixelsDrawn[i] % YSIZE;
    if (map[y][x] == 1) {
      printf("Duplicate pixel: (%d,%d)\n",x,y);
      exit(1);
    }
    map[y][x] = 1;
  }
  // Print the fractal
  for (i=0; i<=YSIZE; i++) {
    for (j=0; j<=2*XSIZE+1; j++) {
      if (map[YSIZE-i][j] == 1) {
        printf("*");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
  free(pixelsDrawn);
  return 0;
}