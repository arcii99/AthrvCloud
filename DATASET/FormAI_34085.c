//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>

int main() {
  /* We will create a program to calculate the number of tomatoes each person ate at a party */ 

  printf("Welcome to the tomato tracker program!\n");

  int num_people; /* declare variable for number of people at the party */
  printf("How many people were at the party? ");
  scanf("%d", &num_people); /* get input from user for number of people */

  float num_tomatoes[num_people]; /* declare array to store number of tomatoes for each person */

  /* loop through each person and get their tomato count */
  for (int i = 0; i < num_people; i++) {
    printf("How many tomatoes did person %d eat? ", i+1);
    scanf("%f", &num_tomatoes[i]); /* storing the number of tomatoes for that person */
  }

  float total_tomatoes = 0; /* Declare a variable to store the total number of tomatoes eaten across all people */

  /* loop through each person and add their tomato count to the total tomatoes */
  for (int i = 0; i < num_people; i++) {
    total_tomatoes += num_tomatoes[i];
  }

  float avg_tomatoes = total_tomatoes / num_people; /* divide the total number of tomatoes by number of people to get average */

  printf("\nThe average number of tomatoes eaten per person is %.2f", avg_tomatoes);

  return 0;
}