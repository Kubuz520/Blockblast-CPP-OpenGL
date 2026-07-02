
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <random>
#include <iostream>
#include "Global.h"
#include "Plansza.h"
#include "Bloczek.h"

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

void Generacja(Plansza table,int* b, int* x, int* y) {
	
	// Generuje nowe 3 bloczki jesli sa zuzyte
	if (B1Used == true && B2Used == true && B3Used == true) {
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

	// Pokazuje Bloczki i plansze
	table.Show();
	B1.Show();
	B2.Show();
	B3.Show();

	// Branie Bloczka
	int b1{};
	std::cout << "Ktory Blok(1-3): ";
	std::cin >> b1;
	std::cout << "\n";

	// Branie Koordynatow do stawiania bloczka
	int x1{};
	int y1{};

	std::cout << "X Koordynat(0-7): ";
	std::cin >> x1;
	std::cout << "\n";
	std::cout << "Y Koordynat(0-7): ";
	std::cin >> y1;
	std::cout << "\n";
	*x = x1;
	*y = y1;
	*b = b1;

}

bool SprawdzaniePoprawnosci(Plansza table, Block block, int x, int y) {

	// sprawdza czy ustawienie jest poprawne
	int x1{ 5 };
	int y1{ 5 };

	for (int i{ x };i > x - blocklenght;i--) {
		x1--;
		if (block.block[y1][x1] == 1) {
			if (i < 0) {
				return false ;
			}
		}
		y1 = 5;
		for (int j{ y };j > y - blocklenght;j--) {
			y1--;
			if (block.block[y1][x1] == 1) {
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
	Block block = PrzypisanieBloczku(b - 1);
	
	// Wywolanie funkcji ktora sprawdza czy dany ruch jest poprawny
	if (SprawdzaniePoprawnosci(*table, block, x, y) == false) {
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
			if (block.block[y1][x1] == 1) {
				table->plansza[j][i] = block.block[y1][x1];
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
void KolejnaGra(Plansza* table) {
	if (gameplaying == true) {
		return;
	}

	int PonownaGra{};

	std::cout << "\n";
	std::cout << "Chcesz Zagrać Jeszcze Raz? (1-Tak)";
	std::cin >> PonownaGra;

	if (PonownaGra == 1) {
		table->Reset();
		score = 0;
		gameplaying = true;
	}
}

int main()
{
	// Ustawianie variabli
	int x{};
	int y{};
	int b{};
	Plansza table;

	// Glowna petla gry
	do {
		Generacja(table,&b, &x, &y);
		gameplaying = Przegrana(table);
		KolejnaGra(&table);
		Stawianie(b, x, y, &table);
		Zwyciestwo(&table);
	} while (gameplaying);
    
}
