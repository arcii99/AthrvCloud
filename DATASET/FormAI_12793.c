//FormAI DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main() {
  sqlite3 *db;
  
  // open or create the database
  int rc = sqlite3_open("products.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // create the table if it doesn't exist
  const char *create_table = "CREATE TABLE IF NOT EXISTS Products (ID INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Price FLOAT, Description TEXT);";
  rc = sqlite3_exec(db, create_table, 0, 0, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot create table: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // insert some initial data
  const char *insert_data = "INSERT INTO Products (Name, Price, Description) VALUES ('Banana', 0.99, 'A yellow fruit'), ('Apple', 1.49, 'A red fruit'), ('Tomato', 0.69, 'A red vegetable');";
  rc = sqlite3_exec(db, insert_data, 0, 0, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot insert data: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  // select all the products
  const char *select_all = "SELECT * FROM Products;";
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare(db, select_all, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  printf("All products:\n");
  while(sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *name = sqlite3_column_text(stmt, 1);
    double price = sqlite3_column_double(stmt, 2);
    const unsigned char *description = sqlite3_column_text(stmt, 3);
    
    printf("ID: %d, Name: %s, Price: %f, Description %s\n", id, name, price, description);
  }
  
  // select only the expensive products
  const char *select_expensive = "SELECT * FROM Products WHERE Price > 1.00;";
  rc = sqlite3_prepare(db, select_expensive, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  printf("\nExpensive products:\n");
  while(sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *name = sqlite3_column_text(stmt, 1);
    double price = sqlite3_column_double(stmt, 2);
    const unsigned char *description = sqlite3_column_text(stmt, 3);
    
    printf("ID: %d, Name: %s, Price: %f, Description %s\n", id, name, price, description);
  }
  
  // close the connection
  sqlite3_close(db);
  
  return 0;
}