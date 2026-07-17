
#include "Bloczek.h"


void Block::Show(int x) {
	std::cout << "\n";
	for (int i{ 0 };i < blocklenght; i++) {
		std::cout << "\n";
		for (int j{ 0 };j < blocklenght; j++) {
			std::cout << block[i][j];

			// Grafika
			if (block[i][j] != 0) {
				std::vector<float> temp = GenerateSquareVertexes((j * BlockWidth) + ((ScreenWidth * 0.6) * x) - (ScreenWidth * 1.5), ((lenght - 1 - i) * BlockWidth) + ScreenHeightBufor, BlockWidth);
				ChangeVerticesArray(VBO_Square, temp);
			}
		}
	}
	std::cout << "\n";
}

Pusty::Pusty() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

DuzyKwadrat::DuzyKwadrat() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

MalyKwadrat::MalyKwadrat() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

PodluznyProstokat::PodluznyProstokat() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

PionowyProstakat::PionowyProstakat() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

PiecPionowe::PiecPionowe() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

PiecPoziome::PiecPoziome() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

CzteryPionowe::CzteryPionowe() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

CzteryPoziome::CzteryPoziome() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

L1::L1() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

L2::L2() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

L3::L3() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

L4::L4() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

DL1::DL1() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

DL2::DL2() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

DL3::DL3() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

DL4::DL4() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

P1::P1() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

P2::P2() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

P3::P3() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}

}

P4::P4() {

	for (int i{ 0 };i < blocklenght; i++) {
		for (int j{ 0 };j < blocklenght; j++) {
			block[i][j] = offset[i][j];
		}
	}
}