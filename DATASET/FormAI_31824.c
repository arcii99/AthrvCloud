//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_numbers(int *numbers);
void print_bingo_board(int *numbers);
int check_board(int *numbers);

int main() {
  int numbers[25];

  generate_random_numbers(numbers);
  print_bingo_board(numbers);

  while (!check_board(numbers)) {
    int num;
    printf("Enter the number you want to mark: ");
    scanf("%d", &num);

    // mark the number as -1 to indicate that it is already called
    for (int i = 0; i < 25; i++) {
      if (numbers[i] == num) {
        numbers[i] = -1;
        break;
      }
    }

    print_bingo_board(numbers);
  }

  printf("BINGO! You won!\n");

  return 0;
}

void generate_random_numbers(int *numbers) {
  srand(time(NULL)); // use current time as seed for random generator

  for (int i = 0; i < 25; i++) {
    numbers[i] = -1; // initialize all numbers to -1
  }

  for (int i = 0; i < 25; i++) {
    int num;
    do {
      num = rand() % 75 + 1; // generate random number between 1 and 75
    } while (check_board(numbers) || num == -1);

    numbers[i] = num;
  }
}

void print_bingo_board(int *numbers) {
  printf("B  I  N  G  O\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int index = i * 5 + j;
      if (numbers[index] == -1) {
        printf("X  ");
      } else {
        printf("%d  ", numbers[index]);
      }
    }
    printf("\n");
  }
}

int check_board(int *numbers) {
  int rows[5] = {0};
  int cols[5] = {0};
  int diag1 = 0;
  int diag2 = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int index = i * 5 + j;
      if (numbers[index] == -1) {
        rows[i]++;
        cols[j]++;
        if (i == j) {
          diag1++;
        }
        if (i + j == 4) {
          diag2++;
        }
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    if (rows[i] == 5 || cols[i] == 5) {
      return 1;
    }
  }

  if (diag1 == 5 || diag2 == 5) {
    return 1;
  }

  return 0;
}