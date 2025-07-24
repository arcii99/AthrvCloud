//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize the random seed
  // conspiracy theory topics
  const char* topics[] = {"The Moon Landing was faked", "Chemtrails are poisoning us", "The Illuminati is controlling everything", "9/11 was an inside job", "The Earth is flat"};

  // conspiracy theory keywords
  const char* keywords[] = {"aliens", "government", "secret society", "cover-up", "mind control", "New World Order", "hidden technology"};

  // randomly select a topic and keyword
  int topicIndex = rand() % (sizeof(topics) / sizeof(topics[0]));
  int keywordIndex = rand() % (sizeof(keywords) / sizeof(keywords[0]));

  // generate a conspiracy theory message
  printf("Did you know that %s is all just a cover-up by %s?\n", topics[topicIndex], keywords[keywordIndex]);

  return 0;
}