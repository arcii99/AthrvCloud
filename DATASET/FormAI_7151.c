//FormAI DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>

int main() {
    printf("  _____      _      _____            _            \n");
    printf(" / ____|    | |    |_   _|          (_)           \n");
    printf("| (___   ___| |_     | |  _ __  _ __ _ _ __   ___ \n");
    printf(" \\___ \\ / _ \\ __|    | | | '_ \\| '__| | '_ \\ / _ \\\n");
    printf(" ____) |  __/ |_    _| |_| |_) | |  | | |_) |  __/\n");
    printf("|_____/ \\___|\\__|  |_____| .__/|_|  |_| .__/ \\___|\n");
    printf("                          | |         | |         \n");
    printf("                          |_|         |_|         \n");

    int edges[7][7] = {{0, 1, 1, 0, 0, 0, 1},
                       {1, 0, 0, 1, 0, 0, 1},
                       {1, 0, 0, 1, 1, 0, 1},
                       {0, 1, 1, 0, 1, 1, 0},
                       {0, 0, 1, 1, 0, 1, 0},
                       {0, 0, 0, 1, 1, 0, 0},
                       {1, 1, 1, 0, 0, 0, 0}};
    
    printf("\nThe graph data structure representation:\n\n");
    printf("\t  A  B  C  D  E  F  G\n");
    printf("\t  -----------------\n");
    printf("\tA| %d  %d  %d  %d  %d  %d  %d\n", edges[0][0], edges[0][1], edges[0][2], edges[0][3], edges[0][4], edges[0][5], edges[0][6]);
    printf("\tB| %d  %d  %d  %d  %d  %d  %d\n", edges[1][0], edges[1][1], edges[1][2], edges[1][3], edges[1][4], edges[1][5], edges[1][6]);
    printf("\tC| %d  %d  %d  %d  %d  %d  %d\n", edges[2][0], edges[2][1], edges[2][2], edges[2][3], edges[2][4], edges[2][5], edges[2][6]);
    printf("\tD| %d  %d  %d  %d  %d  %d  %d\n", edges[3][0], edges[3][1], edges[3][2], edges[3][3], edges[3][4], edges[3][5], edges[3][6]);
    printf("\tE| %d  %d  %d  %d  %d  %d  %d\n", edges[4][0], edges[4][1], edges[4][2], edges[4][3], edges[4][4], edges[4][5], edges[4][6]);
    printf("\tF| %d  %d  %d  %d  %d  %d  %d\n", edges[5][0], edges[5][1], edges[5][2], edges[5][3], edges[5][4], edges[5][5], edges[5][6]);
    printf("\tG| %d  %d  %d  %d  %d  %d  %d\n", edges[6][0], edges[6][1], edges[6][2], edges[6][3], edges[6][4], edges[6][5], edges[6][6]);
    
    printf("\nHere is an example of a traversal algorithm that only visits the odd numbered vertices and prints them in reverse order:\n");
    int visited[7] = {0};
    int current_vertex = 1;
    int odd_vertices[4] = {1, 3, 5, 7};
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 7; j++) {
            if (edges[current_vertex-1][j] == 1 && !visited[j] && j+1 == odd_vertices[i]) {
                current_vertex = j + 1;
                visited[current_vertex-1] = 1;
                printf("%d ", current_vertex);
                break;
            }
        }
    }
    printf("\n");
    
    return 0;
}