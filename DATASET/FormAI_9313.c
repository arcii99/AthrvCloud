//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SENTENCE "The quick brown fox jumps over the lazy dog."
#define MAX_TIME 60.0
#define MAX_ERRORS 3

int main() {
  int i, j, count, errors, seconds;
  double start, end, time_taken;
  char input[100];
  char ch;

  puts("Welcome to our Typing Speed Test!");
  puts("You will be given a sentence to type, and your goal is to type it as quickly and accurately as possible.");

  printf("\nThe sentence is:\n%s\n", SENTENCE);

  puts("When you are ready, press ENTER to begin.");
  getchar();

  puts("3...");
  sleep(1);
  puts("2...");
  sleep(1);
  puts("1...");
  sleep(1);
  puts("GO!");

  count = errors = 0;
  time_taken = 0.0;
  start = clock();

  while (count < sizeof(SENTENCE)-1) {
    ch = SENTENCE[count];
    printf("%c", ch);

    j = 0;

    do {
      input[j] = getchar();
      if (isalnum(input[j])) {
        j++;
      }
    } while ((clock() - start) / CLOCKS_PER_SEC < MAX_TIME && j < sizeof(input) - 1);

    input[j] = '\0';

    if (strcmp(input, "quit") == 0) {
      break;
    }

    i = 0;

    while (input[i] != '\0' && SENTENCE[count] != '\0') {
      if (input[i] != SENTENCE[count]) {
        errors++;

        if (errors >= MAX_ERRORS) {
          puts("\nToo many errors. Better luck next time!");
          exit(1);
        }
      }

      count++;
      i++;
    }
  }

  end = clock();
  time_taken = (end - start) / CLOCKS_PER_SEC;

  puts("\n\nGreat Job! Here are your results:");

  if (time_taken >= MAX_TIME) {
    puts("You took too long. Try again!");
    return 1;
  }

  printf("Elapsed time: %.2f seconds\n", time_taken);
  printf("Number of errors: %d\n", errors);
  printf("Words per minute: %.2f\n", count / (time_taken / 60.0));

  return 0;
}