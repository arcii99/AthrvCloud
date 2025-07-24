//FormAI DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char input[1000];

  // A mysterious declaration
  printf("Hear ye, hear ye! Pray tell me, what dost thou thy script desire?\n");

  // Taking input
  fgets(input, sizeof(input), stdin);

  // A brave new line of code
  printf("Ah, I see! Verily, let me beautify thy script...\n");

  // A noble quest
  beautifyScript(input);

  // A triumphant return
  printf("Behold, thy script of HTML hath been beautified with grace and elegance!\n");

  return 0;
}

// A chivalrous function to beautify the script
void beautifyScript(char* input) {

  // A declaration of variables
  char output[10000];
  int tabs = 0, len = 0;

  // A brave code block
  for (int i = 0; i < strlen(input); i++) {

    if (input[i] == '<') {

      // A battle cry
      printf("Hark! A tag hath been found!\n");

      // A bold decision to add a tab
      for (int j = 0; j < tabs; j++) {
         output[len++] = '\t';
      }

      // An honorable addition to the output
      output[len++] = input[i];
      output[len++] = '\n';

      // A fearless increment
      tabs++;

    } else if (input[i] == '>') {

      // A declaration of defiance
      printf("Slay! The closing bracket hath been found!\n");

      // A heroic decrement
      tabs--;

      // A valiant addition to the output
      output[len++] = '\n';

      // An enterprising calculation of tabs
      for (int j = 0; j < tabs; j++) {
          output[len++] = '\t';
      }

      // An audacious addition to the output
      output[len++] = input[i];

      // A courageous new line
      output[len++] = '\n';

    } else {

      // A humble addition to the output
      output[len++] = input[i];
    }
  }

  // An honorable end to the function
  printf("Verily, thy script hath been beautified!\n");
  printf("Let us now admire it with glee:\n");
  printf("%s\n", output);
}