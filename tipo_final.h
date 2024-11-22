#ifndef TIPO_H
#define TIPO_H

#include <string>
#include <iostream>

class Tipo {
private:
    std::string nombre;
    std::string ventajas[5];
    std::string debilidades[5];
    int max_ven;
    int max_deb;

public:
    Tipo();
    Tipo(std::string nom);

    std::string get_nombre();
    void set_nombre(std::string nom);

    void agregar_ventaja(std::string type);
    void agregar_debilidad(std::string type);

    void mostrar_ventajas();
    void mostrar_debilidades();

    int multiplica(std::string nom);
};

// Implementación de la clase
Tipo::Tipo() {
    nombre = "";
    max_ven = 0;
    max_deb = 0;
}

Tipo::Tipo(std::string nom) {
    nombre = nom;
    max_ven = 0;
    max_deb = 0;
}

std::string Tipo::get_nombre() { return nombre; }

void Tipo::set_nombre(std::string nom) { nombre = nom; }

void Tipo::agregar_ventaja(std::string type) {
    if (max_ven < 5) {
        ventajas[max_ven] = type;
        max_ven++;
    }
}

void Tipo::agregar_debilidad(std::string type) {
    if (max_deb < 5) {
        debilidades[max_deb] = type;
        max_deb++;
    }
}

void Tipo::mostrar_ventajas() {
    for (int i = 0; i < max_ven; i++) {
        std::cout << ventajas[i] << std::endl;
    }
}

void Tipo::mostrar_debilidades() {
    for (int i = 0; i < max_deb; i++) {
        std::cout << debilidades[i] << std::endl;
    }
}

int Tipo::multiplica(std::string nom) {
    for (int i = 0; i < 5; i++) {
        if (ventajas[i] == nom) {
            return 2;
        }
        if (debilidades[i] == nom) {
            return 0;
        }
    }
    return 1;
}

#endif

