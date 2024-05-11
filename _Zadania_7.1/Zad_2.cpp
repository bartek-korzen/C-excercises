#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

// Struktura przechowująca liczbę kostek każdego koloru w danej grze
struct CubeSet
{
    int red;
    int green;
    int blue;
};

int loadData(const char *filename, CubeSet *gameData[], int *numGames) 
{
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Nie można otworzyć pliku input_2.txt" << std::endl;
        return 0;
    }

    int maxGames = 100; 
    *gameData = new CubeSet[maxGames];
    if (*gameData == nullptr) 
    {
        std::cerr << "Błąd alokacji pamięci" << std::endl;
        file.close();
        return 0;
    }

    int gameIndex = 0;
    std::string line;

    while (std::getline(file, line)) 
    {
        if (line.substr(0, 4) == "Game") 
        {
            // Nowa gra, więc inkrementujemy gameIndex
            gameIndex++;
            continue;
        }

        // Analiza danych kostek w danej grze
        int red, green, blue;
        if (sscanf(line.c_str(), "%d green, %d blue, %d red;", &green, &blue, &red) == 3) 
        {
            (*gameData)[gameIndex - 1].red = red;
            (*gameData)[gameIndex - 1].green = green;
            (*gameData)[gameIndex - 1].blue = blue;
        }
    }

    *numGames = gameIndex;
    file.close();
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
    CubeSet *gameData = nullptr;
    int numGames = 0;

    if (!loadData("input_2.txt", &gameData, &numGames)) 
    {
        return 1;
    }

    int possibleGames = calculatePossibleGames(gameData, numGames);
    std::cout << "Suma identyfikatorów możliwych gier: " << possibleGames << std::endl;

    int minimumCubeSetPower = calculateMinimumCubeSetPower(gameData, numGames);
    std::cout << "Suma mocy minimalnych zestawów kostek: " << minimumCubeSetPower << std::endl;

    delete[] gameData;
    
    return 0;
}

int main()
{
    Zad_2();
    return 0;
}
