#include <stdio.h>
#include <string.h>

#include <math.h>

typedef struct Point {
  char PointName[100];
  double x;
  double y;
} Point;
void printPoint(Point p) {
    


int main (){

    Point p1, p2;
    printf("Entrez la lettre et les coordonnées du 1er point:\n");
    scanf(" %c %lf %lf", p1.PointName, &p1.x, &p1.y);
    printf("La lettre du 1er point est: %c\n", p1.PointName[0]);
    printf("%0.2lf\n", p1.x);
    printf("%0.2lf\n", p1.y);
    printf("%c(%.2lf, %.2lf)\n", p1.PointName[0], p1.x, p1.y);
    printf("Entrez la lettre et les coordonnées du 2e point:\n");
    scanf(" %c %lf %lf", p2.PointName, &p2.x, &p2.y);
    printf(" %c\n", p2.PointName[0]);
    printf("%0.2lf\n", p2.x);
    printf("%0.2lf\n", p2.y);   
    printf("%c(%.2lf, %.2lf)\n", p2.PointName[0], p2.x, p2.y);
    printf("La distance entre les deux points est: %.2lf\n", sqrtf((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.);
    return 0;
}
