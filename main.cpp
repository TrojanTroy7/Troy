#include <iostream>
#include <emscripten.h>
#include <emscripten/html5.h>

struct GravityLaw; 

extern "C" {
    GravityLaw* cubeGravityPtr = nullptr;

    EMSCRIPTEN_KEEPALIVE
    void draw_cube_frame(float x, float y, float z, float r, float g, float b) {
        EM_ASM({
            if (window.renderCube) {
                window.renderCube($0, $1, $2, $3, $4, $5);
            }
        }, x, y, z, r, g, b);
    }

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
        draw_cube_frame(0.0f, 0.10f, 0.0f, 0.5f, 0.5f, 0.5f);
        std::cout << "The gray cube is drawn on screen via C++ logic." << std::endl;
    }
}

int main() {
    std::cout << "Troy Engine: Graphics System Initialized." << std::endl;
    return 0;
}
