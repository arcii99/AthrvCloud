//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() 
{
  printf("Welcome to our Happy Firewall Program!\n\n");

  while(1) // Loop to continuously ask user for input
  {
    char input[50];
    printf("Please enter a packet ID: ");
    scanf("%s", input);
    printf("Packet ID %s has been received.\n\n", input);

    if(strlen(input) < 10 || strlen(input) > 20) // If packet ID is too short or too long
    {
      printf("Invalid packet ID length. Please try again.\n\n");
      continue; // Restart loop to ask for new input
    }

    int sum = 0;
    int i;
    for(i = 0; i < strlen(input); i++) // Loop to calculate sum of ASCII values of packet ID characters
    {
      sum += (int)input[i];
    }

    if(sum % 2 == 0) // If sum is even
    {
      printf("Packet %s has been blocked by the firewall because the sum of its ASCII values is even.\n\n", input);
    }
    else // If sum is odd
    {
      printf("Packet %s has passed through the firewall because the sum of its ASCII values is odd.\n\n", input);
    }
  }

  return 0;
}