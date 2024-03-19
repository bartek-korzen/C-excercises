#include <stdio.h>

int factorial(int n) 
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

void Zad_1() 
{
    int number;
    
    printf("Podaj liczbę całkowitą: ");
    scanf("%d", &number);

    printf("Silnia z %d wynosi: %d\n", number, factorial(number));
}

int main()
{
    Zad_1();
    
    return 0;
}