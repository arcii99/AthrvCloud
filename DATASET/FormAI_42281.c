//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_ITEMS 100

typedef struct{
  int id;
  char name[MAX_NAME_LEN];
  float price;
  int quantity;
} Product;

typedef struct{
  int id;
  char name[MAX_NAME_LEN];
  int capacity;
  int current_capacity;
  Product items[MAX_ITEMS];
} Warehouse;

int warehouse_count = 0;
Warehouse warehouses[MAX_PRODUCTS];

int add_warehouse(char* name, int capacity){
  Warehouse w;
  w.id = warehouse_count;
  strcpy(w.name, name);
  w.capacity = capacity;
  w.current_capacity = 0;
  warehouse_count++;
  warehouses[w.id] = w;
  return w.id;
}

int add_product(int warehouse_id, char* name, float price, int quantity){
  if(warehouse_id >= 0 && warehouse_id < warehouse_count){
    Warehouse w = warehouses[warehouse_id];
    if(quantity > (w.capacity - w.current_capacity)){
      printf("Warehouse %s is full, cannot add product\n", w.name);
      return -1;
    }
    Product p;
    p.id = w.current_capacity;
    strcpy(p.name, name);
    p.price = price;
    p.quantity = quantity;
    w.items[p.id] = p;
    w.current_capacity++;
    warehouses[warehouse_id] = w;
    printf("Product %s added to warehouse %s\n", p.name, w.name);
    return p.id;
  } else {
    printf("Invalid warehouse id\n");
    return -1;
  }
}

int main(){
  int wh1 = add_warehouse("Warehouse 1", 10);
  add_product(wh1, "Product 1", 10.0, 5);
  add_product(wh1, "Product 2", 20.0, 3);
  add_product(wh1, "Product 3", 30.0, 10);

  int wh2 = add_warehouse("Warehouse 2", 20);
  add_product(wh2, "Product 4", 40.0, 15);
  add_product(wh2, "Product 5", 50.0, 8);

  return 0;
}