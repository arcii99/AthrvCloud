//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  // Variable declarations
  char passage[1000], summary[1000];
  int len, s_len = 0, i, j;

  // Get passage input
  printf("What tidings dost thou bring?\n");
  fgets(passage, 1000, stdin);
  len = strlen(passage);

  // Summarize passage
  for (i=0; i<len; i++) {
    // Check for end of sentence
    if (passage[i] == '.' || passage[i] == '!' || (passage[i] == '?' && passage[i+1] != ' ')) {
      // Add sentence to summary
      for (j=i; j>=0; j--) {
        // Check for start of sentence
        if (j == 0 || (j > 0 && (passage[j-1] == '.' || passage[j-1] == '!' || passage[j-1] == '?')))
          break;
      }
      // Copy sentence into summary string, separated by newline character
      for (; j<=i; j++) {
        summary[s_len] = passage[j];
        s_len++;
      }
      summary[s_len] = '\n';
      s_len++;
    }
  }
  summary[s_len] = '\0';

  // Print summary
  printf("Hark! Here be the summarization: \n%s\n", summary);
  
  return 0;
}