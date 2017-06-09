// Programa para calculo da aproximação da área da integral

#include <iostream>
#include <locale>
#include <math.h>
#include <iomanip>

 using namespace std;

// função da integral
  double func(double x){

    return 3 *( x * x);

 }

// calculo do delta x
 double deltax (double aa,double bb, double nn){

    return (bb - aa) / nn;

 }

// calculo do ponto medio do primeiro retangulo
 double priMedio(double x, double aa,double bb, double nn){

     return x = (x + (x + ((bb - aa) / nn))) / 2;

 }


 int main () {
    setlocale(LC_ALL, "Portuguese");
    // Numeros de retangulos
    double n = 4.0;

    // Intervalos
    double a = 1.0;
    double b = 3.0;

    // Condicional caso o "b" for maior que "a"
    if (a > b){
        a = a + b;
        b = a - b;
        a = a - b;
        cout << "O resultado da integral é: " << "-";
    }else {
        cout << "O resultado da integral é: ";
    }

    // variavel para armazenar a soma das areas dos retangulos
    double xi = 0;


    double x = a;


    // laço para calcular a soma das areas do retangulo
    for ( x = priMedio(x, a, b, n); x < b; x = x + deltax(a, b, n)){

        // Soma das areas dos retangulo
        xi = xi + func(x);
    }

    // Calculo da aproximação da integral
    double resultado = deltax(a, b, n) * xi;

    // Impressão do resultado
    cout << setprecision(2) << resultado << endl;

    return 0;

 }




