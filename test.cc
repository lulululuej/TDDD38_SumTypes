#include "variant.h"
int main() {
    /*Variant_Helper<char, int, float, double, std::string> obj;
    obj.size_largest();
    Variant<char, int, float, double, std::string> obj1 {5};
    Variant<int, std::string> v { 5 };
    obj.size_largest();

    int *p = new int[10];
    std::cout << p[0] << p[1] << p[2] << p[3] << std::endl;

    Variant<int, std::string> v { 5 };
    v.get_data();*/
    /*std::string str {"Hello world"};
    Variant<int, std::string> v { str };
    std::cout << v.get<std::string>() << std::endl;*/
    //std::string str { "Hello World" };
    //v = str;

    /*
        int x {5};
        int *p = &x;
        std::cout << p << std::endl;  // the addr of x
        std::cout << &p << std::endl; // the addr of p
        std::cout << *p << std::endl; // the value of x
    */

    int* p_int = new int(5);
    std::cout << p_int << std::endl;

    int* p_arr = new int[5];
    std::cout << p_arr << std::endl;

    delete p_int;
    delete[] p_arr;
    
    return 0;
}
