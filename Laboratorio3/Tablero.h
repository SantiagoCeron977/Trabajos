/*
    Clase: Tablero
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:
    
    Clase: Tablero

    Responsabilidades:
    - Representar el laberinto del juego, que es una matriz de 10x10 celdas.
    - Generar el laberinto con caminos (1) y precipicios (0), asegurando que haya un camino válido hasta la salida [9][9].
    - Proveer la posición de inicio del avatar.
    - Imprimir el laberinto en consola para que el jugador pueda verlo.
    - Manejar la lógica interna para la creación del laberinto y el acceso a sus celdas.

    Colaboradores:
    - Colabora con la clase `Avatar` para proporcionar el laberinto y la posición de inicio del avatar.
    - Colabora con la función `main` para coordinar la ejecución del juego y la interacción con el tablero.

    Librerías utilizadas:
    - <cstdlib>: Para generar números aleatorios (función `rand()`).
    - <ctime>: Para inicializar la semilla del generador de números aleatorios (función `srand()`).
    - <vector>: Para almacenar la matriz del laberinto y las posiciones de inicio.
    - <iostream>: Para imprimir el laberinto en la consola y mostrar los mensajes al usuario.

    Autor: Jhonnier Andres Becerra
    Autor: Santiago Ceron
    Correo: becerra.jhonnier@correounivalle.edu.co
    Correo: santiago.ceron.gomez@correounivalle.edu.co
    Fecha: Mayo 2025
*/
#ifndef TABLERO_H
#define TABLERO_H

#include <vector>

class Tablero {
private:
    std::vector<std::vector<int>> laberinto;  // El laberinto
    int inicioX, inicioY;  // Coordenadas de inicio

public:
    Tablero();  // Constructor

    // Métodos para obtener el laberinto y la posición de inicio
    void imprimir();
    std::vector<std::vector<int>> getLaberinto();
    std::vector<int> getInicio();
};

#endif // TABLERO_H
