#include <stdio.h>

void swap(int *a, int *b) 
{
    int temporary = *a;
    *a = *b;
    *b = temporary;
}

void generatePermutations(int array[], int start, int end) 
{
    
    if (start == end) 
    {
        for (int i = 0; i <= end; i++) 
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    } 
    
    else 
    {
        for (int i = start; i <= end; i++) 
        {
            // Zamiana miejscami elementów start i i
            swap(&array[start], &array[i]);
            // Generowanie permutacji dla pozostałej części ciągu
            generatePermutations(array, start + 1, end);
            // Powrót do początkowego układu elementów
            swap(&array[start], &array[i]);
        }
    }
}

void Zad_3() 
{
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);
    generatePermutations(array, 0, n - 1);
}

int main()
{
    Zad_3();

    return 0;
}