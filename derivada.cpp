#include <iostream>
#include <locale>
#include <math.h>

using namespace std;

int main (){
    // Ponto a ser calculado
    double x = 1;
    // Valor a ser h da formula da derivada
    double h = 0.025;
    // Funcões da derivada e calculo do f(x + h) e do f(x) da formula de derivada
    double funx = 2 * x * x * x - x * x;
    x = (x + h);
    double funxh = 2 * x * x * x - x * x;

    // Calculo do resultado da derivada
    double resultado =  (funxh - funx) / h;

    // impressão do resultado na tela
    cout << resultado;

    return 0;


}
