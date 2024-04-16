#include <stdio.h>

int multiplication(int a, int b) 
{
    return a * b;
}

int addition(int a, int b) 
{
    return a + b;
}

int subtraction(int a, int b) 
{
    return a - b;
}

void Zad_3() 
{
    int (*pointer)(int, int);

    int x, y;
    char operation;

    printf("Podaj dwie liczby całkowite (oddzielone spacją): ");
    scanf("%d %d", &x, &y);

    printf("Wybierz jedną z podanych operacji (+, *, -): ");
    scanf(" %c", &operation);

    switch (operation) 
    {
        case '*':
            pointer = &multiplication;
            break;
        case '+':
            pointer = &addition;
            break;
        case '-':
            pointer = &subtraction;
            break;
        default:
            printf("Błąd - niepoprawna operacja.\n");
            return;
    }

    printf("Wynik: %d\n", (*pointer)(x, y));
}

int main()
{
    Zad_3();
    
    return 0;
}
