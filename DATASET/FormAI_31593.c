//FormAI DATASET v1.0 Category: Arithmetic ; Style: medieval
#include <stdio.h>

int main() {
  int heroes = 10; // number of heroes on our quest
  int monsters = 15; // number of monsters we're facing

  int total = heroes + monsters; // total number of creatures on the field

  printf("Assemble the heroes!! We have %d valiant knights ready for battle!\n", heroes);
  printf("But we face a daunting army of %d fierce monsters!\n", monsters);
  printf("Fear not! Our combined strength is %d, and together we will be victorious!\n", total);

  int casualties = (monsters * 2) - heroes; // calculate expected casualties
  int net_heroes = heroes - casualties; // subtract expected casualties from heroes on quest

  printf("Our enemy is strong, and we may lose up to %d men in this battle.\n", casualties);
  printf("But if all goes well, we will return with %d brave knights to tell the tale!\n", net_heroes);

  int loot = (heroes * 50) + (monsters * 25); // calculate potential treasure

  printf("And let's not forget about the treasure! With %d men, we could find up to %d gold pieces in the monster's lair.\n", net_heroes, loot);

  return 0;
}