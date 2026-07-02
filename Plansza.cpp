
#include "Plansza.h"
#include <iostream>

// Pokazanie Planszy
void Plansza::Show() {
    for (int i{ 0 };i < lenght;i++) {
        if (i == 0) {
            std::cout << "score: " <<(score);
        }
        std::cout << "\n";
        for (int j{ 0 };j < lenght;j++) {
            std::cout << plansza[i][j];
        }
    }
}
// Restart Planszy
void Plansza::Reset() {
    for (int i{ 0 };i < lenght;i++) {
        for (int j{ 0 };j < lenght;j++) {
            plansza[i][j] = 0;
        }
    }
}

// Generowanie Planszy
Plansza::Plansza() {
    Reset();
}