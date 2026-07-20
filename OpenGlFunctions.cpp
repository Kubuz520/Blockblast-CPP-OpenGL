
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
		
		// Dolne Bloczki
		for (int i{ 0 };i < hitbox_bottom.size();i++) {
			if (mouse_collider(hitbox_bottom[i]) == true) {
				// Klikniecie na dolny bloczek
				if (hitbox_bottom[i].y_id == -1) {
					block = hitbox_bottom[i].x_id;
					std::cout << "Bottom Block Pressed";
					break;
				}
				// Klikniecie na plansze
				else if (hitbox_bottom[i].x_id != -1 && hitbox_bottom[i].y_id != -1) {
					x = hitbox_bottom[i].x_id;
					y = hitbox_bottom[i].y_id;
					block = block;
					PlaceBlock = true;
					break;
				}
			}
			//block = 0;
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


//Block PrzypisanieBloczku(int i) {
//	Block tmp;
//	switch (i) {
//	case 0:
//		tmp = B1;
//		break;
//	case 1:
//		tmp = B2;
//		break;
//	case 2:
//		tmp = B3;
//		break;
//	}
//	return tmp;
//}
//
//void AddBlocks(int i, int rand) {
//
//	// Dodanie Bloku do jednego ze slotów
//	Block typbloczku = blocks[rand - 1];
//
//	switch (i) {
//	case 0:
//		B1 = typbloczku;
//		break;
//	case 1:
//		B2 = typbloczku;
//		break;
//	case 2:
//		B3 = typbloczku;
//		break;
//	}
//
//}
//
//bool SprawdzaniePoprawnosci(Plansza table, Block block, int x, int y) {
//
//	// sprawdza czy ustawienie jest poprawne
//	int x1{ 5 };
//	int y1{ 5 };
//
//	for (int i{ x };i > x - blocklenght;i--) {
//		x1--;
//		if (block.block1[y1][x1] == 1) {
//			if (i < 0) {
//				return false;
//			}
//		}
//		y1 = 5;
//		for (int j{ y };j > y - blocklenght;j--) {
//			y1--;
//			if (block.block1[y1][x1] == 1) {
//				if (i < 0 || j < 0) {
//					return false;
//				}
//				if (table.plansza[j][i] == 1) {
//					return false;
//				}
//			}
//		}
//	}
//
//	return true;
//}
//
//void Stawianie(int b, int x, int y, Plansza* table) {
//
//	// Bierze odpowiedni blok
//	Block block1 = PrzypisanieBloczku(b - 1);
//
//	// Wywolanie funkcji ktora sprawdza czy dany ruch jest poprawny
//	if (SprawdzaniePoprawnosci(*table, block1, x, y) == false) {
//		return;
//	}
//
//	// stawia blok jesli jest on legalny do postawienia
//	int x1{ 5 };
//	int y1{ 5 };
//
//	for (int i{ x };i > x - blocklenght;i--) {
//		x1--;
//		y1 = 5;
//		for (int j{ y };j > y - blocklenght;j--) {
//			y1--;
//			if (block1.block1[y1][x1] == 1) {
//				table->plansza[j][i] = block1.block1[y1][x1];
//			}
//		}
//	}
//
//	// Ustawia bloczki do uzycia na puste i zmienia booleany
//	Pusty p;
//	switch (b) {
//	case 1:
//		B1 = p;
//		B1Used = true;
//		break;
//	case 2:
//		B2 = p;
//		B2Used = true;
//		break;
//	case 3:
//		B3 = p;
//		B3Used = true;
//		break;
//	}
//
//}
//
//void Zwyciestwo(Plansza* table) {
//
//	int x{ 0 };
//	int y{ 0 };
//	int tablex[lenght]{};
//	int iloscx{ 0 };
//	int tabley[lenght]{};
//	int iloscy{ 0 };
//
//	// Wykrywanie na Plaszyczyznie X
//	for (int i{ 0 };i < lenght;i++) {
//		x = 0;
//		for (int j{ 0 };j < lenght;j++) {
//			if (table->plansza[j][i] == 0) {
//				continue;
//			}
//			x++;
//		}
//		if (x == 8) {
//			tablex[iloscx] = i;
//			iloscx += 1;
//		}
//	}
//
//	// Wykrywanie na plaszyczyznie Y
//	for (int i{ 0 };i < lenght;i++) {
//		y = 0;
//		for (int j{ 0 };j < lenght;j++) {
//			if (table->plansza[i][j] == 0) {
//				continue;
//			}
//			y++;
//		}
//		if (y == 8) {
//			tabley[iloscy] = i;
//			iloscy += 1;
//		}
//	}
//
//	// Zamiana tablicy
//	for (int t{ 0 };t < iloscy;t++) {
//		score += 200;
//		for (int i{ 0 };i < lenght;i++) {
//			table->plansza[tabley[t]][i] = 0;
//		}
//	}
//	for (int t{ 0 };t < iloscx;t++) {
//		score += 200;
//		for (int i{ 0 };i < lenght;i++) {
//			table->plansza[i][tablex[t]] = 0;
//		}
//	}
//
//	iloscy = 0;
//	iloscx = 0;
//
//
//}
//
//bool Przegrana(Plansza table) {
//	for (int b{ 0 };b < 3;b++) {
//
//		Block block;
//		switch (b) {
//		case 0:
//			if (B1Used == true) {
//				continue;
//			}
//			block = B1;
//			break;
//		case 1:
//			if (B2Used == true) {
//				continue;
//			}
//			block = B2;
//			break;
//		case 2:
//			if (B3Used == true) {
//				continue;
//			}
//			block = B3;
//			break;
//		}
//
//
//		for (int i{ 0 };i < lenght;i++) {
//			for (int j{ 0 };j < lenght;j++) {
//				if (SprawdzaniePoprawnosci(table, block, i, j) == true) {
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//
//// Funkcja Odpowiedzialna za restart gry
//void KolejnaGra(Plansza* table) {
//	if (gameplaying == true) {
//		return;
//	}
//
//	int PonownaGra{};
//
//	std::cout << "\n";
//	std::cout << "Chcesz Zagrać Jeszcze Raz? (1-Tak)";
//	std::cin >> PonownaGra;
//
//	if (PonownaGra == 1) {
//		table->Reset();
//		score = 0;
//		gameplaying = true;
//	}
//}