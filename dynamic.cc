#include <iostream>

struct Dynamic
{
        int x;
        double y;
        Dynamic(int n, double d) : x{n}, y{d} {

        };
};


int main() {
    Dynamic* ptr_obj = new Dynamic{1, 1.5};
    std::cout << ptr_obj->x << ' ' << ptr_obj->y <<std::endl;
    new (ptr_obj) Dynamic{3, 3.5};
    std::cout << ptr_obj->x << ' ' << ptr_obj->y <<std::endl; // undefined behaviour
    
}