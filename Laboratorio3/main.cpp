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
#include <iostream>
#include "Tablero.h"
#include "Avatar.h"

int main() {
    Tablero tablero;  // Crear un tablero
    Avatar avatar;   // Crear un avatar

    // Hacer que el avatar se mueva en el laberinto
    avatar.moverse(tablero);
    tablero.imprimir();

    return 0;
}

