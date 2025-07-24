//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

// simulate the sequencing process for a genome of length n
void simulate_sequence(int n) {
  // initialize the genome string with random nucleotides
  char genome[n];
  const char nucleotides[] = "ACTG";
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    genome[i] = nucleotides[rand() % 4];
  }
  
  // simulate the sequencing process
  char read[1000];
  int fd = open("sequence.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
  for (int i = 0; i < n; i += 1000) {
    // randomize the starting position for the read
    int start = rand() % (n - 1000);
    strncpy(read, genome + start, 1000);

    // introduce errors in the read
    for (int j = 0; j < 1000; j++) {
      int rand_num = rand() % 100;
      if (rand_num < 10) {
        read[j] = nucleotides[rand() % 4];
      }
    }

    // write the read to the output file
    write(fd, read, strlen(read));
  }
  close(fd);
}

int main() {
  simulate_sequence(50000);
  return 0;
}