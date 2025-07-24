//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(){
   printf("Welcome to the C Fitness Tracker!\n");
   printf("Get ready to sweat some code!\n");
   printf("What's your name?\n");
   char name[20];
   scanf("%s", name);
   printf("Hello, %s! Let's get started.\n", name);
   printf("How much do you weigh (in lbs)?\n");
   int weight;
   scanf("%d", &weight);
   printf("How tall are you (in inches)?\n");
   int height;
   scanf("%d", &height);
   printf("How old are you?\n");
   int age;
   scanf("%d", &age);
   printf("Great! Now let's move on to the fun stuff.\n");
   int burpees, squats, pushups;
   printf("How many burpees can you do in a row?\n");
   scanf("%d", &burpees);
   printf("How many squats can you do in a row?\n");
   scanf("%d", &squats);
   printf("How many pushups can you do in a row?\n");
   scanf("%d", &pushups);
   printf("Impressive! Now, let's get to work.\n");
   printf("Here's a workout to get you started:\n");
   int workout_time = 30;
   int calories_burned = ((weight * 0.45) * 10) * workout_time;
   printf("Workout time: %d minutes\n", workout_time);
   printf("Calories burned: %d\n", calories_burned);
   printf("BURPEES: %d reps\n", burpees*3);
   printf("SQUATS: %d reps\n", squats*2);
   printf("PUSHUPS: %d reps\n", pushups*2);
   printf("\n\n");
   printf("Way to go, %s! You did it!\n", name);
   printf("That's all for today. Come back tomorrow for more!\n");
   return 0;
}