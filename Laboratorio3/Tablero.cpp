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
#include "Tablero.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

Tablero::Tablero() {
    laberinto = vector<vector<int>>(10, vector<int>(10, 0));  // Inicializamos el laberinto con ceros
    srand(time(0));

    // Punto de inicio aleatorio
    inicioX = rand() % 10;
    inicioY = rand() % 10;
    laberinto[inicioY][inicioX] = 1;

    // Generar un camino principal hasta [9][9]
    int x = inicioX, y = inicioY;
    while (x != 9 || y != 9) {
        int dir = rand() % 2; // 0: horizontal, 1: vertical
        if (dir == 0 && x < 9) {
            x++;
        } else if (dir == 1 && y < 9) {
            y++;
        }
        laberinto[y][x] = 1;
    }

    // Agregar ramificaciones aleatorias al camino
    for (int i = 0; i < 30; ++i) {
        vector<pair<int, int>> camino;
        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 10; ++x) {
                if (laberinto[y][x] == 1) {
                    camino.push_back({y, x});
                }
            }
        }

        if (camino.empty()) break;

        pair<int, int> pos = camino[rand() % camino.size()];
        int ry = pos.first;
        int rx = pos.second;

        int length = rand() % 4 + 1;
        int dir = rand() % 4;

        for (int j = 0; j < length; ++j) {
            if (rx >= 0 && rx < 10 && ry >= 0 && ry < 10) {
                laberinto[ry][rx] = 1;
            }

            if (dir == 0) rx++; // Derecha
            else if (dir == 1) ry++; // Abajo
            else if (dir == 2) rx--; // Izquierda
            else if (dir == 3) ry--; // Arriba

            if (rx < 0 || rx >= 10 || ry < 0 || ry >= 10) break;
        }
    }
}

void Tablero::imprimir() {
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 10; y++) {
            cout << laberinto[y][i] << " ";
        }
        cout << endl;
    }
}

std::vector<std::vector<int>> Tablero::getLaberinto() {
    return laberinto;
}

std::vector<int> Tablero::getInicio() {
    vector<int> inicio;
    inicio.push_back(inicioY);
    inicio.push_back(inicioX);
    return inicio;
}
