#include <stdio.h>

int binarySearch(int array[], int left, int right, int target) 
{
    if (right >= left) 
    {
        int mid = left + (right - left) / 2;

        // Jeśli element jest na środku
        if (array[mid] == target)
            return mid;

        // Jeśli element jest mniejszy niż środkowy, szukaj w lewej połowie
        else if (array[mid] > target)
            return binarySearch(array, left, mid - 1, target);

        // Jeśli element jest większy niż środkowy, szukaj w prawej połowie
        return binarySearch(array, mid + 1, right, target);
    }

    // Jeśli element nie został znaleziony
    return -1;
}

void Zad_2() 
{
    int array[] = {1, 6, 7, 12, 16, 23, 41, 53, 66, 95};
    int n = sizeof(array) / sizeof(array[0]);
    int target = 23;
    int result = binarySearch(array, 0, n - 1, target);
    
    if (result == -1)
        printf("Element %d nie został znaleziony.\n", target);
    else
        printf("Element %d znajduje się na %d miejscu.\n", target, result+1);    
}

int main()
{
    Zad_2();

    return 0;
}

