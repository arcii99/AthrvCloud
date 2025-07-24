//FormAI DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int main() {
   srand(time(NULL)); //seeding the random number generator
 
   int shape = rand() % 3; //generating a random number to determine the shape of the e-book reader
 
   if (shape == 0) { //shape 0 = square
      //code for displaying a square-shaped e-book reader UI
   }
   else if (shape == 1) { //shape 1 = circle
      //code for displaying a circle-shaped e-book reader UI
   }
   else { //shape 2 = triangle
      //code for displaying a triangle-shaped e-book reader UI
   }
 
   //code for reading the e-book files and displaying them on the screen
 
   return 0;
}