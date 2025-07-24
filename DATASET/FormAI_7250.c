//FormAI DATASET v1.0 Category: System event logger ; Style: all-encompassing
/* 
   This is a unique C System Event Logger program that logs various events for an imaginary
   online shopping application. The program logs events such as user logins, product searches, 
   adding items to cart, and completing orders. The logged events are stored in a file with 
   a time stamp so that they can be analyzed later.

   Author: Jane Doe
   Date:   21st May 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to log user login events
void log_login(char* username) {
  // Get current time
  time_t curr_time;
  time(&curr_time);

  // Open log file in append mode
  FILE *fptr;
  fptr = fopen("event_log.txt", "a");

  // Write event to log file with timestamp
  fprintf(fptr, "User %s logged in at %s\n", username, ctime(&curr_time));
  fclose(fptr);
}

// Function to log product search events
void log_search(char* search_term) {
  // Get current time
  time_t curr_time;
  time(&curr_time);

  // Open log file in append mode
  FILE *fptr;
  fptr = fopen("event_log.txt", "a");

  // Write event to log file with timestamp
  fprintf(fptr, "User searched for %s at %s\n", search_term, ctime(&curr_time));
  fclose(fptr);
}

// Function to log add to cart events
void log_add_to_cart(char* item_name) {
  // Get current time
  time_t curr_time;
  time(&curr_time);

  // Open log file in append mode
  FILE *fptr;
  fptr = fopen("event_log.txt", "a");

  // Write event to log file with timestamp
  fprintf(fptr, "User added item %s to cart at %s\n", item_name, ctime(&curr_time));
  fclose(fptr);
}

// Function to log order completion events
void log_order_complete(char* item_name) {
  // Get current time
  time_t curr_time;
  time(&curr_time);

  // Open log file in append mode
  FILE *fptr;
  fptr = fopen("event_log.txt", "a");

  // Write event to log file with timestamp
  fprintf(fptr, "User completed order for item %s at %s\n", item_name, ctime(&curr_time));
  fclose(fptr);
}

// Main function to simulate a shopping session and log events
int main() {
  // Simulate user login event
  char *username = "jane_doe";
  log_login(username);

  // Simulate user searching for an item
  char *search_term = "laptop";
  log_search(search_term);

  // Simulate user adding an item to cart
  char *item_name = "MacBook Pro";
  log_add_to_cart(item_name);

  // Simulate user completing order
  log_order_complete(item_name);

  return 0;
}