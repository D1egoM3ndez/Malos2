#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "personaje_final.h"
#include "tipo_final.h"
#include "ataque_final.h"
#include "pokemon_final.h"
#include "entrenador_final.h"

// Función para ejecutar el turno del jugador
void ejecutar_turno_jugador(Pokemon& jugador, Pokemon& bot) {
    std::cout << "Elige un ataque" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i << ".- " << jugador.get_ataque(i) << std::endl;
    }

    int num;
    std::cin >> num;
    while (num < 0 || num > 2) {
        std::cout << "Selecciona un número entre 0 y 2: ";
        std::cin >> num;
    }

    Ataque ataq = jugador.get_ataque(num);
    Tipo tipo_ataque = ataq.get_tipo();
    Tipo tipo_objetivo = bot.get_tipo();

    int compatible = tipo_ataque.multiplica(tipo_objetivo.get_nombre());
    int aumento = (compatible == 2) ? 2 : (compatible == 0 ? 0 : 1);
    if (compatible == 2) std::cout << "¡Es súper eficaz!" << std::endl;
    else if (compatible == 0) std::cout << "Es poco eficaz..." << std::endl;

    int dano_total = ataq.get_poder() * aumento;
    bot.recibe_dano(dano_total);

    std::cout << "Vida de " << bot.get_nombre() << " es ahora de " 
    << bot.get_vida() << std::endl;
}

// Función para ejecutar el turno del bot
void ejecutar_turno_bot(Pokemon& bot, Pokemon& jugador) {
    int num_ataque_bot = std::rand() % 3;
    Ataque ataque = bot.get_ataque(num_ataque_bot);
    Tipo tipo_ataque = ataque.get_tipo();
    Tipo tipo_objetivo = jugador.get_tipo();

    int compatible = tipo_ataque.multiplica(tipo_objetivo.get_nombre());
    int aumento = (compatible == 2) ? 2 : (compatible == 0 ? 0 : 1);
    if (compatible == 2) std::cout << "¡Es súper eficaz!" << std::endl;
    else if (compatible == 0) std::cout << "Es poco eficaz..." << std::endl;

    int dano_total = ataque.get_poder() * aumento;
    jugador.recibe_dano(dano_total);

    std::cout << "Nueva vida de " << jugador.get_nombre() << " es de " 
    << jugador.get_vida() << std::endl;
}

// Función para imprimir separadores
void imprimir_separador() {
    std::cout << "--------------------------" << std::endl;
}

int main() {
    std::srand(std::time(0)); // Inicializar generador de números aleatorios

    // Declaración de tipos y configuración inicial
    Tipo fuego("Fuego"), agua("Agua");

    fuego.agregar_ventaja("Planta");
    fuego.agregar_debilidad("Agua");
    agua.agregar_ventaja("Fuego");
    agua.agregar_debilidad("Eléctrico");

    // Creación de Pokémon
    Pokemon charizard("Charizard", "Ruta 5", 35, 160, fuego);
    charizard.agregar_ataq(Ataque("Llamarada", 90, 85, fuego));
    charizard.agregar_ataq(Ataque("Ascuas", 40, 100, fuego));
    charizard.agregar_ataq(Ataque("Lanzallamas", 90, 80, fuego));

    Pokemon blastoise("Blastoise", "Ruta 4", 36, 155, agua);
    blastoise.agregar_ataq(Ataque("Rayo Burbuja", 70, 95, agua));
    blastoise.agregar_ataq(Ataque("Agua Lodosa", 80, 85, agua));
    blastoise.agregar_ataq(Ataque("Buceo", 80, 80, agua));

    // Creación de entrenadores
    Entrenador ent1("Rojo", "Pueblo Paleta", 10);
    ent1.agregar_poke(charizard);

    Entrenador ent2("Azul", "Ciudad Carmín", 10);
    ent2.agregar_poke(blastoise);

    Entrenador arr[2] = {ent1, ent2};

    imprimir_separador();
    std::cout << "Bienvenido al mundo Pokémon" << std::endl;
    std::cout << "Selecciona tu entrenador:" << std::endl;
    std::cout << "0.- " << ent1.get_nombre() << "\n1.- " 
    << ent2.get_nombre() << std::endl;

    int num;
    std::cin >> num;
    while (num < 0 || num > 1) {
        std::cout << "Por favor, selecciona un número válido: ";
        std::cin >> num;
    }

    Entrenador player = arr[num];
    Pokemon poke = player.get_poke(0); // Selección inicial de Pokémon
    imprimir_separador();

    Entrenador bot("Bot", "Liga Pokémon", 15);
    Pokemon poke_bot = bot.get_poke(0);

    std::cout << "Te enfrentarás a " << bot.get_nombre() << " con su " 
    << poke_bot.get_nombre() << "!" << std::endl;

    // Turnos
    int turno = std::rand() % 2;
    while (poke.get_vida() > 0 && poke_bot.get_vida() > 0) {
        imprimir_separador();
        if (turno == 0) {
            std::cout << "Tu turno:" << std::endl;
            ejecutar_turno_jugador(poke, poke_bot);
            turno = 1;
        } else {
            std::cout << "Turno del Bot:" << std::endl;
            ejecutar_turno_bot(poke_bot, poke);
            turno = 0;
        }
    }

    // Determinar el ganador
    imprimir_separador();
    if (poke.get_vida() > 0) {
        std::cout << "¡Ganaste la batalla!" << std::endl;
        player.aumento_lv();
        std::cout << "Nuevo nivel de entrenador: " 
        << player.get_nivel() << std::endl;
    } else {
        std::cout << "Perdiste la batalla. ¡Sigue entrenando!" << std::endl;
    }

    return 0;
}
