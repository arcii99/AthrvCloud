//FormAI DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#define ROWS 50
#define COLS 50

int grid[ROWS][COLS];
int next_grid[ROWS][COLS];

void init_grid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

int count_neighbors(int row, int col) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int r = row + i;
            int c = col + j;
            if(i == 0 && j == 0) continue;
            if(r < 0 || r >= ROWS || c < 0 || c >= COLS) continue;
            if(grid[r][c] == 1) count++;
        }
    }
    return count;
}

void next_iteration() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int count = count_neighbors(i, j);
            if(grid[i][j] == 1) {
                if(count < 2 || count > 3) next_grid[i][j] = 0;
                else next_grid[i][j] = 1;
            }
            else {
                if(count == 3) next_grid[i][j] = 1;
                else next_grid[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void print_grid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int main() {
    init_grid();
    for(int i = 0; i < 100; i++) {
        system("clear");    // Comment this line if not using linux
        // system("cls");  // Uncomment this line if using windows
        print_grid();
        next_iteration();
        usleep(100000);     // For slower rendering, increase value of usleep
    }
    return 0;
}