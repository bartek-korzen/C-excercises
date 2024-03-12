#include <stdio.h>

// Funkcja do obliczania współczynnika Newtona.
int newtonSymbol(int n, int k) 
{
    if (k == 0 || k == n) 
    {
        return 1;
    } 
    
    else 
    {
        return newtonSymbol(n - 1, k - 1) + newtonSymbol(n - 1, k);
    }
}

// Funkcja do wyświetlania trójkąta Pascala o zadanej wysokości.
void pascalsTriangle(int height) 
{
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            printf("%d ", newtonSymbol(i, j));
        }
        printf("\n");
    }
}

void Zad_1() 
{
    int height;
    
    printf("Podaj wysokość trójkąta Pascala: ");
    scanf("%d", &height);

    pascalsTriangle(height);

}

int main()
{
    
    Zad_1();
    
    return 0;
}
