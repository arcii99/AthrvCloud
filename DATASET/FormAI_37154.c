//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point {
   int x,y;
};

typedef struct triangle {
   struct point A,B,C;
}Triangle;

typedef struct circle {
   struct point center;
   int radius;
}Circle;

double distance(struct point A, struct point B) {
   return sqrt(pow((B.x-A.x),2)+pow((B.y-A.y),2));
}

Triangle* get_triangle_from_points(struct point A,struct point B,struct point C) {
   Triangle* t=(Triangle*) malloc(sizeof(Triangle));
   t->A=A;
   t->B=B;
   t->C=C;
   return t;
}

int is_triangle(Triangle* t) {
   double ab=distance(t->A,t->B);
   double ac=distance(t->A,t->C);
   double bc=distance(t->B,t->C);
   if((ab+ac>bc) && (ab+bc>ac) && (ac+bc>ab))
      return 1;
   else
      return 0;
}

Circle* get_circle_from_points(struct point A,struct point B,struct point C) {
   double a,b,c,d,e,f,g;
   Circle* c1=(Circle*) malloc(sizeof(Circle));
   a=A.x; b=A.y;
   c=B.x; d=B.y;
   e=C.x; f=C.y;
   g=2*((c-a)*(f-d)-(b-a)*(e-c));
   if(g==0){
      c1->center.x=c1->center.y=c1->radius=0;
      return c1;
   }
   c1->center.x=((f-d)*(pow(c,2)-pow(a,2)+pow(d,2)-pow(b,2))+(b-f)*(pow(e,2)-pow(c,2)+pow(f,2)-pow(d,2)))/(g);
   c1->center.y=((a-c)*(pow(e,2)-pow(c,2)+pow(f,2)-pow(d,2))+(c-e)*(pow(a,2)-pow(b,2)+pow(c,2)-pow(d,2)))/(g);
   c1->radius=distance(c1->center,A);
   return c1;
}

int main() {
   struct point A,B,C;
   printf("Enter coordinates of A:\n");
   scanf("%d%d",&A.x,&A.y);
   printf("Enter coordinates of B:\n");
   scanf("%d%d",&B.x,&B.y);
   printf("Enter coordinates of C:\n");
   scanf("%d%d",&C.x,&C.y);
   
   Triangle* t=get_triangle_from_points(A,B,C);
   if(!is_triangle(t))
      printf("Points entered do not form a triangle!\n");
   else {
      printf("Triangle is formed by:\nA(%d,%d)\nB(%d,%d)\nC(%d,%d)\n",t->A.x,t->A.y,t->B.x,t->B.y,t->C.x,t->C.y);
      
      Circle* c=get_circle_from_points(A,B,C);
      printf("The circle that passes through the points is:\nCenter: (%d,%d)\nRadius: %d\n",c->center.x,c->center.y,c->radius);
   }
   return 0;
}