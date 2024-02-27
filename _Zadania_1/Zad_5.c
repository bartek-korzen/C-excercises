#include <stdio.h>

int sumOfMultiples(int number) {
    if (number < 0) // Jeśli liczba jest ujemna, zwróć 0
        return 0;

    int sum = 0;
    for (int i = 3; i < number; i++) {
        if (i % 3 == 0 || i % 5 == 0) 
            sum += i;
    }
    return sum;
}

void Zad_5() {
    int number;
    printf("Podaj liczbe: ");
    scanf("%d", &number);

    int result = sumOfMultiples(number);
    printf("Suma wszystkich wielokrotnosci 3 lub 5 poniżej %d wynosi: %d\n", number, result);
}

int main()
{

Zad_5();

return 0;

}

