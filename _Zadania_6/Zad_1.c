#include <stdio.h>

union Data 
{
    int integer_number;
    float floating_number;
    char single_character;
};

void Zad_1() 
{
    union Data data;

    data.integer_number = 62;
    printf("Liczba całkowita: %d\n", data.integer_number);

    data.floating_number = 5.23;
    printf("Liczba zmiennoprzecinkowa: %.2f\n", data.floating_number);

    data.single_character = 'B';
    printf("Znak: %c\n", data.single_character);
}

int main()
{
    Zad_1();
    
    return 0;
}
