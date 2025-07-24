//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  
  printf("           __                 \n");
  printf("       .-'\\ \\                \n");
  printf("     .' \\ \\ \\               \n");
  printf("    / <) ) ) \\              \n");
  printf("  _/ \\\\ (/ / \\ \\            \n");
  printf(" / \\\\    /).:.\\ \\           \n");
  printf("( `)'\\ / .:.,. `.\\         \n");
  printf("(>\\   `-' .:.,. .:.`.       \n");
  printf(">-` >\\ `^^-^--^--^-^-.      \n");
  printf("`   \\  \\             `.     \n");
  printf("     `\"`               `    \n");
  printf("           ALIEN INVASION PROBABILITY CALCULATOR\n\n");

  srand(time(NULL)); // Seed the random number generator with current time

  int probability = rand() % 101; // Generate a random number between 0-100 as the probability

  printf("Calculating probability of an alien invasion...\n\n");
  printf("Probability: %d%%\n\n", probability);

  if (probability == 0) {
    printf("No chance of an alien invasion, humanity is safe for now.\n");
  } else if (probability > 0 && probability < 25) {
    printf("Low probability of an alien invasion.\n");
    printf("But, it's always good to be prepared. You never know what's out there.\n");
  } else if (probability >= 25 && probability < 50) {
    printf("Moderate probability of an alien invasion.\n");
    printf("We should start taking this seriously and make necessary preparations.\n");
  } else if (probability >= 50 && probability < 75) {
    printf("High probability of an alien invasion.\n");
    printf("We need to act fast and work together with other nations to defend our planet.\n");
  } else {
    printf("Very high probability of an alien invasion.\n");
    printf("This is not a drill, we need to evacuate major cities and prepare for a full-scale invasion.\n");
  }

  return 0;
}