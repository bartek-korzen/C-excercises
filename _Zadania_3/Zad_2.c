#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber() 
{
    return rand() % 100 + 1;
}

// Funkcja do tworzenia dynamicznie alokowanej macierzy o zadanych rozmiarach i wypełniania jej losowymi liczbami.
int** generateMatrix(int rows, int columns) 
{
    int** martix = (int**)malloc(rows * sizeof(int*));

    if (martix == NULL) 
    {
        fprintf(stderr, "Błąd alokacji pamięci dla macierzy.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) 
    {
        martix[i] = (int*)malloc(columns * sizeof(int));

        if (martix[i] == NULL) 
        {
            fprintf(stderr, "Błąd alokacji pamięci dla wiersza %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }

    return martix;
}

// Funkcja do wypełniania macierzy losowymi liczbami.
void fillMatrix(int** martix, int rows, int columns) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            martix[i][j] = generateRandomNumber();
        }
    }
}

// Funkcja do wyświetlania zawartości macierzy.
void displayMatrix(int** martix, int rows, int columns) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            printf("%d ", martix[i][j]);
        }
        printf("\n");
    }
}

// Funkcja do zwalniania zaalokowanej pamięci dla macierzy.
void releaseMartix(int** martix, int rows) 
{
    for (int i = 0; i < rows; i++) 
    {
        free(martix[i]);
    }
    free(martix);
}

void Zad_2() 
{
    srand(time(NULL));

    int rows, columns;

    printf("Podaj liczbę wierszy macierzy: ");
    scanf("%d", &rows);

    printf("Podaj liczbę kolumn macierzy: ");
    scanf("%d", &columns);

    int** martix = generateMatrix(rows, columns);

    fillMatrix(martix, rows, columns);

    printf("Zawartość macierzy:\n");
    displayMatrix(martix, rows, columns);

    releaseMartix(martix, rows);

}

int main()
{
    
    Zad_2();
    
    return 0;
    
}