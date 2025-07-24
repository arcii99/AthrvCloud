//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main(){
  // ASCII art printout with a smiley face!
  printf("\n\n");
  printf("      _____        _____            \n");
  printf("  .-\"     \\\\ ___//     `-.         \n");
  printf(" /  __      /'--' `\\      __ \\    \n");
  printf("|/'  _)       _____       (_ `\\|  \n");
  printf("|_.-'        /' _  `\\        `../  \n");
  printf("            (`a`a`)            \n");
  printf("             \\ V /             \n");
  printf("             (_^_)             \n");
  printf("            /\\| |/\\            \n");
  printf("           (\\|_|/` )           \n");
  printf("            `\\___/'            \n");
  printf("\n\n");

  // Creating a sample text to convert:
  char str[100] = "HELLO WORLD! I AM A HAPPY BOT!";

  // Converting text to ASCII art:
  for(int i=0;i<100;i++){
      if(str[i] != '\0'){
          int ascii_num = (int)str[i];
          printf("%c",ascii_num);
      }else{
          break;
      }
  }
  printf("\n\n");

  // ASCII art text printout:
  printf("@@@@@@@    @@@@@@   @@@@@@@@  @@@@@@@@  @@@@@@@@ \n");
  printf("@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@ \n");
  printf("@@!  @@@  @@!  @@@  @@!         @@!     @@!      \n");
  printf("!@!  @!@  !@!  @!@  !@!         !@!     !@!      \n");
  printf("@!@!!@!   @!@!@!@!  @!!!:!      @!!     @!!!:!   \n");
  printf("!!@!@!    !!!@!!!!  !!!!!:      !!!     !!!!!:   \n");
  printf("!!: :!!   !!:  !!!  !!:         !!:     !!:      \n");
  printf(":!:  !:!  :!:  !:!  :!:         :!:     :!:      \n");
  printf("::   :::  ::   :::   :: ::::     ::      :: :::: \n");
  printf(" :   : :   :   : :  : :: ::      :     : :: ::   \n");

  return 0;
}