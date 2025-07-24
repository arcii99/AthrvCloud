//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include<stdio.h>
#include<math.h>

int main(){
   float radius, area, circumference;
   
   printf("Hello there! Let's calculate the area and circumference of a circle!\n");
   printf("Please enter the radius of the circle: ");
   scanf("%f", &radius);
   
   area = M_PI * pow(radius, 2);
   circumference = 2 * M_PI * radius;
   
   printf("\nYay! We did it!\n");
   printf("The area of the circle is: %.2f\n",area);
   printf("The circumference of the circle is: %.2f\n",circumference);
   
   printf("\nWait, do you want me to calculate the diameter of the circle too? ");
   char answer[5];
   scanf("%s", answer);
   
   if (answer[0] == 'y' || answer[0] == 'Y'){
      float diameter = 2 * radius;
      printf("\nWoohoo! Here's the diameter of the circle: %.2f", diameter);
   }
   else{
      printf("\nOkay, no worries! Let me know if you need anything else.");
   }
   
   return 0;
}