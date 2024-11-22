#ifndef POKEMON_H
#define POKEMON_H

#include "personaje_final.h"
#include "tipo_final.h"
#include "ataque_final.h"

class Pokemon : public Personaje {
private:
    int vida;
    Tipo tipo;
    Ataque ataques[3];
    int max_ataques;

public:
    Pokemon();
    Pokemon(std::string nom, std::string city, int lv, int hp, Tipo t);

    int get_vida();
    Tipo get_tipo();
    Ataque get_ataque(int index);

    void agregar_ataq(Ataque a);
    void recibe_dano(int dano);
};

// Implementación de la clase
Pokemon::Pokemon() {
    nombre = "";
    lugar = "";
    nivel = 0;
    vida = 0;
    tipo = Tipo();
    max_ataques = 0;
}

Pokemon::Pokemon(std::string nom, std::string city, int lv, int hp, Tipo t) {
    nombre = nom;
    lugar = city;
    nivel = lv;
    vida = hp;
    tipo = t;
    max_ataques = 0;
}

int Pokemon::get_vida() { return vida; }

Tipo Pokemon::get_tipo() { return tipo; }

Ataque Pokemon::get_ataque(int pos) {
    if (pos >= 0 && pos < max_ataques) {
        return ataques[pos];
    }
    return Ataque();
}

void Pokemon::agregar_ataq(Ataque a) {
    if (max_ataques < 3) {
        ataques[max_ataques] = a;
        max_ataques++;
    }
}

void Pokemon::recibe_dano(int dano) {
    vida -= dano;
    if (vida < 0) vida = 0;
}

#endif
