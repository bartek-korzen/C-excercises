#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktura przechowująca liczbę kostek każdego koloru w danej grze
typedef struct 
{
    int red;
    int green;
    int blue;
} CubeSet;

int loadData(const char *filename, CubeSet *gameData[], int *numGames) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        perror("Nie można otworzyć pliku input_2.txt");
        return 0;
    }

    int maxGames = 100; 
    *gameData = malloc(maxGames * sizeof(CubeSet));
    if (*gameData == NULL) 
    {
        perror("Błąd alokacji pamięci");
        fclose(file);
        return 0;
    }

    int gameIndex = 0;
    char line[100]; 

    while (fgets(line, sizeof(line), file)) 
    {
        if (strncmp(line, "Game", 4) == 0) 
        {
            // Nowa gra, więc inkrementujemy gameIndex
            gameIndex++;
            continue;
        }

        // Analiza danych kostek w danej grze
        int red, green, blue;
        if (sscanf(line, "%d green, %d blue, %d red;", &green, &blue, &red) == 3) 
        {
            (*gameData)[gameIndex - 1].red = red;
            (*gameData)[gameIndex - 1].green = green;
            (*gameData)[gameIndex - 1].blue = blue;
        }
    }

    *numGames = gameIndex;
    fclose(file);
    return 1;
}

// Funkcja do obliczania sumy identyfikatorów gier (pierwsza część zadania)
int calculatePossibleGames(CubeSet gameData[], int numGames) 
{
    int possibleGames = 0;
    const int maxRed = 12, maxGreen = 13, maxBlue = 14;

    for (int i = 0; i < numGames; i++) 
    {
        if (gameData[i].red <= maxRed && gameData[i].green <= maxGreen && gameData[i].blue <= maxBlue) {
            possibleGames += i + 1;
        }
    }

    return possibleGames;
}

// Funkcja do obliczania sumy mocy minimalnych zestawów kostek (druga część zadania)
int calculateMinimumCubeSetPower(CubeSet gameData[], int numGames) 
{
    int totalPower = 0;

    for (int i = 0; i < numGames; i++) 
    {
        int redPower = gameData[i].red * gameData[i].green * gameData[i].blue;
        totalPower += redPower;
    }

    return totalPower;
}

int Zad_2() 
{
    CubeSet *gameData;
    int numGames;

    if (!loadData("input_2.txt", &gameData, &numGames)) 
    {
        return 1;
    }

    int possibleGames = calculatePossibleGames(gameData, numGames);
    printf("Suma identyfikatorów możliwych gier: %d\n", possibleGames);

    int minimumCubeSetPower = calculateMinimumCubeSetPower(gameData, numGames);
    printf("Suma mocy minimalnych zestawów kostek: %d\n", minimumCubeSetPower);

    free(gameData);
}

int main()
{
    Zad_2();
    
    return 0;
}
