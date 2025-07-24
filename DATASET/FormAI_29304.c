//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep()

int main() {
  printf("Welcome to C RAM Usage Monitor!\n");
  printf("Tracking RAM usage...\n\n");
  sleep(1);

  while(1) {
    system("free -m > ram.txt"); // storing free memory and used memory in ram.txt file
    FILE *fp = fopen("ram.txt","r"); // opening file in read mode
    char buffer[1024]; // buffer to read data from file

    if(fp != NULL) {
      while(fgets(buffer, sizeof(buffer), fp) != NULL) { // reading file line by line
        printf("%s", buffer); // printing contents of the file line by line
      }
    }

    fclose(fp); // closing the file
    printf("\nUpdating RAM usage in every 5 seconds...\n\n");
    sleep(5);
  }

  return 0;
}