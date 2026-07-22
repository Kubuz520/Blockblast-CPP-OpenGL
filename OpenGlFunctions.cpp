
#include "OpenGLFunctions.h"


bool mouse_collider(hitbox block1) {
	double startx_point = block1.x;
	double endx_point = block1.x + (block1.width);
	double starty_point = block1.y;
	double endy_point = block1.y - (block1.heigth);

	if (x_mouse_pos > startx_point && x_mouse_pos < endx_point && y_mouse_pos < starty_point && y_mouse_pos > endy_point) {
		return true;
	}
	return false;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0 , width, height);
	ScreenWidth = width;
	ScreenHeight = height;
}
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
		glfwSetWindowShouldClose(window, true);
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		
		// Bloczki
		int tempblock{ block };
		for (int i{ 0 };i < hitbox_bottom.size();i++) {
			if (mouse_collider(hitbox_bottom[i]) == true) {
				// Klikniecie na dolny bloczek
				if (hitbox_bottom[i].y_id == BOTTOM_BLOCK_ID) {
					block = hitbox_bottom[i].x_id;
					ChangeScreen = true;
					break;
				}
				// Klikniecie na plansze
				else if (hitbox_bottom[i].y_id != BOTTOM_BLOCK_ID) {
					x = hitbox_bottom[i].x_id;
					y = hitbox_bottom[i].y_id;
					block = tempblock;
					PlaceBlock = true;
					ChangeScreen = true;
					break;
				}
				// Restart Gry
				else if (hitbox_bottom[i].x_id == RESTART_BUTTON_ID) {
					PonownaGra = true;
					break;
				}
			}
			// Odkliknięcie dolnego bloczka
			block = 0;
			ChangeScreen = true;
		}
	}
}
std::vector<float> GenerateSquareVertexes(float x, float y, float width) {
	float X_point{ x / ScreenWidth};
	float Y_point{ y / ScreenHeight};
	float Width_point{ width / ScreenWidth };
	float Height_point{ width / ScreenHeight };
	
	std::vector<float> Triangle = {
		X_point - Width_point / 2, Y_point + Height_point / 2, 0.0f,			// Lewy Gorny Rog
		X_point - Width_point / 2, Y_point - Height_point / 2, 0.0f,			// Lewy Dolny Rog
		X_point + Width_point / 2, Y_point + Height_point / 2, 0.0f,			// Prawy Gorny Rog

		X_point + Width_point / 2, Y_point - Height_point / 2, 0.0f,			// Prawy Dolny Rog
		X_point - Width_point / 2, Y_point - Height_point / 2, 0.0f,			// Lewy Dolny Rog
		X_point + Width_point / 2, Y_point + Height_point / 2, 0.0f				// Prawy Gorny Rog
	};
	return Triangle;
}

// funkcja dodająca arraya do arraya oraz funkcja updateujaca buffor
void ChangeVerticesArray(int VBO_Id, std::vector<float> InstertingArray) {
	if (VBO_Id == VBO_Square) {
		vertices_square.insert(vertices_square.end(), InstertingArray.begin(), InstertingArray.end());
	}
	else if (VBO_Id == VBO_Empty) {
		vertices_empty.insert(vertices_empty.end(), InstertingArray.begin(), InstertingArray.end());
	}
}
