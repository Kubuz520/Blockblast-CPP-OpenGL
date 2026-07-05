
#include "OpenGLFunctions.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0 , width, height);
	ScreenWidth = width;
	ScreenHeight = height;
}
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
		glfwSetWindowShouldClose(window, true);
}
std::vector<float> GenerateSquareVertexes(float x, float y, float width) {
	float X_point{ x / ScreenWidth };
	float Y_point{ y / ScreenHeight };
	float Width_point{ width / 1000 };
	float Height_point{ width / 1000 };
	
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