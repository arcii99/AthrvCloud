//FormAI DATASET v1.0 Category: Robot movement control ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Defining the constants
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define PI 3.14159265358979323846

//Defining the structure
typedef struct 
{
   double x, y, z, alpha, beta, gamma;
} Robot;

//Function to move correctly
void move(Robot *r, int dir, double distance) 
{
   switch (dir) 
   {
      // Move forward
      case FORWARD:
         r->x += distance * cos(r->alpha);
         r->y += distance * sin(r->alpha);
         break;

         //Move Backward
      case BACKWARD:
         r->x -= distance * cos(r->alpha);
         r->y -= distance * sin(r->alpha);
         break;

         //Move left
      case LEFT:
         r->x += distance * cos(r->alpha + PI / 2);
         r->y += distance * sin(r->alpha + PI / 2);
         break;

         //Move right
      case RIGHT:
         r->x += distance * cos(r->alpha - PI / 2);
         r->y += distance * sin(r->alpha - PI / 2);
         break;
   }   
}

//Function to rotate
void rotate(Robot *r, double angle) 
{
   r->alpha += angle;   
}

//Main Function
int main() 
{
   Robot r;
   r.x = 0;
   r.y = 0;
   r.z = 0;
   r.alpha = 0.0;
   r.beta = 0.0;
   r.gamma = 0.0;

   printf("Starting Position: %.2lf, %.2lf\n", r.x, r.y);
   
   move(&r, FORWARD, 5.0);   // Move forward by 5 units
   printf("Moved Forward, Position: %.2lf, %.2lf\n", r.x, r.y);
   
   move(&r, RIGHT, 4.0);   // Move right by 4 units
   printf("Moved Right, Position: %.2lf, %.2lf\n", r.x, r.y);
   
   rotate(&r, PI / 4);   // Rotate by pi/4 radians
   printf("Rotated, Position: %.2lf, %.2lf\n", r.x, r.y);

   move(&r, FORWARD, 3.0);   // Move forward by 3 units
   printf("Moved forward after rotation, Position: %.2lf, %.2lf\n", r.x, r.y);

   return 0;
}