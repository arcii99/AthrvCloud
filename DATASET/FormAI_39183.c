//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tile {
   int visited;
   int has_enemy;
   int has_treasure;
};

struct player {
   int x_pos;
   int y_pos;
   int health;
   int treasure_count;
};

struct dungeon {
   int x_size;
   int y_size;
   struct tile tiles[100][100];
};

void print_map(struct dungeon* d, struct player* p) {
   printf(" ");
   for (int i = 0; i < d->x_size; i++) {
      printf("_");
   }
   printf("\n");
   for (int i = 0; i < d->y_size; i++) {
      printf("|");
      for (int j = 0; j < d->x_size; j++) {
         if (p->x_pos == j && p->y_pos == i) {
            printf("@");
            continue;
         }
         if (d->tiles[j][i].visited) {
            if (d->tiles[j][i].has_enemy) {
               printf("E");
            } else if (d->tiles[j][i].has_treasure) {
               printf("$");
            } else {
               printf(".");
            }
         } else {
            printf(" ");
         }
      }
      printf("|\n");
   }
   printf(" ");
   for (int i = 0; i < d->x_size; i++) {
      printf("-");
   }
   printf("\n");
}

int main() {
   srand(time(NULL));  // Seed the randomizer
   
   struct dungeon d;
   d.x_size = 10 + rand() % 10;
   d.y_size = 10 + rand() % 10;
   
   // Initialize tiles
   for (int i = 0; i < d.x_size; i++) {
      for (int j = 0; j < d.y_size; j++) {
         d.tiles[i][j].visited = 0;
         d.tiles[i][j].has_enemy = (rand() % 100 < 20) ? 1 : 0;
         d.tiles[i][j].has_treasure = (rand() % 100 < 20) ? 1 : 0;
      }
   }
   
   struct player p;
   p.x_pos = rand() % d.x_size;
   p.y_pos = rand() % d.y_size;
   p.health = 10;
   p.treasure_count = 0;
   
   print_map(&d, &p);
   
   while (1) {
      int move = 0;
      while (!move) {
         char c = getchar();
         switch (c) {
            case 'w':
               if (p.y_pos > 0) {
                  p.y_pos--;
                  move = 1;
               }
               break;
            case 'a':
               if (p.x_pos > 0) {
                  p.x_pos--;
                  move = 1;
               }
               break;
            case 's':
               if (p.y_pos < d.y_size - 1) {
                  p.y_pos++;
                  move = 1;
               }
               break;
            case 'd':
               if (p.x_pos < d.x_size - 1) {
                  p.x_pos++;
                  move = 1;
               }
               break;
            case 'q':
               printf("Goodbye!\n");
               return 0;
            default:
               break;
         }
      }
      
      // Check for events
      if (d.tiles[p.x_pos][p.y_pos].has_enemy) {
         printf("You have encountered an enemy!\n");
         int enemy_health = 5 + rand() % 10;
         while (p.health > 0 && enemy_health > 0) {
            int damage = rand() % 5;
            printf("You hit the enemy for %d damage!\n", damage);
            enemy_health -= damage;
            
            if (enemy_health <= 0) {
               printf("The enemy has been defeated!\n");
               p.treasure_count += 5 + rand() % 10;
               d.tiles[p.x_pos][p.y_pos].has_enemy = 0;
               break;
            }
            
            damage = rand() % 5;
            printf("The enemy hits you for %d damage!\n", damage);
            p.health -= damage;
         }
         
         if (p.health <= 0) {
            printf("You have died!\n");
            return 0;
         }
      } else if (d.tiles[p.x_pos][p.y_pos].has_treasure) {
         printf("You have found treasure worth %d gold!\n", 5 + rand() % 10);
         p.treasure_count += 5 + rand() % 10;
         d.tiles[p.x_pos][p.y_pos].has_treasure = 0;
      }
      
      // Mark tile as visited
      d.tiles[p.x_pos][p.y_pos].visited = 1;
      
      print_map(&d, &p);
      
      // Check for victory
      if (p.treasure_count >= 50) {
         printf("Congratulations! You have won!\n");
         return 0;
      }
   }
}