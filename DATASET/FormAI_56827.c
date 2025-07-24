//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: artistic
#include <stdio.h>

int main(){
  int x,y;
  int radius=50;
  int centerX=150;
  int centerY=150;
  int length=200;
  int width=100;

  printf("Creating unique geometric shape using C\n");
  printf("Enter the coordinates x and y between 0 and 300\n");

  scanf("%d %d",&x,&y);

  if(x>0 && x<=300 && y>=0 && y<=300){
    if(x<=centerX && y<=centerY){
      printf("Inside the circle\n");
    }
    else if(x>centerX && y>=centerY && y<=(centerY+(width/2))){
      printf("Inside the rectangle\n");
    }
      else if(x>=centerX && x<=(centerX+length) && y>=(centerY+(width/2))){
        printf("Inside the triangle\n");
      }
          else if(x>=120 && x<=180 && y>=30 && y<=90){
            printf("Inside the square\n");
          }
          else{
            printf("Outside all the shapes\n");
          } 
        }
        else{
          printf("Invalid coordinates\n");
        }
        return 0;
      }