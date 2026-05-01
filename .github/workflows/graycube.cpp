#include <iostream>
#include <emscripten.h>

struct GravityLaw; 

extern "C" {
    GravityLaw* cubeGravityPtr = nullptr;

    EMSCRIPTEN_KEEPALIVE
    void get_dimensions(float* h, float* w, float* d) {
        *h = 1.0f;
        *w = 1.0f;
        *d = 1.0f;
    }

    EMSCRIPTEN_KEEPALIVE
    void get_positions(float* x, float* y, float* z) {
        *x = 0.0f;
        *y = 0.10f;
        *z = 0.0f;
    }

    EMSCRIPTEN_KEEPALIVE
    void get_colors(float* r, float* g, float* b) {
        *r = 0.5f;
        *g = 0.5f;
        *b = 0.5f;
    }

    EMSCRIPTEN_KEEPALIVE
    void _add_cube_to_logic(int id) {
        std::cout << "The gray cube is created with a pointer to its gravity law." << std::endl;
    }
}

int main() {
    std::cout << "The gray cube is existent." << std::endl;
    return 0;
}
