//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PLAYERS 100
#define MAX_ROUNDS 20
#define MAX_SCORE 1000

typedef struct {
    int x;
    int y;
    int score;
} player_t;

typedef struct {
    player_t players[MAX_PLAYERS];
    int count;
} player_list_t;

typedef struct {
    player_t players[2];
    int round;
} match_t;

typedef struct {
    match_t matches[MAX_ROUNDS];
    int count;
} match_list_t;

float euclidean_distance(player_t a, player_t b) {
    int x_diff = a.x - b.x;
    int y_diff = a.y - b.y;
    return sqrt((x_diff * x_diff) + (y_diff * y_diff));
}

float avg_cluster_distance(player_list_t *cluster) {
    int i,j;
    float sum = 0;
    for(i = 0; i < cluster->count; i++) {
        for(j = i+1; j < cluster->count; j++) {
            sum += euclidean_distance(cluster->players[i], cluster->players[j]);
        }
    }
    return sum / ((cluster->count*(cluster->count-1))/2);
}

int find_closest_clusters(player_list_t *clusters, int *a, int *b) {
    int i,j;
    float min_distance = MAX_SCORE*MAX_SCORE;
    for(i = 0; i < clusters->count; i++) {
        for(j = i+1; j < clusters->count; j++) {
            float dist = avg_cluster_distance(&clusters[i]) + avg_cluster_distance(&clusters[j]);
            if(dist < min_distance) {
                min_distance = dist;
                *a = i;
                *b = j;
            }
        }
    }
    return min_distance;
}

void merge_clusters(player_list_t *clusters, int a, int b) {
    int i;
    for(i = 0; i < clusters[b].count; i++) {
        clusters[a].players[clusters[a].count++] = clusters[b].players[i];
    }
    for(i = b; i < clusters->count-1; i++) {
        clusters[i] = clusters[i+1];
    }
    clusters->count--;
}

void print_clusters(player_list_t *clusters) {
    int i, j;
    for(i = 0; i < clusters->count; i++) {
        printf("Cluster #%d:\n", i+1);
        for(j = 0; j < clusters[i].count; j++) {
            printf("[%d,%d] Score: %d\n", clusters[i].players[j].x, clusters[i].players[j].y, clusters[i].players[j].score);
        }
        printf("\n");
    }
}

void play_matches(player_list_t *cluster, match_list_t *matches) {
    int i, j;
    for(i = 0; i < cluster->count; i++) {
        for(j = i+1; j < cluster->count; j++) {
            match_t match;
            match.players[0] = cluster->players[i];
            match.players[1] = cluster->players[j];
            match.round = matches->count + 1;
            matches->matches[matches->count++] = match;
        }
    }
}

int main() {
    player_list_t initial_cluster = {
        .players = {
            {1,1,100},
            {1,2,200},
            {2,1,150},
            {2,2,50},
            {5,5,300},
            {8,8,200}
        },
        .count = 6
    };
    player_list_t clusters = initial_cluster;
    match_list_t matches = {
        .matches = {},
        .count = 0
    };
    int round = 1;
    while(clusters.count > 1 && round <= MAX_ROUNDS) {
        printf("Round #%d\n", round);
        print_clusters(&clusters);
        int a,b;
        float dist = find_closest_clusters(&clusters, &a, &b);
        printf("Merging clusters #%d and #%d with distance %f\n", a+1, b+1, dist);
        merge_clusters(&clusters, a, b);
        play_matches(&clusters, &matches);
        round++;
    }
    printf("Final clusters:\n");
    print_clusters(&clusters);
    printf("Matches played:\n");
    int i;
    for(i = 0; i < matches.count; i++) {
        printf("Round #%d: [%d,%d] vs [%d,%d]\n", matches.matches[i].round,
            matches.matches[i].players[0].x, matches.matches[i].players[0].y,
            matches.matches[i].players[1].x, matches.matches[i].players[1].y);
    }
    return 0;
}