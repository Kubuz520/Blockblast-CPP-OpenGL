#pragma once

#include <vector>

struct hitbox {
	double x;
	double y;
	double width;
	double heigth;
	int x_id;
	int y_id;
public:
	hitbox(double x, double y, double width, double heigth, int x_id = -1, int y_id = -1) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->heigth = heigth;
		this->x_id = x_id;
		this->y_id = y_id;
	}
};

// Wazne Variable
inline int block{};
inline bool PlaceBlock{ false };

// Ustawianie variabli
inline int x{};
inline int y{};

const int lenght{ 8 };
const int blocklenght{ 5 };
const int numberofblocks{ 20 };
inline int score{ 0 };
inline bool gameplaying{ true };

// Screen 
inline int ScreenWidth{ 900 };
inline int ScreenHeight{ 900 };

inline int ScreenWidthBufor{ -300 };
inline int ScreenHeightBufor{ -700 };

// Bloczki
const int BlockWidth{ 80 };

// Id bufforu Trojkata
inline unsigned int VBO_Empty;
// Id bufforu Kwadratu
inline unsigned int VBO_Square;

// Koordynaty Myszki
inline double x_mouse_pos;
inline double y_mouse_pos;

// Koordynaty trojkata
inline std::vector<float> vertices_empty = {

};
// Koordynaty trojkata
inline std::vector<float> vertices_square = {
	
};

// Hitboxy Dolnych Bloczkow
inline std::vector<hitbox> hitbox_bottom;