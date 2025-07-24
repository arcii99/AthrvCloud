//FormAI DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>

int main() {
  char color[20];
  printf("Yo! I'm your new C Color Code Converter!\n\n");
  printf("Enter a color name to convert to its hex code: ");
  scanf("%s", color);

  if(strcmp(color, "pink") == 0){
      printf("Pink?! Really? You're going to have to own that one, but here's the hex code: #FFC0CB\n");
  }
  else if(strcmp(color, "teal") == 0){
      printf("Teal it is! The hex code for that bad boy is: #008080\n");
  }
  else if(strcmp(color, "chartreuse") == 0){
      printf("Woah, chartreuse? That's fancy. It's hex code is: #7FFF00\n");
  }
  else if(strcmp(color, "aqua") == 0 || strcmp(color, "cyan") == 0){
      printf("Cyan or Aqua? They're basically the same thing, and here's the hex code: #00FFFF\n");
  }
  else if(strcmp(color, "puce") == 0){
      printf("Puce? What even is that? But here's the hex code: #CC8899\n");
  }
  else{
      printf("I'm sorry, I don't know that color. Let's stick to the basics, huh?\n");
  }

  printf("\nThanks for using my C Color Code Converter! Come back with all your color needs!\n");

  return 0;
}