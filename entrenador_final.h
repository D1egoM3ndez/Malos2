#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include "personaje_final.h"
#include "pokemon_final.h"

class Entrenador : public Personaje {
private:
    Pokemon equipo[3];
    int max_pokemon;

public:
    Entrenador();
    Entrenador(std::string nom, std::string city, int lv);

    Pokemon get_poke(int index);
    void agregar_poke(Pokemon p);
};

// Implementación de la clase
Entrenador::Entrenador() {
    nombre = "";
    lugar = "";
    nivel = 0;
    max_pokemon = 0;
}

Entrenador::Entrenador(std::string nom, std::string city, int lv) {
    nombre = nom;
    lugar = city;
    nivel = lv;
    max_pokemon = 0;
}

Pokemon Entrenador::get_poke(int index) {
    if (index >= 0 && index < max_pokemon) {
        return equipo[index];
    }
    return Pokemon();
}

void Entrenador::agregar_poke(Pokemon p) {
    if (max_pokemon < 3) {
        equipo[max_pokemon] = p;
        max_pokemon++;
    }
}

#endif
