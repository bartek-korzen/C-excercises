#include <stdio.h>

void Zad_2() 
{
    int array[10];
    for (int i = 0; i < 10; i++) 
    {
        array[i] = i;
    }
    int *pointer = array;

    printf("Tablica:\n");

    for (int i = 0; i < 10; i++) 
    {
        printf("%d, ", *pointer );
        pointer ++;
    }
    printf("\n");
}

int main()
{
    Zad_2();
    
    return 0;
}
