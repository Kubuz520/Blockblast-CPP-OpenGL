#pragma once

#include <Glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Global.h"


bool mouse_collider(hitbox block1);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
std::vector<float> GenerateSquareVertexes(float x, float y, float width);
void ChangeVerticesArray(int VBO_Id, std::vector<float> InstertingArray);