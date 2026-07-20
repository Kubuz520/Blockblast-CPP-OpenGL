
#include "Plansza.h"


// Pokazanie Planszy
void Plansza::Show() {
    
    for (int i{ 0 };i < lenght;i++) {
        if (i == 0) {
            //std::cout << "score: " <<(score);
        }
        //std::cout << "\n";
        for (int j{ 0 };j < lenght;j++) {
            //std::cout << plansza[i][j];

            double x_pos = (j * BlockWidth) + ScreenWidthBufor;
            double y_pos = ((lenght - 1 - i) * BlockWidth);

            // Grafika
            if (plansza[i][j] != 0) {
                std::vector<float> temp = GenerateSquareVertexes(x_pos, y_pos, BlockWidth);
                ChangeVerticesArray(VBO_Square, temp);
            }
            else {
                std::vector<float> temp = GenerateSquareVertexes(x_pos, y_pos, BlockWidth);
                ChangeVerticesArray(VBO_Empty, temp);
            }

            hitbox tempvar{ x_pos + ScreenWidth - (0.5*BlockWidth), y_pos + ScreenHeight + (0.5 * BlockWidth), static_cast<double>(BlockWidth), static_cast<double>(BlockWidth), j, i};
            hitbox_bottom.push_back(tempvar);
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