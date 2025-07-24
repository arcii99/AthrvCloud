//FormAI DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
/*

  Compresses a string using a unique compression algorithm.

  The algorithm works by replacing consecutive repeating
  characters with a count of the repetition. For example,
  the string "aaabbb" would be compressed to "a3b3".

  Each compressed character takes up two bytes, with the first
  byte representing the number of times the character is repeated,
  and the second byte representing the character itself.

*/

#include <stdio.h>
#include <string.h>

void compress(char *str) {
  int len = strlen(str);
  char buf[1000];
  int count = 1;
  int buf_index = 0;
  char current = str[0];

  for (int i = 1; i < len; i++) {
    if (str[i] == current) {
      count++;
    } else {
      buf[buf_index] = count;
      buf[buf_index+1] = current;
      buf_index += 2;
      count = 1;
      current = str[i];
    }
  }

  // append the last sequence
  buf[buf_index] = count;
  buf[buf_index+1] = current;
  buf_index += 2;

  // copy the compressed string back into the original string
  memcpy(str, buf, buf_index);
  str[buf_index] = '\0';
}

int main() {
  char str[] = "aaabbbcccdddeeefff";
  printf("Before compression: %s\n", str);
  compress(str);
  printf("After compression: %s\n", str);
  return 0;
}