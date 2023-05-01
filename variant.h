#ifndef VARIANT_H // include guard
#define VARIANT_H

#include <string>
#include <iostream>
#include <algorithm>

// base case of variant_helper
template<typename... Types>
struct Variant_Helper
{
    static constexpr std::size_t size = 0;
};

template<typename Type, typename... Types>
struct Variant_Helper<Type, Types...>
{
    static constexpr std::size_t size = std::max(sizeof(Type), Variant_Helper<Types...>::size);
    void size_largest() {
        std::cout << size << std::endl;
    }
};

/* Variant */
template<typename... Types>
class Variant
{
    private:
        std::array<char, Variant_Helper<Types...>::size> memory;
        int type {-1};
    
    public:
        //? use for normalization
        template<typename T, typename NormalizedType = std::remove_cv_t<std::remove_reference_t<T>>>
        Variant(T&& data)
            : type {}
        {
            //? new()
            new(&memory[0]) NormalizedType { std::forward<T>(data) };
        }

        /*template <typename T, typename NormalizedType = std::remove_cv_t<std::remove_reference_t<T>>>
        Variant(T&& value)
            // Note: Helper is a dependent name (it depends on Types...) so the compiler will
            // assume that index_of is *not* a template. To fix this we have to add the template
            // keyword before index_of just to communicate to the compiler that it actually is
            // a template (See seminar 6 for details).
            : type { Helper::template index_of<NormalizedType>() }
        {
            new (&memory[0]) NormalizedType { std::forward<T>(value) };
        }*/

        void size_largest() {
            std::cout << sizeof(memory) << std::endl;
        }
};


#endif /* VARIANT_H */