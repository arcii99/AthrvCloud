//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_of_tests = 5; // number of test paragraphs
  char tests[][200] = { // test paragraphs
    "Beneath the rule of men entirely great, The pen is mightier than the sword. - Edward Bulwer-Lytton",
    "Two things are infinite: the universe and human stupidity; and I'm not sure about the universe. - Albert Einstein",
    "We're born alone, we live alone, we die alone. Only through our love and friendship can we create the illusion for the moment that we're not alone. - Orson Welles",
    "Believe you can and you're halfway there. - Theodore Roosevelt",
    "The only true wisdom is in knowing you know nothing. - Socrates"
  };
  int total_chars = 0; // total number of characters in all tests
  for (int i = 0; i < num_of_tests; i++) {
    total_chars += sizeof(tests[i])/sizeof(char);
  }
  const int timer_value = 60; // duration of the test in seconds
  const int max_chars = 50; // maximum number of characters to display
  printf("Type the following paragraphs as quickly and accurately as possible. You have %d seconds.\n", timer_value);
  printf("--------------------------------------------------\n\n");
  for (int i = 0; i < num_of_tests; i++) {
    printf("Paragraph %d:\n%s\n\n", i+1, tests[i]);
  }
  printf("--------------------------------------------------\n\n");
  printf("Press ENTER to start the test.\n");
  getchar();
  printf("Ready...\n");
  printf("--------------------------------------------------\n\n");
  srand(time(NULL));
  int count = 0;
  clock_t start_time = clock();
  while ((clock()-start_time)/CLOCKS_PER_SEC < timer_value) {
    int random_test = rand()%num_of_tests;
    int random_char = rand()%(sizeof(tests[random_test])/sizeof(char));
    printf("%c", tests[random_test][random_char]);
    count++;
  }
  int elapsed_time = (clock()-start_time)/CLOCKS_PER_SEC;
  printf("\n\n--------------------------------------------------\n\n");
  printf("You typed %d characters in %d seconds.\n", count, elapsed_time);
  printf("Your typing speed was %.2f characters per second.\n", (float)count/elapsed_time);
  float accuracy = ((float)count/total_chars)*100;
  printf("Your accuracy was %.2f%%.\n", accuracy);
  printf("--------------------------------------------------\n\n");
  return 0;
}