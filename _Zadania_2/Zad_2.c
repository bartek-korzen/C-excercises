#include <stdio.h>

void modyfikuj(float *wskaznik) 
{
    *wskaznik *= 2; 
}

void Zad_2() 

{
    
    float zmienna = 3.5;
    
    printf("Początkowa wartość zmiennej: %.2f\n", zmienna);

    modyfikuj(&zmienna);

    printf("Nowa wartość zmiennej: %.2f\n", zmienna);

}

int main()
{
    Zad_2();

    return 0;
}