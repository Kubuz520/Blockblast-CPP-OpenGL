#pragma once

#include <vector>

// Wazne Variable
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