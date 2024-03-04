#include <stdio.h>

void Zad_1() 
{
    
    int zmienna = 10;

    int * wskaznik = &zmienna;

    * wskaznik = 20;

    printf("Wartosc zmiennej: %d\n", zmienna);
    printf("Wartosc wskaznika: %d\n", * wskaznik);

}

int main()
{
    
    Zad_1();

    return 0;

}
