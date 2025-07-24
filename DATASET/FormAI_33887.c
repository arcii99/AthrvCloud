//FormAI DATASET v1.0 Category: Poker Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 13
int generate_card_number()
{
   return (rand() % 13) + 1;
}

// Function to print the name of a card based on its number
void print_card_name(int card_number)
{
   switch(card_number) 
   {
      case 1:
         printf("Ace ");
         break;
      case 11:
         printf("Jack ");
         break;
      case 12:
         printf("Queen ");
         break;
      case 13:
         printf("King ");
         break;
      default:
         printf("%d ", card_number);
         break;
   }
}

// Function to print the suit of a card based on its number
void print_card_suit(int card_suit)
{
   switch(card_suit)
   {
      case 1:
         printf("of Hearts");
         break;
      case 2:
         printf("of Clubs");
         break;
      case 3:
         printf("of Diamonds");
         break;
      case 4:
         printf("of Spades");
         break;
   }
}

int main()
{
   printf("Welcome to a peaceful game of Poker.\n");
   printf("You have been dealt the following hand:\n");

   srand(time(0));

   int card1_number = generate_card_number();
   int card1_suit = (rand() % 4) + 1;

   print_card_name(card1_number);
   print_card_suit(card1_suit);
   printf(" and ");

   int card2_number = generate_card_number();
   int card2_suit = (rand() % 4) + 1;

   print_card_name(card2_number);
   print_card_suit(card2_suit);
   printf("\n");

   int flop1_number = generate_card_number();
   int flop1_suit = (rand() % 4) + 1;

   int flop2_number = generate_card_number();
   int flop2_suit = (rand() % 4) + 1;

   int flop3_number = generate_card_number();
   int flop3_suit = (rand() % 4) + 1;

   printf("The flop is:\n");
   print_card_name(flop1_number);
   print_card_suit(flop1_suit);
   printf(", ");
   print_card_name(flop2_number);
   print_card_suit(flop2_suit);
   printf(", and ");
   print_card_name(flop3_number);
   print_card_suit(flop3_suit);
   printf("\n");

   int turn_number = generate_card_number();
   int turn_suit = (rand() % 4) + 1;

   printf("The turn is:\n");
   print_card_name(turn_number);
   print_card_suit(turn_suit);
   printf("\n");

   int river_number = generate_card_number();
   int river_suit = (rand() % 4) + 1;

   printf("The river is:\n");
   print_card_name(river_number);
   print_card_suit(river_suit);
   printf("\n");

   return 0;
}