// Programa para calculo da aproximação da área da integral

#include <iostream>
#include <locale>
#include <math.h>
#include <iomanip>
#include <cmath>

 using namespace std;

double funcSegundoGrau(double, double, double, double);
double funcExponecial(double, double);
double funcLog(double, double);

double deltax (double, double, double);
double priMedio(double, double );


int main () {
    setlocale(LC_ALL, "Portuguese");

    double escolhaFun, a, b, c, expoenteIns;
    cout << "Digite:\n"
         << "1 para função do segundo grau\n"
         << "2 para função exponencial\n"
         << "3 para logaritmo natural\n"
         << "4 para logaritmo "<< endl ;
    cin >> escolhaFun;

     if (escolhaFun == 1){
        cout << "Digite o valor de a: ";
        cin >> a;
        cout << "Digite o valor de b: ";
        cin >> b;
        cout << "Digite o valor de c: ";
        cin >> c;


    }else if (escolhaFun == 2){

        cout << "Digite o valor do expoente: ";
        cin >> expoenteIns;

    }

    // Numeros de retangulos
    double numeroRetangulos;
    cout << "Insira o valor de n" << endl;
    cin >> numeroRetangulos;

    // Intervalos
    double pontoInicial;
    cout << "Insira o valor inicial" << endl;
    cin >> pontoInicial;

    double pontoFinal;
    cout << "Insira o valor final" << endl;
    cin >> pontoFinal;



    //variavel do ponto medio
    double xi;
    // variavel da soma dos pontos medios
    double somaXi = 0;
    //Variavl do resultado
    double resultado;

    // Condicional caso o "b" for maior que "a"
    if (pontoInicial > pontoFinal){
        pontoInicial = pontoInicial + pontoFinal;
        pontoFinal = pontoInicial - pontoFinal;
        pontoInicial = pontoInicial - pontoFinal;
        cout << "O resultado da integral é: " << "-";
    }else {
        cout << "O resultado da integral é: ";
    }

    xi = priMedio(a, deltax(pontoInicial, pontoFinal, numeroRetangulos));


    // laço para calcular a soma das areas do retangulo
    for ( xi ; xi < pontoFinal; xi += deltax(pontoInicial, pontoFinal, numeroRetangulos)){

        // Soma das areas dos retangulo
        if (escolhaFun == 1){
            somaXi = somaXi + funcSegundoGrau(xi, a, b, c);

        }else if (escolhaFun == 2){
            somaXi = somaXi + funcExponecial(xi, expoenteIns);

        }else if (escolhaFun == 3 || escolhaFun == 4){
            somaXi = somaXi + funcLog(xi, escolhaFun);
        }

    }

    // Calculo da aproximação da integral
    resultado = deltax(pontoInicial, pontoFinal, numeroRetangulos) * somaXi;

    // Impressão do resultado
    cout << setprecision(4) << resultado << endl;

    return 0;

 }

// função para calculo de funçção do segundo grau
 double funcSegundoGrau(double x, double a, double b, double c){

    return a * x * x + b * x + c;
 }

// Função de uma função exponencial
 double funcExponecial(double x, double expoente){

    return pow(x,expoente);
 }

// Funçção de uma função logaritmica
 double funcLog(double x, double numDaEscolha){

    if (numDaEscolha == 3){

        return log (x);

    }else if (numDaEscolha == 4){

        return log10 (x);
    }

 }

// calculo do delta x
double deltax (double aa,double bb, double nn){

    return (bb - aa) / nn;

}

// calculo do ponto medio do primeiro retangulo
double priMedio(double x0, double aa){

    return (2 * x0 + aa) / 2;

}
