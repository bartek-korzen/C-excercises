#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calculateEnergyValue(char *line) 
{
    int length = strlen(line);
    int firstDigit = -1, lastDigit = -1;

    for (int i = 0; i < length; i++) 
    {
        if (isdigit(line[i])) 
        {
            firstDigit = line[i] - '0';
            break;
        }
    }

    for (int i = length - 1; i >= 0; i--) 
    {
        if (isdigit(line[i])) 
        {
            lastDigit = line[i] - '0';
            break;
        }
    }
    
    // Sprawdź czy pierwsza i ostatnia cyfra zostały znalezione
    if (firstDigit != -1 && lastDigit != -1) 
    {
        return firstDigit * 10 + lastDigit;
    } 
    else 
    {
        return 0;
    }
}

int Zad_1() 
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) 
    {
        perror("Nie można otworzyć pliku input.txt");
        return 1;
    }

    int totalEnergy = 0;
    char line[100]; 

    while (fgets(line, sizeof(line), file)) 
    {
        char *pos;
        if ((pos = strchr(line, '\n')) != NULL) 
        {
            *pos = '\0';
        }

        int energyValue = calculateEnergyValue(line);
        totalEnergy += energyValue;
    }

    fclose(file);
    printf("Suma wszystkich wartości energetycznych: %d\n", totalEnergy);
}

int main()
{
    Zad_1();
    
    return 0;
}
