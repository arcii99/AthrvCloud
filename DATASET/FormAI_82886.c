//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 10

typedef struct Room{
    int x, y, w, h;
} room;

typedef struct Map{
    char layout[WIDTH][HEIGHT];
    room rooms[MAX_ROOMS];
    int num_rooms;
} map;

void init_map(map* m){
    // Initialize layout to be all walls
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            m->layout[i][j] = '#';
        }
    }

    // Generate rooms
    for(int i = 0; i < MAX_ROOMS; i++){
        int x = rand() % (WIDTH - 10) + 1;
        int y = rand() % (HEIGHT - 6) + 1;
        int w = rand() % 8 + 4;
        int h = rand() % 4 + 3;

        // Check for overlapping rooms
        for(int j = 0; j < m->num_rooms; j++){
            room r = m->rooms[j];
            if(x < r.x + r.w && x + w > r.x && y < r.y + r.h && y + h > r.y){
                x = rand() % (WIDTH - 10) + 1;
                y = rand() % (HEIGHT - 6) + 1;
                j = -1;
            }
        }

        // Add room to map
        m->rooms[i].x = x;
        m->rooms[i].y = y;
        m->rooms[i].w = w;
        m->rooms[i].h = h;
        m->num_rooms++;
    }

    // Connect rooms with corridors
    for(int i = 0; i < m->num_rooms - 1; i++){
        int x1 = m->rooms[i].x + m->rooms[i].w/2;
        int y1 = m->rooms[i].y + m->rooms[i].h/2;
        int x2 = m->rooms[i+1].x + m->rooms[i+1].w/2;
        int y2 = m->rooms[i+1].y + m->rooms[i+1].h/2;
        
        while(x1 != x2 || y1 != y2){
            if(x1 < x2){
                x1++;
            } else if(x1 > x2){
                x1--;
            }

            if(y1 < y2){
                y1++;
            } else if(y1 > y2){
                y1--;
            }

            m->layout[x1][y1] = '.';
        }
    }
}

void print_map(map* m){
    for(int j = 0; j < HEIGHT; j++){
        for(int i = 0; i < WIDTH; i++){
            printf("%c ", m->layout[i][j]);
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));

    map m;
    init_map(&m);
    print_map(&m);

    return 0;
}