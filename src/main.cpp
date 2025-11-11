// Proyecto_Berlin: EL JUEGO DE LA CARTA

#include <iostream>
#include <unistd.h>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string IntroAndNamePlayer();

void IntroducePassword();

void DevelopementInProgress(string name_player);

void DisplayMenu();

char GetUserSelection();

void FromMenuToAdventure();

int main(){
    // string name_player = IntroAndNamePlayer();

    // IntroducePassword();

    // DevelopementInProgress(name_player);

    FromMenuToAdventure();

    return 0;
}

string IntroAndNamePlayer()
{
    bool result { false };
    string name_player;

    cout << endl;
    cout << "¡Hola! Bienvenido al Juego de la Carta, un placer conocerte." << endl;
    cout << "¿Cómo te llamas? Escribe tu nombre." << endl;
    do
    {
        getline(cin, name_player);
        std::transform(name_player.begin(), name_player.end(), name_player.begin(),[](unsigned char c){ return std::tolower(c); });
        
        if (name_player == "beltran")
        {
            result = true;
        }
        else
        {
            cout << "Se nos conoce por muchos nombres " << name_player << ", asegurate de escribir tu nombre sin tildes." << endl;
            sleep(1);
            cout << "Inténtalo de nuevo." << endl;
        }


    } while (!result);

    cout << endl;
    cout << "Bueno, bueno, bueno..." << endl;
    sleep(1);
    cout << "Parece que tenemos ante nosotros al verdadero Potrillo!!!" << endl;
    sleep(1);
    cout << "Mucho me han hablado de ti." << endl;
    sleep(1);
    cout << endl;
    cout << "Todo juego necesita un héroe, tu momento ha llegado jugador!" << endl;
    sleep(1);

    return name_player;
}

void IntroducePassword()
{
    cout << "Para asegurarme de que tengo ante mí al legítimo jugador de este juego necesito una última comprobación. Dime el nombre del grupo de tus amigos del instituto: " << endl;
    sleep(1);

    for (size_t i { 0 }; i <= 2; i++)
    {
        string first_password;
        getline(cin, first_password);

        if (first_password == "Coc(keros) y permanente")
        {
            cout << "jajajsjdsksajdskadjjajajdaidkjjaja" << endl;
            sleep(1);
            cout << first_password << endl;
            sleep(1);
            cout << "Lo sé, el nombre es lamentable, pero son tus amigos y hay que quererlos." << endl;
            sleep(1);
            cout << "Ahora sí, en... ";
            sleep(1);
            cout << "3, ";
            sleep(1);
            cout << "2, ";
            sleep(1);
            cout << "1... ";
            sleep(1);
            cout << "empieza..." << endl <<endl;
            sleep(1);

            cout << "================ EL JUEGO DE LA CARTA ================" << endl << endl;
            break;
        }
        else
        {
            cout << "Incorrecto, comprueba el was y vuelve a intentarlo chaval..." << endl;
        }

        if (i == 2)
        {
            cout << "Macho, has superado el número de intentos, haz el favor de centrarte un poco más la próxima vez." << endl;
        }
    }
}

void DevelopementInProgress(string name_player)
{
    cout << "Querido " << name_player << ". Por el momento esta es la parte del juego disponible." << endl;
    sleep(3);
    cout << "A medida que el tiempo pase, nuevas pistas y rompecabezas se desbloquearán." << endl;
    sleep(2);
    cout << "Ya queda menos para resolver el misterio que esconde EL JUEGO DE LA CARTA :)" <<endl;
}

void DisplayMenu()
{
    std::cout << "\n¿Qué aventura o misión tienes el valor de desbloquear?:" << std::endl;
    std::cout << "I - Información relevante" << std::endl;
    std::cout << "A - Constancia" << std::endl; // Empezar con las imágenes y acabar dando el texto encriptado escrito
    std::cout << "B - Orientación" << std::endl; // Acabar dando la clave: TITANV
    std::cout << "C - Repetición" << std::endl; // Acabar dando el algoritmo y las instrucciones finales
    std::cout << "Q - Salir del juego" << std::endl;    
}

char GetUserSelection()
{
    char selection;
    std::cout << "\nEscribe tu elección: ";
    cin >> selection;

    selection = toupper(static_cast<unsigned char>(selection));
    return selection;
}

void FromMenuToAdventure()
{
    char selection;

    do
    {
        DisplayMenu();
        selection = GetUserSelection();

        switch (selection)
        {
        case 'I':
            std::cout << "Información relevante ha sido selecionada" << std::endl;
            break;
        case 'A':
            std::cout << "La CONSTANCIA no busca el camino más corto, sino el que siempre llega." << std::endl;
            break;
        case 'B':
            std::cout << "Allá vamos con el arte de no perderse incluso sin saber el destino, la ORIENTACIÓN." << std::endl;
            break;
        case 'C':
            std::cout << "Has seleccionado REPETICIÓN, el pulso con que la razón da forma al caos." << std::endl;
            break;
        case 'Q':
            std::cout << "Saliste de EL JUEGO DE LA CARTA. Hasta pronto vaquero :)" << std::endl;
            break;
        
        default:
            std::cout << "Me da a mí que no das pie con bola, hazme el favor de poner una de las opciones permitidas pedazo de bobi..." << std::endl;
            break;
        }
    } while (selection != 'Q');
}