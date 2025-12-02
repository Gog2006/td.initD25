#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


typedef struct {
  int x;
  int y;
} Point;

int comparerDbl(const void* a, const void* b){
    const Point* p1 = (const Point*)a;
    const Point* p2 = (const Point*)b;
    if (p1->y != p2->y) {
        return p1->y - p2->y;
    }
    return p1->x - p2->x;
}

int comparerPoints(const void* a, const void* b) {
    const Point* p1 = (const Point*)a;
    const Point* p2 = (const Point*)b;

    if (p1->x != p2->x) {
        return p1->x - p2->x;
    }
    return p1->y - p2->y;
}


int main(){
    Point points[] = { {-8, 4}, {6, 6}, {-1, 1}, {1, -8}, {-6, -5}, {6, -9} };
    int n = sizeof(points) / sizeof(points[0]);
    printf("Affichage des points aleatoires et distance au centre:\n");
    for (int i = 0; i < n; i++) {
        double distance = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
        printf("(%d, %d)  --d-> %.1f\n", points[i].x, points[i].y, distance);
    }



    qsort(points, n, sizeof(Point), comparerPoints);

    printf("\nTri avec qsort par distance au centre\n");
    for (int i = 0; i < n; i++) {
        double distance = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
        printf("(%d, %d)  --d-> %.1f\n", points[i].x, points[i].y, distance);
    }

    return 0;

}
//compilation 
// gcc -std=c11 -Wall -Wextra -O2  -o /home/do501389/tdsinitD/td.initD25/td13/td13a/ex3 /home/do501389/tdsinitD/td.initD25/td13/td13a/ex3.c -lm
// execution
// /home/do501389/tdsinitD/td.initD25/td13/td13a/ex3

