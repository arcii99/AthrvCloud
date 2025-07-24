//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main(){ 

  char data[] = "Data is the new oil"; // Input data to be mined
  int freq[26] = {0}; // Array to store frequency of each letter in input data
  int i = 0;

  // Count the frequency of each letter in the data
  while(data[i] != '\0') {
    if(data[i] >= 'a' && data[i] <= 'z') {
      freq[data[i] - 'a']++;
    }
    i++;
  }

  // Determine the most frequent letter in the data
  int max_freq = 0;
  char max_letter;
  for(int j = 0; j < 26; j++) {
    if(freq[j] > max_freq) {
      max_freq = freq[j];
      max_letter = j + 'a';
    }
  }

  // Output the results
  printf("The most frequent letter in the data is '%c', which appeared %d times.\n", max_letter, max_freq);

  return 0;
}