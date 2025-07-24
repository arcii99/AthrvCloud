//FormAI DATASET v1.0 Category: Fractal Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 255

typedef struct {
  double x, y;
} point;

typedef struct {
  point ul, lr;
} rect;

typedef struct {
  point c;
  double r;
} circle;

typedef struct node {
  rect r;
  bool is_leaf;
  circle c;
  struct node *children[4];
} node;

node *create_node(rect r) {
  node *new_node = malloc(sizeof(node));
  new_node->r = r;
  new_node->is_leaf = true;
  return new_node;
}

void destroy_tree(node *root) {
  for(int i = 0; i < 4; i++) {
    if(root->children[i] != NULL) {
      destroy_tree(root->children[i]);
    }
  }
  free(root);
}

bool contains(rect r, point p) {
  return (p.x >= r.ul.x && p.x < r.lr.x && p.y >= r.ul.y && p.y < r.lr.y);
}

bool overlaps(rect r1, rect r2) {
  return !(r1.ul.x > r2.lr.x || r1.lr.x < r2.ul.x || r1.ul.y > r2.lr.y || r1.lr.y < r2.ul.y);
}

void draw_circle(circle c, int iterations[][WIDTH]) {
  for(int i = ceil(c.c.y - c.r); i < floor(c.c.y + c.r); i++) {
    for(int j = ceil(c.c.x - c.r); j < floor(c.c.x + c.r); j++) {
      point p = {j, i};
      int distance = sqrt(pow(p.x - c.c.x, 2) + pow(p.y - c.c.y, 2));
      if(distance < c.r) {
        iterations[i][j]++;
      }
    }
  }
}

void print_iterations(int iterations[][WIDTH]) {
  FILE *f = fopen("output.pgm", "w");
  fprintf(f, "P2\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_ITERATIONS);
  for(int i = 0; i < HEIGHT; i++) {
    for(int j = 0; j < WIDTH; j++) {
      fprintf(f, "%d ", iterations[i][j]);
    }
    fprintf(f, "\n");
  }
  fclose(f);
}

void insert_circle(node *root, circle c, int iterations[][WIDTH]) {
  if(!overlaps(root->r, (rect){{c.c.x - c.r, c.c.y - c.r}, {c.c.x + c.r, c.c.y + c.r}})) {
    return; // Circle does not overlap node
  }
  if(root->is_leaf) {
    if(root->c.r == 0) {
      root->c = c;
    }
    else {
      // Split node into four quadrants and add circle to appropriate quadrant
      rect ul = {root->r.ul, {root->r.ul.x + (root->r.lr.x - root->r.ul.x) / 2, root->r.ul.y + (root->r.lr.y - root->r.ul.y) / 2}};
      rect ur = {{root->r.ul.x + (root->r.lr.x - root->r.ul.x) / 2, root->r.ul.y}, {root->r.lr.x, root->r.ul.y + (root->r.lr.y - root->r.ul.y) / 2}};
      rect ll = {{root->r.ul.x, root->r.ul.y + (root->r.lr.y - root->r.ul.y) / 2}, {root->r.ul.x + (root->r.lr.x - root->r.ul.x) / 2, root->r.lr.y}};
      rect lr = {{root->r.ul.x + (root->r.lr.x - root->r.ul.x) / 2, root->r.ul.y + (root->r.lr.y - root->r.ul.y) / 2}, root->r.lr};
      node *children[4] = {create_node(ul), create_node(ur), create_node(ll), create_node(lr)};
      for(int i = 0; i < 4; i++) {
        root->children[i] = children[i];
      }
      root->is_leaf = false;
      insert_circle(root, root->c, iterations);
      root->c = (circle){{0, 0}, 0};
      insert_circle(root, c, iterations);
    }
  }
  else {
    for(int i = 0; i < 4; i++) {
      insert_circle(root->children[i], c, iterations);
    }
  }
}

int main() {
  node *root = create_node((rect){{0, 0}, {WIDTH, HEIGHT}});
  int iterations[HEIGHT][WIDTH] = {0};
  srand(time(NULL));
  for(int i = 0; i < 50; i++) {
    point c = {(double)rand() / RAND_MAX * WIDTH, (double)rand() / RAND_MAX * HEIGHT};
    double r = (double)rand() / RAND_MAX * 100 + 10;
    circle new_circle = {c, r};
    insert_circle(root, new_circle, iterations);
    draw_circle(new_circle, iterations);
  }
  print_iterations(iterations);
  destroy_tree(root);
  return 0;
}