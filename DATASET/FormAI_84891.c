//FormAI DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>

// Retro data mining program

int main() {
  char data[] = "Retro Data Mining Example";
  int freq[26] = {0};

  for (int i = 0; data[i] != '\0'; i++) {
    if (data[i] >= 'A' && data[i] <= 'Z') {
      freq[data[i] - 'A']++;
    } else if (data[i] >= 'a' && data[i] <= 'z') {
      freq[data[i] - 'a']++;
    }
  }

  printf("Frequency of each letter: \n");
  for (int i = 0; i < 26; i++) {
    printf("%c: %d\n", i+'a', freq[i]);
  }

  // Finding the most frequent letter
  int max_freq = 0;
  char max_letter;

  for (int i = 0; i < 26; i++) {
    if (freq[i] > max_freq) {
      max_freq = freq[i];
      max_letter = i + 'a';
    }
  }

  printf("The most frequent letter is '%c' appearing %d times in the string.\n", max_letter, max_freq);

  return 0;
}