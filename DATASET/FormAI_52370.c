//FormAI DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>

int main(){
  char event[100];
  int event_id, time;
  
  printf("Welcome to our Event Logger System!\n");
  
  printf("Enter the event ID: ");
  scanf("%d", &event_id);
  
  printf("Enter the event description: ");
  scanf("%s", event);
  
  printf("Enter the time of the event: ");
  scanf("%d", &time);
  
  printf("Event logged successfully!\n");
  printf("Event ID: %d\n", event_id);
  printf("Event Description: %s\n", event);
  printf("Event Time: %d\n", time);
  
  return 0;
}