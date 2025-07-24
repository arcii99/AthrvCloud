//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  //The warehouse has a total of 5 shelves
  int num_shelves = 5;
  //Each shelf can hold a maximum of 10 items
  int max_items_per_shelf = 10;

  //Create a 2D array to represent the shelves and their contents
  char shelves[num_shelves][max_items_per_shelf][50];

  //Initialize all shelves and items to be empty to begin with
  for (int i = 0; i < num_shelves; i++)
  {
    for (int j = 0; j < max_items_per_shelf; j++)
    {
      strcpy(shelves[i][j], "Empty");
    }
  }

  //Display the initial state of the warehouse
  printf("Initial Warehouse State:\n\n");

  for (int i = 0; i < num_shelves; i++)
  {
    printf("Shelf %d: ", i+1);
    for (int j = 0; j < max_items_per_shelf; j++)
    {
      printf("%s ", shelves[i][j]);
    }
    printf("\n");
  }

  //Prompt the user to choose an action to take
  printf("\nWhat would you like to do?\n");
  printf("(1) Add an item to the warehouse\n");
  printf("(2) Remove an item from the warehouse\n");
  printf("(3) View the current state of the warehouse\n");
  printf("(4) Exit\n");

  int choice;
  scanf("%d", &choice);

  while (choice != 4)
  {
    if (choice == 1)
    {
      //Add an item to the warehouse

      //Prompt the user for the shelf and item number
      int shelf_num, item_num;
      printf("Enter the shelf number (1-5): ");
      scanf("%d", &shelf_num);
      printf("Enter the item number (1-10): ");
      scanf("%d", &item_num);

      //Make sure the shelf and item number are valid
      if (shelf_num < 1 || shelf_num > num_shelves || item_num < 1 || item_num > max_items_per_shelf)
      {
        printf("Invalid shelf or item number\n");
      }
      else
      {
        //Prompt the user for the item name
        printf("Enter the name of the item: ");
        char item_name[50];
        scanf("%s", item_name);

        //Add the item to the specified shelf and item number
        strcpy(shelves[shelf_num - 1][item_num - 1], item_name);

        //Confirm that the item was added successfully
        printf("Item '%s' has been added to shelf %d, item %d\n", item_name, shelf_num, item_num);
      }
    }
    else if (choice == 2)
    {
      //Remove an item from the warehouse

      //Prompt the user for the shelf and item number
      int shelf_num, item_num;
      printf("Enter the shelf number (1-5): ");
      scanf("%d", &shelf_num);
      printf("Enter the item number (1-10): ");
      scanf("%d", &item_num);

      //Make sure the shelf and item number are valid
      if (shelf_num < 1 || shelf_num > num_shelves || item_num < 1 || item_num > max_items_per_shelf)
      {
        printf("Invalid shelf or item number\n");
      }
      else if (strcmp(shelves[shelf_num - 1][item_num - 1], "Empty") == 0)
      {
        //Make sure there is actually an item to remove
        printf("There is no item to remove from shelf %d, item %d\n", shelf_num, item_num);
      }
      else
      {
        //Remove the item from the specified shelf and item number
        strcpy(shelves[shelf_num - 1][item_num - 1], "Empty");

        //Confirm that the item was removed successfully
        printf("Item has been removed from shelf %d, item %d\n", shelf_num, item_num);
      }
    }
    else if (choice == 3)
    {
      //Display the current state of the warehouse

      printf("Current Warehouse State:\n\n");

      for (int i = 0; i < num_shelves; i++)
      {
        printf("Shelf %d: ", i+1);
        for (int j = 0; j < max_items_per_shelf; j++)
        {
          printf("%s ", shelves[i][j]);
        }
        printf("\n");
      }
    }
    else
    {
      //Invalid choice, prompt the user again
      printf("Invalid choice, please enter a number from 1-4\n");
    }

    //Prompt the user to choose another action to take
    printf("\nWhat would you like to do?\n");
    printf("(1) Add an item to the warehouse\n");
    printf("(2) Remove an item from the warehouse\n");
    printf("(3) View the current state of the warehouse\n");
    printf("(4) Exit\n");

    scanf("%d", &choice);
  }

  printf("Thank you for using the Warehouse Management System!\n");

  return 0;
}