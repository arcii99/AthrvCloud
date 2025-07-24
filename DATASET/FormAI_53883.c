//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_NUMBERS 100000

int randomNumber() {
  return rand() % 100;
}

typedef struct {
  int numbers[MAX_NUMBERS];
  size_t count;
} NumberBuffer;

typedef struct {
  NumberBuffer buffer;
  int sum;
} SumBuffer;

void addNumberAsync(NumberBuffer *buffer, int number) {
  if (buffer->count < MAX_NUMBERS) {
    buffer->numbers[buffer->count++] = number;
    printf("Added number: %d\n", number);
  }
}

void sumNumbersAsync(NumberBuffer *buffer, SumBuffer *sumBuffer) {
  int sum = 0;
  for (size_t i = 0; i < buffer->count; i++) {
    sum += buffer->numbers[i];
  }
  sumBuffer->buffer = *buffer;
  sumBuffer->sum = sum;
  buffer->count = 0;
  printf("Summed %zu numbers: %d\n", sumBuffer->buffer.count, sumBuffer->sum);
}

void printBuffer(NumberBuffer *buffer) {
  printf("Buffer contains %zu numbers:\n[ ", buffer->count);
  for (size_t i = 0; i < buffer->count && i < 10; i++) {
    printf("%d ", buffer->numbers[i]);
  }
  if (buffer->count > 10) {
    printf("... ");
  }
  printf("]\n");
}

void printSumBuffer(SumBuffer *buffer) {
  printf("Sum buffer contains sum: %d, and buffer size: %zu\n", buffer->sum, buffer->buffer.count);
  printBuffer(&buffer->buffer);
}

int main(int argc, char **argv) {
  srand(time(NULL));
  NumberBuffer buffer = { .count = 0 };
  SumBuffer sumBuffer = { .sum = 0, .buffer.count = 0 };

  for (size_t i = 0; i < 10; i++) {
    addNumberAsync(&buffer, randomNumber());
  }

  printBuffer(&buffer);

  sumNumbersAsync(&buffer, &sumBuffer);

  printf("Current sum: %d\n", sumBuffer.sum);

  printSumBuffer(&sumBuffer);

  return 0;
}