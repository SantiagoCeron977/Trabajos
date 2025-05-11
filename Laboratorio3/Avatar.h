/*
    Clase: Avatar
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:
    
    Clase: Avatar

    Responsabilidades:
    - Representar al agente (soldado) dentro del laberinto.
    - Manejar el movimiento del avatar dentro del laberinto (moverse en 4 direcciones).
    - Evitar retrocesos asegurando que el avatar solo se mueva en direcciones válidas.
    - Registrar los movimientos realizados por el avatar.
    - Controlar la lógica de búsqueda para llegar a la salida ubicada en la casilla [9][9].

    Colaboradores:
    - Colabora con la clase `Tablero` para obtener el laberinto y la posición de inicio del avatar.
    - Colabora con la clase `main` para coordinar la ejecución del juego y la interacción con el avatar.
    
    Librerías utilizadas:
    - <string>: Para almacenar los movimientos del avatar como cadenas de texto.
    - <vector>: Para almacenar los movimientos realizados por el avatar.

    Autor: Jhonnier Andres Becerra
    Autor: Santiago Ceron
    Correo: becerra.jhonnier@correounivalle.edu.co
    Correo: santiago.ceron.gomez@correounivalle.edu.co
    Fecha: Mayo 2025
*/

#ifndef AVATAR_H
#define AVATAR_H

#include "Tablero.h"
#include <vector>
#include <string>

class Avatar {
private:
    int x, y;  // Posición actual del avatar
    std::vector<std::string> movimientos;  // Para guardar los movimientos realizados

public:
    Avatar();  // Constructor por defecto

    // Método para moverse dentro del laberinto
    void moverse(Tablero &tablero);

    // Obtener los movimientos realizados
    std::vector<std::string> getMovimientos() const;
};

#endif // AVATAR_H
