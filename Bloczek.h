#pragma once

#include <Glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Global.h"
#include "OpenGLFunctions.h"

class Block {

public:
	int block1[blocklenght][blocklenght];
	virtual ~Block() = default;
	void Show(int x);

};

class Pusty : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};
public:
	Pusty();

};

// Kwadraty #####################################

class DuzyKwadrat : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,1},
		{0,0,1,1,1},
		{0,0,1,1,1}
	};
public:
	DuzyKwadrat();

};

class MalyKwadrat : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,1,1},
		{0,0,0,1,1}
	};
public:
	MalyKwadrat();

};

// Prostokaty ###################################

class PodluznyProstokat : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,1},
		{0,0,1,1,1}
	};
public:
	PodluznyProstokat();

};

class PionowyProstakat : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,1,1},
		{0,0,0,1,1},
		{0,0,0,1,1}
	};
public:
	PionowyProstakat();

};

// Linie ######################################

class PiecPionowe : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,1},
		{0,0,0,0,1},
		{0,0,0,0,1},
		{0,0,0,0,1},
		{0,0,0,0,1}
	};
public:
	PiecPionowe();

};

class PiecPoziome : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{1,1,1,1,1}
	};
public:
	PiecPoziome();

};

class CzteryPionowe : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,1},
		{0,0,0,0,1},
		{0,0,0,0,1},
		{0,0,0,0,1}
	};
public:
	CzteryPionowe();

};

class CzteryPoziome : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,1,1,1,1}
	};
public:
	CzteryPoziome();

};

// L'ki ######################################

class L1 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,1,1},
		{0,0,0,0,1},
		{0,0,0,0,1}
	};
public:
	L1();

};

class L2 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,1,0},
		{0,0,0,1,0},
		{0,0,0,1,1}
	};
public:
	L2();

};

class L3 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,1,1},
		{0,0,0,1,0},
		{0,0,0,1,0}
	};
public:
	L3();

};

class L4 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,1},
		{0,0,0,0,1},
		{0,0,0,1,1}
	};
public:
	L4();

};

// Duże L'ki ######################################

class DL1 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,1},
		{0,0,0,0,1},
		{0,0,0,0,1}
	};
public:
	DL1();

};

class DL2 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,1,1}
	};
public:
	DL2();

};

class DL3 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,1},
		{0,0,1,0,0},
		{0,0,1,0,0}
	};
public:
	DL3();

};

class DL4 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,1},
		{0,0,0,0,1},
		{0,0,1,1,1}
	};
public:
	DL4();

};

// Plusy ##########################################

class P1 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,1},
		{0,0,0,1,1},
		{0,0,0,0,1}
	};
public:
	P1();

};

class P2 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,1,0},
		{0,0,1,1,1}
	};
public:
	P2();

};

class P3 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,1,0},
		{0,0,0,1,1},
		{0,0,0,1,0}
	};
public:
	P3();

};

class P4 : public Block {

private:
	int offset[blocklenght][blocklenght] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,1,1},
		{0,0,0,1,0}
	};
public:
	P4();
};