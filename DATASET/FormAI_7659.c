//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 50
#define BOARD_HEIGHT 20
#define MAX_ROOMS 10
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 10
#define MIN_ROOM_WIDTH 5
#define MIN_ROOM_HEIGHT 5

void generate_board(char board[BOARD_HEIGHT][BOARD_WIDTH]);
void print_board(char board[BOARD_HEIGHT][BOARD_WIDTH]);

int main()
{
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    srand(time(NULL));
    generate_board(board);
    print_board(board);
    return 0;
}

void generate_board(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    int num_rooms = rand() % MAX_ROOMS + 1;
    int room_x, room_y, room_width, room_height;
    for (int i = 0; i < num_rooms; i++)
    {
        room_width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
        room_height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
        room_x = rand() % (BOARD_WIDTH - room_width - 1) + 1;
        room_y = rand() % (BOARD_HEIGHT - room_height - 1) + 1;
        for (int y = room_y; y < room_y + room_height; y++)
        {
            for (int x = room_x; x < room_x + room_width; x++)
            {
                board[y][x] = '.';
            }
        }
    }
}

void print_board(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            if (board[y][x] == '\0')
            {
                board[y][x] = '#';
            }
            printf("%c", board[y][x]);
        }
        printf("\n");
    }
}