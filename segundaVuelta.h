#pragma once
#include <string>
#include <variant>


namespace nmsv1 {
    enum class Color { red, blue, green };
    enum class Traffic_light { green, yellow, red };

    Traffic_light& operator++(Traffic_light& t);
    
    void dimeColorTL(const Traffic_light& t);
    void dimeColorC(const Color& c);

    struct Entry {
        std::string name;
        std::variant<double*, int> v;
    };
    void f(Entry* pe);


}
