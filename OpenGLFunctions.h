#pragma once

#include <Glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Global.h"
#include "Bloczek.h"
#include "Plansza.h"
//
//Block PrzypisanieBloczku(int i);
//void AddBlocks(int i, int rand);
//bool SprawdzaniePoprawnosci(Plansza table, Block block, int x, int y);
//void Stawianie(int b, int x, int y, Plansza* table);
//void Zwyciestwo(Plansza* table);
//bool Przegrana(Plansza table);
//void KolejnaGra(Plansza* table);

bool mouse_collider(hitbox block1);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
std::vector<float> GenerateSquareVertexes(float x, float y, float width);
void ChangeVerticesArray(int VBO_Id, std::vector<float> InstertingArray);