
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <random>
#include <iostream>
#include <vector>
#include "Global.h"
#include "Plansza.h"
#include "Bloczek.h"
#include "OpenGLFunctions.h"


Plansza table;

// Tworzenie Listy wszystkich mozliwych bloczkow
DuzyKwadrat x1;
MalyKwadrat x2;
PodluznyProstokat x3;
PionowyProstakat x4;
PiecPionowe x5;
PiecPoziome x6;
CzteryPionowe x7;
CzteryPoziome x8;
L1 x9;
L2 x10;
L3 x11;
L4 x12;
DL1 x13;
DL2 x14;
DL3 x15;
DL4 x16;
P1 x17;
P2 x18;
P3 x19;
P4 x20;

Block blocks[] = {
x1, x2, x3, x4,
x5, x6, x7, x8,
x9, x10, x11, x12,
x13, x14, x15, x16,
x17, x18, x19, x20
};

// Trzy bloczki ktore sa mozliwe do uzycia
Block B1;
Block B2;
Block B3;

// Variable do 3 bloczkow odnosnie tego czy sa zuzyte czy nie
bool B1Used{ true };
bool B2Used{ true };
bool B3Used{ true };

// Variable Graficzne ###########################################

// Shader punktów (najprostszy mozliwy)
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

// Shader Kolorów (fragment shader)
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
"}\0";

const char* fragmentShaderSourceEmpty = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(0.8f,0.8f,0.8f,1.0f);\n"
"}\0";

// Id shaderu punktów
unsigned int VertexShader;
// Id fragment shaderu
unsigned int fragmentShader;
unsigned int fragmentShaderEmpty;
// Id programu shaderów
unsigned int shaderProgram;
unsigned int shaderProgramEmpty;

// Id VAO Trojkata
unsigned int VAO_Empty;
// Id VAO Kwadratu
unsigned int VAO_Square;

// Funkcja Rysujaca to co chemy 
void Draw(int Id, int ShaderId) {
	if (Id == VAO_Empty) {
		glBindVertexArray(VAO_Empty);
		glUseProgram(ShaderId);
		glDrawArrays(GL_TRIANGLES, 0, vertices_empty.size());
	}
	else if (Id == VAO_Square) {
		glBindVertexArray(VAO_Square);
		glUseProgram(ShaderId);
		glDrawArrays(GL_TRIANGLES, 0, vertices_square.size());
	}
}

void UpdateBuffor(int VBO_Id) {
	if (VBO_Id == VBO_Square) {
		glBindBuffer(GL_ARRAY_BUFFER, VBO_Square);
		glBufferData(GL_ARRAY_BUFFER, vertices_square.size() * sizeof(float), vertices_square.data(), GL_STATIC_DRAW);
	}
	if (VBO_Id == VBO_Empty) {
		glBindBuffer(GL_ARRAY_BUFFER, VBO_Empty);
		glBufferData(GL_ARRAY_BUFFER, vertices_empty.size() * sizeof(float), vertices_empty.data(), GL_STATIC_DRAW);
	}
}

void AddBlocks(int i, int rand) {

	// Dodanie Bloku do jednego ze slotów
	Block typbloczku = blocks[rand - 1];

	switch (i) {
	case 0:
		B1 = typbloczku;
		break;
	case 1:
		B2 = typbloczku;
		break;
	case 2:
		B3 = typbloczku;
		break;
	}

}

void GenerateBlocks() {
	for (int i{ 0 };i < 3;i++) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(1, numberofblocks);

		AddBlocks(i, dist(gen));
	}
	B1Used = false;
	B2Used = false;
	B3Used = false;
}

Block PrzypisanieBloczku(int i) {
	Block tmp;
	switch (i) {
	case 0:
		tmp = B1;
		break;
	case 1:
		tmp = B2;
		break;
	case 2:
		tmp = B3;
		break;
	}
	return tmp;
}

void Generacja(Plansza table,int* b, int* x, int* y) {
	
	// Generuje nowe 3 bloczki jesli sa zuzyte
	if (B1Used == true && B2Used == true && B3Used == true) {
		GenerateBlocks();
	}

	// Pokazuje Bloczki i plansze
	vertices_square.clear();
	vertices_empty.clear();
	hitbox_bottom.clear();

	table.Show();
	
	B1.Show(1);
	B2.Show(2);
	B3.Show(3);
	
	UpdateBuffor(VBO_Square);
	UpdateBuffor(VBO_Empty);

}

bool SprawdzaniePoprawnosci(Plansza table, Block block, int x, int y) {

	// sprawdza czy ustawienie jest poprawne
	int x1{ 5 };
	int y1{ 5 };

	for (int i{ x };i > x - blocklenght;i--) {
		x1--;
		if (block.block1[y1][x1] == 1) {
			if (i < 0) {
				return false ;
			}
		}
		y1 = 5;
		for (int j{ y };j > y - blocklenght;j--) {
			y1--;
			if (block.block1[y1][x1] == 1) {
				if (i < 0 || j < 0) {
					return false ;
				}
				if (table.plansza[j][i] == 1) {
					return false ;
				}
			}
		}
	}

	return true;
}

void Stawianie(int b, int x, int y, Plansza* table) {

	// Bierze odpowiedni blok
	Block block1 = PrzypisanieBloczku(b - 1);
	
	// Wywolanie funkcji ktora sprawdza czy dany ruch jest poprawny
	if (SprawdzaniePoprawnosci(*table, block1, x, y) == false) {
		return;
	}
	
	// stawia blok jesli jest on legalny do postawienia
	int x1{5};
	int y1{5};

	for (int i{ x };i > x - blocklenght;i--) {
		x1--;
		y1 = 5;
		for (int j{ y };j > y - blocklenght;j--) {
			y1--;
			if (block1.block1[y1][x1] == 1) {
				table->plansza[j][i] = block1.block1[y1][x1];
			}
		}
	}

	// Ustawia bloczki do uzycia na puste i zmienia booleany
	Pusty p;
	switch (b) {
	case 1:
		B1 = p;
		B1Used = true;
		break;
	case 2:
		B2 = p;
		B2Used = true;
		break;
	case 3:
		B3 = p;
		B3Used = true;
		break;
	}
	
}

void Zwyciestwo(Plansza* table) {

	int x{ 0 };
	int y{ 0 };
	int tablex[lenght]{};
	int iloscx{0};
	int tabley[lenght]{};
	int iloscy{ 0 };

	// Wykrywanie na Plaszyczyznie X
	for (int i{ 0 };i < lenght;i++) {
		x = 0;
		for (int j{ 0 };j < lenght;j++) {
			if (table->plansza[j][i] == 0) {
				continue;
			}
			x++;
		}
		if (x == 8) {
			tablex[iloscx] = i;
			iloscx += 1;
		}
	}

	// Wykrywanie na plaszyczyznie Y
	for (int i{ 0 };i < lenght;i++) {
		y = 0;
		for (int j{ 0 };j < lenght;j++) {
			if (table->plansza[i][j] == 0) {
				continue;
			}
			y++;
		}
		if (y == 8) {
			tabley[iloscy] = i;
			iloscy += 1;
		}
	}

	// Zamiana tablicy
	for (int t{ 0 };t < iloscy;t++) {
		score += 200;
		for (int i{ 0 };i < lenght;i++) {
			table->plansza[tabley[t]][i] = 0;
		}
	}
	for (int t{ 0 };t < iloscx;t++) {
		score += 200;
		for (int i{ 0 };i < lenght;i++) {
			table->plansza[i][tablex[t]] = 0;
		}
	}

	iloscy = 0;
	iloscx = 0;
	

}

bool Przegrana(Plansza table) {
	for (int b{ 0 };b < 3;b++) {

		Block block;
		switch (b) {
		case 0:
			if (B1Used == true) {
				continue;
			}
			block = B1;
			break;
		case 1:
			if (B2Used == true) {
				continue;
			}
			block = B2;
			break;
		case 2:
			if (B3Used == true) {
				continue;
			}
			block = B3;
			break;
		}


		for (int i{ 0 };i < lenght;i++) {
			for (int j{ 0 };j < lenght;j++) {
				if (SprawdzaniePoprawnosci(table, block, i, j) == true) {
					return true;
				}
			}
		}
	}
	return false;
}

// Funkcja Odpowiedzialna za restart gry
void KolejnaGra(Plansza* table, GLFWwindow* window) {
	if (gameplaying == true) {
		return;
	}

	if (PonownaGra == true) {
		GenerateBlocks();
		table->Reset();
		score = 0;
		gameplaying = true;
		ChangeScreen = true;
	}
	else {
		glfwSetWindowShouldClose(window, true);
	}
}

int main()
{
// OPENGL #################################################

	// Inicjalizowanie GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// Tworzenie Okna
	GLFWwindow* window = glfwCreateWindow(ScreenWidth, ScreenHeight, "MichalBlast", NULL, NULL);
	
	if (window == NULL) {
		std::cout << "Blad GLFW \n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Inicjalizowanie GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Blad GLAD'a \n";
		return -1;
	}

	// Ustala Viewport na ktorym OpenGL bedzie mogl rysowac
	glViewport(0, 0, ScreenWidth, ScreenHeight);	// ((x,y) lewego dolnego pixela okna), ((x,y) rozmiar okna)

	// Ustala która funkcja będzie odpowiedzialna za zmienianie rozmiaru okna -- "OpenGLFunctions"
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	// Generowanie bufforów czyli rezerwowanie miejsca na karcie graficznej i wsadzanie informacji o wektorach
	glGenBuffers(1, &VBO_Empty);
	glGenBuffers(1, &VBO_Square);


	// Shadery ###########################################################


	// Ustalanie Shaderów
	VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(VertexShader);

	// Ustalanie Fragment Shadera
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	fragmentShaderEmpty = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderEmpty, 1, &fragmentShaderSourceEmpty, NULL);
	glCompileShader(fragmentShaderEmpty);

	// Tworzenie programu do shaderów
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, VertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	shaderProgramEmpty = glCreateProgram();
	glAttachShader(shaderProgramEmpty, VertexShader);
	glAttachShader(shaderProgramEmpty, fragmentShaderEmpty);
	glLinkProgram(shaderProgramEmpty);

	// Usuweanie niepotrzebnych shaderów
	glDeleteShader(VertexShader);
	glDeleteShader(fragmentShader);
	glDeleteShader(fragmentShaderEmpty);
	

	// Zapisywanie VAO ########################################


	// Zapisywanie w VAO jak rysowac trojkat
	glGenVertexArrays(1, &VAO_Empty);
	glBindVertexArray(VAO_Empty);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_Empty);
	glBufferData(GL_ARRAY_BUFFER, vertices_empty.size() * sizeof(float), vertices_empty.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Zapisywanie w VAO jak rysowac Kwadrat
	glGenVertexArrays(1, &VAO_Square);
	glBindVertexArray(VAO_Square);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_Square);
	glBufferData(GL_ARRAY_BUFFER, vertices_square.size() * sizeof(float), vertices_square.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Petla Gry #@####################################################
	Generacja(table, &block, &x, &y);

	while (gameplaying && !glfwWindowShouldClose(window)) {
		
		// Zbieranie pozycji myszki i konwertowwanie jej na moje kordynaty
		glfwGetCursorPos(window, &x_mouse_pos, &y_mouse_pos);
		y_mouse_pos = ((y_mouse_pos - (0.5 * ScreenHeight)) * -2) + ScreenHeight;
		x_mouse_pos = ((x_mouse_pos - (0.5 * ScreenWidth)) * 2) + ScreenWidth;

		// Input
		processInput(window);

		// Rendering
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Rysowanie 
		Draw(VAO_Square, shaderProgram);
		Draw(VAO_Empty, shaderProgramEmpty);

		// Odbieranie eventow
		glfwSwapBuffers(window);
		glfwPollEvents();

		// Printy 

		//std::cout << "Mouse X: " << x_mouse_pos << "\n";
		//std::cout << "Mouse Y: " << y_mouse_pos << "\n";
		//std::cout << "Block: " << block << "\n";
		//std::cout << "X: " << x << " Y: " << y << "\n";
		//for (int i{ 0 };i < hitbox_bottom.size();i++) {
		//	std::cout << "X: " << hitbox_bottom[i].x << " Y: " << hitbox_bottom[i].y << " \n";
		//	std::cout << "Width: " << hitbox_bottom[i].width << " Lenght: " << hitbox_bottom[i].heigth << " \n";
		//}


		// Glowna petla gry
		if (PlaceBlock == true) {
			gameplaying = Przegrana(table);
			KolejnaGra(&table, window);
			Stawianie(block, x, y, &table);
			Zwyciestwo(&table);
			block = 0;
			PlaceBlock = false;
		}
		if (ChangeScreen == true) {
			Generacja(table, &block, &x, &y);
			ChangeScreen = false;
		}

	} 

	glfwTerminate();
	return 0;
}
