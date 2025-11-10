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

int main(){
    string name_player = IntroAndNamePlayer();

    IntroducePassword();

    DevelopementInProgress(name_player);

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
            sleep(3);
            cout << "Inténtalo de nuevo." << endl;
        }


    } while (!result);

    cout << endl;
    cout << "Bueno, bueno, bueno..." << endl;
    sleep(2);
    cout << "Parece que tenemos ante nosotros al verdadero Potrillo!!!" << endl;
    sleep(3);
    cout << "Mucho me han hablado de ti." << endl;
    sleep(2);
    cout << endl;
    cout << "Todo juego necesita un héroe, tu momento ha llegado jugador!" << endl;
    sleep(2);

    return name_player;
}

void IntroducePassword()
{
    cout << "Para asegurarme de que tengo ante mí al legítimo jugador de este juego necesito una última comprobación." << endl;
    sleep(3);
    cout << "Dime el nombre del grupo de tus amigos del instituto: ";

    for (size_t i { 0 }; i <= 2; i++)
    {
        string first_password;
        getline(cin, first_password);

        if (first_password == "Coc(keros) y permanente")
        {
            cout << "jajajsjdsksajdskadjjajajdaidkjjaja" << endl;
            cout << first_password << endl;
            sleep(2);
            cout << "Lo sé, el nombre es lamentable, pero son tus amigos y hay que quererlos." << endl;
            sleep(2);
            cout << "Ahora sí, en... ";
            sleep(1);
            cout << "3, ";
            sleep(1);
            cout << "2, ";
            sleep(1);
            cout << "1... ";
            sleep(1);
            cout << "empieza..." << endl <<endl;

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