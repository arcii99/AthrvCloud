//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include <stdio.h>

void move(int, char, char, char);
void tower_of_hanoi(int);

int main() 
{
   int num;
   
   printf("Enter the number of disks: ");
   scanf("%d", &num);
   
   printf("The sequence of moves involved in the Tower of Hanoi are: \n");
   tower_of_hanoi(num);
   
   return 0;
}

void tower_of_hanoi(int num) 
{
   move(num, 'A', 'C', 'B');
}

void move(int num, char source, char destination, char auxiliary) 
{
   if (num == 1) 
   {
      printf("Move disk 1 from %c to %c\n", source, destination);
      return;
   }
   move(num-1, source, auxiliary, destination);
   printf("Move disk %d from %c to %c\n", num, source, destination);
   move(num-1, auxiliary, destination, source);
}