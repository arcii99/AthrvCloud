//FormAI DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float radius, height;
  printf("Welcome to the Curious Math Circus!\n\n");
  printf("We have a special show for you today where we'll be calculating the volume of a cone!\n\n");
  printf("What is the radius of the base of the cone?\n");
  scanf("%f", &radius);
  printf("What is the height of the cone?\n");
  scanf("%f", &height);
  
  // Calculating the volume of the cone
  float volume = (1.0 / 3) * M_PI * pow(radius, 2) * height;
  
  if(volume < 0) {
    printf("\nOh dear, something went wrong with the calculation.\n");
    printf("Don't worry, let's try that again!\n");
    return 0;
  }

  printf("\nFantastic! The volume of the cone is %.2f cubic units.\n", volume);
  printf("\n");
  
  // Challenge the user to calculate the surface area of the cone
  printf("Can you calculate the surface area of the cone?\n");
  
  float slant_height = sqrt(pow(radius, 2) + pow(height, 2));
  float surface_area = M_PI * radius * (radius + slant_height);
  
  printf("\nHmm, let me check...\n");
  float user_answer;
  scanf("%f", &user_answer);
  
  if(user_answer == surface_area) {
    printf("Wow! You got it right! Congratulations!\n");
  } else {
    printf("Sorry, that's not correct. The correct answer is %.2f square units.\n", surface_area);
  }
  printf("\n");
  
  // Show the user some interesting facts about cones
  printf("Did you know that the word 'cone' comes from the Greek word 'k?nos', which means pinecone?\n");
  printf("Cones are commonly used in the manufacture of ice cream cones, traffic cones, and loudspeakers.\n");
  printf("The surface area of the Earth is approximately equal to the surface area of three cones with the same base radius and height as the Earth.\n");
  
  return 0;
}