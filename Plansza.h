#pragma once

#include <Glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Global.h"
#include "OpenGLFunctions.h"

class Plansza {

public:
    int plansza[lenght][lenght];
    Plansza();
    void Show();
    void Reset();
};