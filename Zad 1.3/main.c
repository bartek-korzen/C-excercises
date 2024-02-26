#include <stdio.h>

// Funkcja obliczająca silnie
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Funkcja obliczająca silnie dla wszystkich liczb w tablicy 'array'
void count_factorial(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Silnia z %d: %d\n", array[i], factorial(array[i]));
    }
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(array) / sizeof(array[0]);

    count_factorial(array, n);

    return 0;
}
