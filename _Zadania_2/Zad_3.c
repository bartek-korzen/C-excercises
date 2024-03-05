#include <stdio.h>

typedef struct Point 
{
  int x;
  int y;
} Point;

void changeCoordinates(Point *point, int newX, int newY) 
{
  point -> x = newX;
  point -> y = newY;
  printf("Zmiana współrzędnych punktu\n");
}

void printPoint(Point point) 
{
  printf("Współrzędne punktu: (%d, %d)\n", point.x, point.y);
}

typedef struct Rectangle 
{
  Point left;
  Point right;
}  Rectangle;

// Funkcja licząca pole i obwód prostokąta
void calculateAreaAndPerimeter(Rectangle rectangle) 
{
  int width = rectangle.right.x - rectangle.left.x;
  int height = rectangle.right.y - rectangle.left.y;
  int area = width * height;
  int perimeter = 2 * (width + height);
  printf("Pole prostokąta: %d\n", area);
  printf("Obwód prostokąta: %d\n", perimeter);
}

void Zad_3() 
{
  Point point;

  point.x = 10;
  point.y = 20;

  printPoint(point);

  // Zmiana współrzędnych za pomocą funkcji
  changeCoordinates(&point, 30, 40);
  
  printPoint(point);

  Rectangle rectangle;

  rectangle.left.x = 0;
  rectangle.left.y = 0;
  rectangle.right.x = 5;
  rectangle.right.y = 10;

  calculateAreaAndPerimeter(rectangle);

}

int main()
{
    Zad_3();
    
    return 0;
}

