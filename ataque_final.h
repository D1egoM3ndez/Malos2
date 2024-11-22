#ifndef ATAQUE_H
#define ATAQUE_H

#include <string>
#include "tipo_final.h"

class Ataque {
private:
    std::string nombre;
    int poder;
    int precision;
    Tipo tipo;

public:
    Ataque();
    Ataque(std::string nom, int pow, int prec, Tipo t);

    std::string get_nombre();
    int get_poder();
    int get_precision();
    Tipo get_tipo();
};

// Implementación de la clase
Ataque::Ataque() {
    nombre = "";
    poder = 0;
    precision = 0;
    tipo = Tipo();
}

Ataque::Ataque(std::string nom, int pow, int prec, Tipo t) {
    nombre = nom;
    poder = pow;
    precision = prec;
    tipo = t;
}

std::string Ataque::get_nombre(){ 
    return nombre; 
    }

int Ataque::get_poder(){ 
    return poder;
    }

int Ataque::get_precision(){ 
    return precision; 
    }

Tipo Ataque::get_tipo(){ 
    return tipo; 
    }

#endif

