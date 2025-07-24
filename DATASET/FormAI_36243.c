//FormAI DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include<stdio.h> 

int main() 
{ 
  int knight = 4; // For illustrative purposes, we shall assume there are four knights in this kingdom
  int noble = 2; // A visiting noble has arrived in the kingdom

  printf("Before the jousting tournament, there were %d knights and %d nobles in the kingdom.\n", knight, noble);
  
  // The jousting tournament brings in more knights to the kingdom
  knight |= 8; // 1000 OR 0100 = 1100 (There are now 12 knights in the kingdom)
  
  printf("After the jousting tournament, there were %d knights and %d nobles in the kingdom.\n", knight, noble);
  
  // The noble wishes to make alliances with the knights, but he cannot deal with the lowest ranking knight
  knight &= ~1; // 1100 AND 1110 = 1100 (The lowest ranking knight has been removed from the kingdom)
  
  printf("The noble has made alliances with all the other remaining knights in the kingdom.\n");
  printf("There were %d knights and %d nobles in the kingdom at the end of the day.\n", knight, noble);

  return 0; 
}