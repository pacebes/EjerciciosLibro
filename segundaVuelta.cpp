#include <iostream> 
#include <string> 
#include "segundaVuelta.h" 

#pragma once

namespace nmsv1 {

    Traffic_light& operator++(Traffic_light& t) // prefix increment:     ++
    {
        using enum Traffic_light; // here, we are using Traffic_light
        switch (t) {
        case green: return t = yellow;
        case yellow: return t = red;
        case red: return t = green;
        }
    }

    void dimeColorC(const Color & c)
    {
        
        switch (c) {
        case Color::red:
            std::cout << " red ";
            break;

        case Color::blue:
            std::cout << " blue ";
            break;

        case Color::green:
            std::cout << " green ";
            break;

        default:
            std::cout << " unknown ";
            break;

        }
        
    }
    void dimeColorTL(const Traffic_light& t)
    {
        using enum Traffic_light; // here, we are using Traffic_light
        
        
        switch (t) {
        case green:
            std::cout << " green ";
            break;

        case yellow:
            std::cout << " yellow ";
            break;

        case red:
            std::cout << " red ";
            break;

        default:
            std::cout << " unknown ";
            break;

        }
    }
    
    void f(Entry* pe)
    {
        if (std::holds_alternative<int>(pe->v))
            std::cout << get<int>(pe->v);

    }

}

