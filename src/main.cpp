// Proyecto_Berlin: EL JUEGO DE LA CARTA

#include <iostream>
#include <unistd.h>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string IntroAndNamePlayer();

void IntroducePassword(string name_player);

void DevelopementInProgress(string name_player);

void DisplayMenu();

char GetUserSelection();

void FromMenuToAdventure(string name_player);

void InformacionRelevante(string name_player);

void Constancia(string name_player);

void Orientacion(string name_player);

void Repeticion(string name_player);

void Historia(string name_player);

int main(){
    string name_player = IntroAndNamePlayer();

    IntroducePassword(name_player);

    FromMenuToAdventure(name_player);

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
        transform(name_player.begin(), name_player.end(), name_player.begin(),[](unsigned char c){ return tolower(c); });
        
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

void IntroducePassword(string name_player)
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
            cout << "Ahora sí... 3, 2, 1 ... empieza" << endl;
            sleep(1);

            cout << "\n================ EL JUEGO DE LA CARTA ================" << endl << endl;
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
    cout << "\n===============================================================================" << endl;
    cout << "Querido " << name_player << ". Por el momento esta es la parte del juego disponible." << endl;
    cout << "A medida que el tiempo pase, nuevas pistas y rompecabezas se desbloquearán." << endl;
    cout << "Ya queda menos para resolver el misterio que esconde EL JUEGO DE LA CARTA :)" <<endl;
    cout << "===============================================================================" << endl;
}

void DisplayMenu()
{
    cout << "\n¿Qué aventura o misión tienes el valor de desbloquear?:" << endl;
    cout << "I - Información relevante" << endl;
    cout << "C - Constancia" << endl; // Empezar con las imágenes y acabar dando el texto encriptado escrito
    cout << "O - Orientación" << endl; // Acabar dando la clave: TITANV
    cout << "R - Repetición" << endl; // Acabar dando el algoritmo y las instrucciones finales
    cout << "Q - Salir del juego" << endl; // Meter alguna pista secreta
}

char GetUserSelection()
{
    char selection;
    cout << "\nEscribe tu elección: ";
    cin >> selection;

    selection = toupper(static_cast<unsigned char>(selection));
    return selection;
}

void FromMenuToAdventure(string name_player)
{
    char selection;

    do
    {
        DisplayMenu();
        selection = GetUserSelection();

        switch (selection)
        {
        case 'I':
            InformacionRelevante(name_player);
            break;
        case 'H':
            Historia(name_player);
        case 'C':
            Constancia(name_player);
            break;
        case 'O':
            Orientacion(name_player);
            break;
        case 'R':
            Repeticion(name_player);
            break;
        case 'Q':
            cout << "\nSaliste de EL JUEGO DE LA CARTA. Hasta pronto vaquero :)" << endl;
            break;
        
        default:
            cout << "Me da a mí que no das pie con bola, hazme el favor de poner una de las opciones permitidas pedazo de bobi..." << endl;
            break;
        }
    } while (selection != 'Q');
}

void InformacionRelevante(string name_player)
{
    cout << "Información relevante ha sido selecionada:" << endl;
    cout << "\nBasta ya de misterios, el juego ha comenzado y es necesario dejar ciertas cosas claras." << endl;
    cout << "Con motivo de tu cumpleaños y tu visita a la nación que te vio crecer, un de tus amigos, uno ciertamente extraño, te entregó una carta encriptada." << endl;
    cout << "Además esta carta venía acompañada de dos fotografías." << endl;
    cout << "El objetivo de este juego, del cual tú eres su jugador, es resolver todos los misterios que rodean a la carta y acabar desvelando su contenido." << endl;
    cout << "\nLa aventura continúa " << name_player << ", vayamos de vuelta al menú principal." << endl;
}

void Historia(string name_player)
{
    cout << "La historia vive en quien la recuerda y la comparte." << endl;
    // Hacer un relato alegórico que sirva de narrativa para el juego (ideas de chatgpt)
    // Se puede intentar meter la palabra secreta que salga a partir del menú principal (CHOIR)
    DevelopementInProgress(name_player);
}

void Constancia(string name_player)
{
    cout << "La CONSTANCIA no busca el camino más corto, sino el que siempre llega." << endl;
    // / Empezar con las imágenes y acabar dando el texto encriptado escrito gracias a la ayuda de Holmie14.
    DevelopementInProgress(name_player);
}

void Orientacion(string name_player)
{
    cout << "Allá vamos con el arte de no perderse incluso sin saber el destino, la ORIENTACIÓN." << endl;
    // Acabar dando la clave: TITANV
    // Dar contexto de mi trabajo y de la orientacion que depende de satélites. Estos satélites se lanzan con cohetes que queman combustible
    // aunque nosotros conseguimos hacer uno de agua. Deja que te impulse y oriente, es la clave que buscabas (rollo adivinanza y poetico). 
    DevelopementInProgress(name_player);
}

void Repeticion(string name_player)
{
    cout << "Has seleccionado REPETICIÓN, el pulso con que la razón da forma al caos." << endl;
    // Mediante esta prueba va a conseguir el archivo con el algoritmo (script de python).
    // Comentar algo de serpientes, sonidos repatitivos e imnóticos.
    // Hacer un laberinto que viaje de menu en menu. Para salir y conseguir el objetivo habrá
    // que replicar de alguna forma la clave que se ha conseguido en la historia.
    DevelopementInProgress(name_player);
}