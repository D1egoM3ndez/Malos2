#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>

class Personaje {
protected:
    std::string nombre;
    std::string lugar;
    int nivel;

public:
    Personaje();
    Personaje(std::string nom, std::string city, int lv);

    std::string get_nombre();
    std::string get_lugar();
    int get_nivel();

    void set_nombre(std::string nom);
    void set_lugar(std::string city);
    void set_nivel(int lv);

    void aumento_lv();
    void mostrar();
};

// Implementación de la clase
Personaje::Personaje() {
    nombre = "";
    lugar = "";
    nivel = 0;
}

Personaje::Personaje(std::string nom, std::string city, int lv) {
    nombre = nom;
    lugar = city;
    nivel = lv;
}

std::string Personaje::get_nombre() { return nombre; }

std::string Personaje::get_lugar() { return lugar; }

int Personaje::get_nivel() { return nivel; }

void Personaje::set_nombre(std::string nom) { nombre = nom; }

void Personaje::set_lugar(std::string city) { lugar = city; }

void Personaje::set_nivel(int lv) { nivel = lv; }

void Personaje::aumento_lv() { nivel++; }

void Personaje::mostrar() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Lugar: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
}

#endif
