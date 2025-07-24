//FormAI DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num_of_bids;
  int bid_values[10];
  int highest_bid_value = 0;
  int highest_bid_index = 0;

  printf("Welcome to the Digital Auction System.\n\n");

  printf("Please enter the number of bids you would like to make (maximum 10): ");
  scanf("%d", &num_of_bids);

  if (num_of_bids > 10 || num_of_bids < 1)
  {
    printf("Invalid input. You can only make between 1 and 10 bids.\n");
    return 1;
  }

  printf("\nPlease enter your bid values (in dollars) one by one:\n");

  for (int i = 0; i < num_of_bids; i++)
  {
    scanf("%d", &bid_values[i]);

    if (bid_values[i] > highest_bid_value)
    {
      highest_bid_value = bid_values[i];
      highest_bid_index = i;
    }
  }

  printf("\nAll bids have been submitted. The highest bid is: $%d\n", highest_bid_value);
  printf("Congratulations to the highest bidder, who made bid number %d.\n", highest_bid_index + 1);

  return 0;
}