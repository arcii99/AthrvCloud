//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

//Define the structure for each item in the inventory
struct medicineInventory {
  char name[50];
  int quantity;
  float price;
};

//Global variables
struct medicineInventory inventory[100];
int numItems = 0;

//Function to add an item to the inventory
void addMedicine(char name[], int quantity, float price) {
  struct medicineInventory newItem;
  
  //Add the information for the new item
  strcpy(newItem.name, name);
  newItem.quantity = quantity;
  newItem.price = price;
  
  //Add the new item to the inventory array
  inventory[numItems] = newItem;
  numItems++;
  
  printf("%s added to inventory.\n", name);
}

//Function to display the inventory
void displayInventory() {
  printf("NAME\tQUANTITY\tPRICE\n");
  
  //Loop through the inventory array and print each item
  for (int i = 0; i < numItems; i++) {
    printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
}

//Function to search for an item in the inventory
int searchInventory(char name[]) {
  for (int i = 0; i < numItems; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      return i;
    }
  }
  
  //If the item is not found
  return -1;
}

//Function to update the quantity of an item in the inventory
void updateInventory(char name[], int quantity) {
  int itemIndex = searchInventory(name);
  
  //If the item is found
  if (itemIndex != -1) {
    inventory[itemIndex].quantity += quantity;
    
    printf("%d %s added to inventory.\n", quantity, name);
  }
  else {
    printf("%s not found in inventory.\n", name);
  }
}

//Function to sell an item from the inventory
void sellMedicine(char name[], int quantity) {
  int itemIndex = searchInventory(name);
  
  //If the item is found
  if (itemIndex != -1) {
    //If there is enough quantity to sell
    if (inventory[itemIndex].quantity >= quantity) {
      inventory[itemIndex].quantity -= quantity;
      float totalPrice = inventory[itemIndex].price * quantity;
      
      printf("%d %s sold for %.2f.\n", quantity, name, totalPrice);
    }
    else {
      printf("Not enough %s in inventory to sell!", name);
    }
  }
  else {
    printf("%s not found in inventory.\n", name);
  }
}

int main() {
  //Add some initial items to the inventory
  addMedicine("Acetaminophen", 50, 5.99);
  addMedicine("Ibuprofen", 75, 9.99);
  addMedicine("Aspirin", 100, 3.99);
  
  //Display the initial inventory
  displayInventory();
  
  //Update the inventory
  updateInventory("Ibuprofen", 25);
  updateInventory("Nonexistent Item", 10);
  
  //Display the updated inventory
  displayInventory();
  
  //Sell some items
  sellMedicine("Ibuprofen", 10);
  sellMedicine("Nonexistent Item", 5);
  sellMedicine("Aspirin", 200);
  
  //Display the final inventory
  displayInventory();
  
  return 0;
}