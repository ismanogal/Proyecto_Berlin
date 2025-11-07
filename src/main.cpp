#include <iostream>
#include <string>

int main(){
    std::string line;
    std::cout << "Bienvenido al juego. ¿Cómo te llamas?\n" << std::flush;
    if(!std::getline(std::cin, line)) return 0;
    std::cout << "Hola, " << line << "! Vamos con un acertijo.\n" << std::flush;

    std::cout << "Soy algo que sube y baja pero nunca se mueve. ¿Qué soy?\n" << std::flush;
    if(!std::getline(std::cin, line)) return 0;

    if(line == "temperatura" || line == "la temperatura" || line == "temperatura.") {
        std::cout << "¡Correcto! Fin del demo.\n" << std::flush;
    } else {
        std::cout << "Casi. Respuesta esperada: temperatura. Fin del demo.\n" << std::flush;
    }

    return 0;
}
