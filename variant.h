#ifndef VARIANT_H // include guard
#define VARIANT_H

#include <string>
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <new>

//?
template<typename T>
T& asObj(char* memory) { // originally stored as char takes 1 byte;
    //std::cout << "asObj = " << *std::launder(reinterpret_cast<T*>(memory)) << std::endl;
    return *std::launder(reinterpret_cast<T*>(memory)); // now reinterpret to T takes diff number of bytes;
}

// base case of variant_helper
template<typename... Types>
struct Variant_Helper;

// specialization
template<typename Type, typename... Types>
struct Variant_Helper<Type, Types...>
{
    static constexpr std::size_t size = std::max(sizeof(Type), Variant_Helper<Types...>::size);
    void size_largest() {
        std::cout << size << std::endl;
    }

    template<typename T, int N = 0>
    static constexpr int index_of() {
        if(std::is_same<T, Type>::value) {
            //std::cout << "index = " << N << std::endl;
            return N;
        }
        else {
            return Variant_Helper<Types...>::template index_of<T, N+1>();
        }
    }

    static void destroy(char* mem, int type) {
        if(type == 0) {
            std::cout << "1 obj: " << asObj<Type>(mem) << std::endl;
            asObj<Type>(mem).~Type();
        }
        else {
            std::cout << "2 obj: " << asObj<Type>(mem) << std::endl;
            return Variant_Helper<Types...>::destroy(mem, type-1); //? why type-1;
        }
    }
};

// specialization
template <>
struct Variant_Helper<>
{
    static constexpr std::size_t size {0};
    // static constexpr int type {-1};

    template<typename T, int N = 0>
    static constexpr int index_of()
    {
        return -1;
    }

    static void destroy(char*, int)
    {
        throw std::bad_cast{};
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
        //? why use for normalization
        /* 
            This parameter must be taken as a forwarding reference 
            as to make sure that it works in the general case (some constructors might expect reference of different types)
            It also ensures that parameter passing is as efficient as possible.
        */
        /*  Remove any references and any potential const qualifiers */
        template<typename T, typename NormalizedType = std::remove_cv_t<std::remove_reference_t<T>>>
        Variant(T&& data)
            : type { Variant_Helper<Types...>::template index_of<NormalizedType>() }
        {
            //? new()
            /* use placement new to initialize an object of type NormalizedType inside memory */
            std::cout << "ini: " << data << std::endl;
            new(&memory[0]) NormalizedType { std::forward<T>(data) };
        }

        void size_largest() {
            std::cout << sizeof(memory) << std::endl;
        }

        template<typename T, typename NormalizedType = std::remove_cv_t<std::remove_reference_t<T>>>
        T& get() {
            int comingType {Variant_Helper<Types...>::template index_of<NormalizedType>()}; 
            //std::cout << type << ", " << comingType << std::endl;
            if(type == comingType) {
                //std::cout << asObj<T>(&memory[0]) << std::endl;
                return asObj<T>(&memory[0]);
            }
            else {
                throw std::bad_cast{};
            }
        }

        template<typename T, typename NormalizedType = std::remove_cv_t<std::remove_reference_t<T>>>
        Variant& operator=(T&& val){
            std::cout << "alloc new val = " << val << std::endl;
            if(type == Variant_Helper<Types...>::template index_of<NormalizedType>()) {
                asObj<NormalizedType>(&memory[0]) = std::forward<T>(val);
            }
            else {
                std::cout << "old type = " << type << std::endl;
                Variant_Helper<Types...>::destroy(&memory[0], type);
                std::cout << "call destroy done" << std::endl;
                new(&memory[0]) NormalizedType { std::forward<T>(val) };
                type = Variant_Helper<Types...>::template index_of<NormalizedType>();
            }
            return *this;
        }
};


#endif /* VARIANT_H */