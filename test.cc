#include "variant.h"

int main() {
    /*Variant_Helper<char, int, float, double, std::string> obj;
    obj.size_largest();
    Variant<char, int, float, double, std::string> obj1 {5};
    //Variant<int, std::string> v { 5 };
    obj.size_largest();*/

    int *p = new int[10];
    std::cout << p[0] << p[1] << p[2] << p[3] << std::endl;
}