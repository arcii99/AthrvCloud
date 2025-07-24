//FormAI DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
  char name[100];
  
  printf("Enter your name survivor: ");
  scanf("%s", name);
  
  printf("Welcome %s, to the post-apocalyptic world. The world is in chaos after the outbreak of a deadly virus. The few of us left are struggling to survive.\n", name);
  
  char scavenger[8] = "scaveng";
  char message[100] = "We need more supplies. Can you go scavenging?";
  
  if (strstr(message, scavenger)) {
    char task[50];
    strcpy(task, "search the ruins");
    
    printf("Our scavenger team went missing. %s, you need to %s and bring back essential supplies.\n", name, task);
  } else {
    printf("We need someone to %s.\n", message);
  }
  
  char mutated[4] = "mut";
  char mutation[50] = "Watch out for mutated creatures!";
  
  if (strstr(mutation, mutated)) {
    printf("We have been seeing more of these mutated creatures. Be careful out there %s!\n", name);
  } else {
    printf("%s, keep an eye out for any mutated creatures.\n", name);
  }
  
  char group[100] = "We have a group of survivors taking refuge in the city. Come join us.";
  char city[5] = "city";
  
  if (strstr(group, city)) {
    printf("%s, we can't survive on our own, come join us in the city.\n", name);
  } else {
    printf("We are a group of survivors looking for more people to join us %s. If interested, search for our group.\n", name);
  }
  
  return 0;
}