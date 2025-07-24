//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  char input[20];
  time_t t;

  // Intializes random number generator
  srand((unsigned) time(&t));

  // Generating random number between 0-20
  int random_number = rand() % 21;

  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Please enter your name: ");

  // Reading user's name
  fgets(input, sizeof(input), stdin);
  printf("Hello, %s\n", input);
  printf("Do you want to know your future? (yes/no)\n");

  // Reading user's response
  fgets(input, sizeof(input), stdin);

  if (strcmp(input, "yes\n") == 0)
  {
    printf("Generating your fortune...\n");

    switch (random_number)
    {
      case 0:
        printf("You will have a pleasant surprise today!\n");
        break;
      case 1:
        printf("You will meet a new acquaintance soon.\n");
        break;
      case 2:
        printf("You will receive a windfall soon!\n");
        break;
      case 3:
        printf("Your dreams will come true soon!\n");
        break;
      case 4:
        printf("A new opportunity will present itself soon!\n");
        break;
      case 5:
        printf("You will travel to a far off place soon!\n");
        break;
      case 6:
        printf("You will find true love soon!\n");
        break;
      case 7:
        printf("You will be promoted soon!\n");
        break;
      case 8:
        printf("You will receive a special surprise from a loved one soon!\n");
        break;
      case 9:
        printf("You will make new friends soon!\n");
        break;
      case 10:
        printf("You will have a successful business venture soon!\n");
        break;
      case 11:
        printf("You will find inner peace soon!\n");
        break;
      case 12:
        printf("You will pass your exams with flying colors!\n");
        break;
      case 13:
        printf("You will find a solution to a long-standing problem soon!\n");
        break;
      case 14:
        printf("You will have an exciting adventure soon!\n");
        break;
      case 15:
        printf("You will be recognized for your hard work soon!\n");
        break;
      case 16:
        printf("You will receive a gift from someone special soon!\n");
        break;
      case 17:
        printf("You will be blessed with good health soon!\n");
        break;
      case 18:
        printf("You will learn a valuable life lesson soon!\n");
        break;
      case 19:
        printf("You will embark on a new journey soon!\n");
        break;
      case 20:
        printf("You will have a happy and peaceful life!\n");
        break;
      default:
        break;
    }

    printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");
  }
  else
  {
    printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");
  }

  return 0;
}