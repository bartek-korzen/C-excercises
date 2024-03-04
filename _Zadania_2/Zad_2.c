#include <stdio.h>

void modyfikuj(float *wskaznik) 
{
    *wskaznik *= 2; 
}

void Zad_2() 

{
    
    float zmienna = 3.5;

    modyfikuj(&zmienna);

    printf("Nowa wartosc zmiennej: %.2f\n", zmienna);

}

int main()
{
    
    Zad_2();

    return 0;
    
}