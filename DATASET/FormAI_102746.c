//FormAI DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *html = "<html>\n<body>\n<div>\n<p>Hello world!</p>\n</div>\n</body>\n</html>";
  int indent = 0;
  int len = strlen(html);
  char *output = (char*)malloc(len*sizeof(char));
  int j = 0;
  for(int i=0; i<len; i++) {
    char c = html[i];
    if(c == '<') {
      output[j] = '\n';
      for(int k=0; k<indent; k++) {
        output[++j] = ' ';
      }
      indent += 2;
    } else if(c == '/') {
      indent -= 2;
    }
    output[++j] = c;
  }
  printf("%s", output);
  free(output);
  return 0;
}