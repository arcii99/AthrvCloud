//FormAI DATASET v1.0 Category: System administration ; Style: enthusiastic
#include<unistd.h>
#include<stdio.h>

int main() {
  printf("Welcome to the system administration program by Chatbot!\n");
  printf("This program is designed to help manage your system with ease.\n");
  printf("Let's get started!");

  // Checking system information
  printf("Checking System Information...");
  system("uname -a");
  system("lsb-release -a");

  // Creating a new User
  printf("Creating a new User...\n");
  system("sudo adduser newuser");

  // Installing a package
  printf("Installing a package...\n");
  system("sudo apt-get install wget");

  // Starting a service
  printf("Starting a service...\n");
  system("sudo systemctl start apache2");

  // Stoping a service
  printf("Stoping a service...\n");
  system("sudo systemctl stop apache2");

  // Checking system resources
  printf("Checking system resources...\n");
  system("top");

  // Updating system packages
  printf("Updating system packages...\n");
  system("sudo apt-get update && sudo apt-get upgrade");

  // Checking system logs
  printf("Checking system logs...\n");
  system("sudo journalctl");

  printf("Thank you for using the system administration program by Chatbot!");

  return 0;
}