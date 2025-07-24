//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>

// Ken Thompson-style unique browser plugin program

// function to check if given website is safe or not
int isSafe(char* url) {
  // logic to check if website is safe
  // we can use an external API or database to check for website safety
  // for now, let's assume all websites are safe
  return 1;
}

// function to display a warning message to user
void displayWarning() {
  printf("\n\nWARNING! This website may not be safe!\n");
  printf("Please proceed with caution.\n\n");
}

// function to check the URL before opening it in the browser
void checkURL(char* url) {
  // first, check if the website is safe
  if(!isSafe(url)) {
    displayWarning();
  }
  // if website is safe, proceed with opening it in the browser
  else {
    printf("Opening %s in the browser...\n", url);
    // code to open the website in the browser goes here (not included for brevity)
  }
}

// main function
int main() {
  char url[100];
  printf("Enter the URL you want to open in the browser: ");
  scanf("%s", url);
  // check the URL before opening it in the browser
  checkURL(url);
  return 0;
}