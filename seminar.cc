#include <iostream>
#include <variant>
#include <optional>
#include <any>

struct my_union {
    my_union(): n{0} {}
    ~my_union() {}
    union
    {
        int n;
        std::string s;
    };
    
};

class Variant {
    public:
        Variant();
        ~Variant();
    private:
        enum class Type {};
};

union Sum_Type
{
    int n;
    char c;
    char const* s;
};


int main() {

    /* Union */
    /*Sum_Type obj;
    obj.c = 'a';
    std::cout << obj.c << std::endl;
    obj.s = "some text";
    std::cout << obj.c << std::endl; // undefined behaviour
    std::cout << obj.s << std::endl;
    std::cout << obj.n << std::endl; // undefined behaviour*/

    /* std::variant */
    /*std::variant<int, double> data{15};
    std::cout << std::get<int>(data) << std::endl;
    //std::cout << std::get<double>(data) << std::endl; // terminating sue to uncaught exception: bad_variant_access
    data = 12.5;
    std::cout << std::get<1>(data) << std::endl;
    //std::cout << std::get<int>(data) << std::endl; // terminating sue to uncaught exception: bad_variant_access*/

    /* std::any */
    /*std::any var;
    var = 5;
    std::cout << std::any_cast<int>(var) << std::endl;

    var = new double{5.3};
    std::cout << *std::any_cast<double*>(var) << std::endl;
    delete std::any_cast<double*>(var);*/

    /* Implementation */
    /*my_union u{}; // initialicize the first field
    std::cout << u.n << std::endl;
    u.s = "hello";
    std::cout << u.s << std::endl;
    std::cout << u.n << std::endl; // undefined behaviour*/
}