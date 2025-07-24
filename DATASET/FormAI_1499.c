//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
   char cyberpunk[20000] = "<html><head><title>Welcome to the Cyberpunk World!</title></head>\n<body>\n<h1>Experience the Future Today!</h1>\n<p>Our world is a dark and gritty place. But that doesn't mean it's ugly! In fact, it's quite beautiful when you look at it from the right angle.</p>\n<div class=\"cyberDeck\">\n<p>Our Cyber Decks will elevate your experience to the next level. With our latest technology, you can now tap into a whole new world of possibilities.</p>\n<ul><li>Real-time Hacking</li><li>Advanced Robotics</li><li>Virtual Reality</li></ul>\n<p>Don't miss out on this opportunity to upgrade your life. Join us on the dark side.</p>\n</div>\n<footer>\n<p><a href=\"#\">Contact</a> us if you have any questions or concerns.</p>\n</footer>\n</body>\n</html>\n";
   int indent = 0;
   int i;

   for (i = 0; i < strlen(cyberpunk); i++) {
      if (cyberpunk[i] == '<') {
         if (cyberpunk[i+1] == '/') {
            indent -= 2;
         }
         for (int j = 0; j < indent; j++) {
            putchar(' ');
         }
         if (cyberpunk[i+1] != '/') {
            indent += 2;
         }
      }
      putchar(cyberpunk[i]);
      if (cyberpunk[i] == '>') {
         putchar('\n');
      }
   }
   return 0;
}