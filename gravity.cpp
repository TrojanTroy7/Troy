#include <iostream>

float surface = 0.0f;

extern "C" {
    void apply_gravity(float &objectHeight) {
        if (objectHeight > surface) {
            objectHeight -= 0.1f; 
        } 
        else {
            objectHeight = surface;
            std::cout << "It is on whatever surface." << std::endl; 
        }
    }
}
