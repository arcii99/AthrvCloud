//FormAI DATASET v1.0 Category: Fractal Generation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

void drawSierpinski(int x1, int y1, int x2, int y2, int x3, int y3, int depth){
  if(depth == 0){
    printf("%d,%d\n", x1, y1);
    printf("%d,%d\n", x2, y2);
    printf("%d,%d\n", x3, y3);
  }else{
    int x12 = (x1 + x2)/2;
    int y12 = (y1 + y2)/2;
    int x23 = (x2 + x3)/2;
    int y23 = (y2 + y3)/2;
    int x31 = (x3 + x1)/2;
    int y31 = (y3 + y1)/2;
    drawSierpinski(x1, y1, x12, y12, x31, y31, depth-1);
    drawSierpinski(x2, y2, x23, y23, x12, y12, depth-1);
    drawSierpinski(x3, y3, x31, y31, x23, y23, depth-1);
  }
}

int main(){
  int triangleSize = 512;
  int depth = 6;
  int height = triangleSize*sin(M_PI/3);
  int x1 = 0;
  int y1 = height;
  int x2 = triangleSize;
  int y2 = height;
  int x3 = triangleSize/2;
  int y3 = 0;
  drawSierpinski(x1, y1, x2, y2, x3, y3, depth);
  
  return 0;
}