#include <cassert>
#include <string>
#include "variant.h"

int main()
{
    Variant<int, std::string> v { 5 };
    /*
    try
    {
        v.get<std::string>();
        assert(false);
    }
    catch (std::bad_cast& e)
    {
        assert(true);
    }
    
    assert( v.get<int>() == 5 );

    std::string str { "Hello World" };
    v = str;

    assert( v.get<std::string>() == str );

    v.get<std::string>().push_back('!');

    assert( v.get<std::string>() == "Hello World!" );

    v = 0;

    assert( v.get<int>() == 0 );

    assert( v.get<int>()++ == 0 );
    assert( ++v.get<int>() == 2 );

    v = str;

    assert( v.get<std::string>() == str );
    */
}
