/*
    Proyecto: Laboratorio 3 
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto gestiona la simulacion del movimiento de un soldado en un tablero donde el movimiento es aleatorio
    el movimiento esta establecido por 1 y 0, donde el soldado puede estar en 1 y en el 0 es visto como un lugar en que no puede estar

    Autor: Jhonnier Andres Becerra
    Autor: Santiago Ceron
    Correo: becerra.jhonnier@correounivalle.edu.co
    Correo: santiago.ceron.gomez@correounivalle.edu.co
    Fecha: Mayo 2025
*/
#include "Avatar.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Avatar::Avatar() : x(0), y(0) {}

void Avatar::moverse(Tablero &tablero) {
    srand(time(0));  // Inicializamos la semilla aleatoria

    // Obtenemos la posición de inicio del tablero
    std::vector<int> posicion = tablero.getInicio();
    std::vector<std::vector<int>> laberinto = tablero.getLaberinto();

    // Mientras no lleguemos a la salida [9][9]
    while (posicion[0] != 9 || posicion[1] != 9) {
        // Elegir una dirección aleatoria (0: abajo, 1: arriba, 2: derecha, 3: izquierda)
        int desicion = rand() % 4;
        std::string movimiento = "";

        switch (desicion) {
            case 0: // Moverse abajo
                if (posicion[0] < 9 && laberinto[posicion[0] + 1][posicion[1]] == 1) {
                    posicion[0]++;
                    movimiento = "Abajo";
                }
                break;
            case 1: // Moverse arriba
                if (posicion[0] > 0 && laberinto[posicion[0] - 1][posicion[1]] == 1) {
                    posicion[0]--;
                    movimiento = "Arriba";
                }
                break;
            case 2: // Moverse derecha
                if (posicion[1] < 9 && laberinto[posicion[0]][posicion[1] + 1] == 1) {
                    posicion[1]++;
                    movimiento = "Derecha";
                }
                break;
            case 3: // Moverse izquierda
                if (posicion[1] > 0 && laberinto[posicion[0]][posicion[1] - 1] == 1) {
                    posicion[1]--;
                    movimiento = "Izquierda";
                }
                break;
        }

        // Si el movimiento fue valido, lo agregamos a los movimientos realizados
        if (!movimiento.empty()) {
            movimientos.push_back(movimiento);
            // Mostramos el movimiento y la posición
            std::cout << "Moviendose hacia: " << movimiento << std::endl;
            std::cout << "Posicion actual: [" << posicion[0] << ", " << posicion[1] << "]" << std::endl;
        }

        // Mostramos el movimiento y la posición
        std::cout << "Moviendose hacia: " << movimiento << std::endl;
        std::cout << "Posicion actual: [" << posicion[0] << ", " << posicion[1] << "]" << std::endl;
    }

    // Llegó a la salida
    std::cout << "El soldado ha encontrado la salida!" << std::endl;
}

// Obtener los movimientos realizados
std::vector<std::string> Avatar::getMovimientos() const {
    return movimientos;
}

