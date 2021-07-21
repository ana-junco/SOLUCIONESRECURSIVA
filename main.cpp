#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//Ejrcicios en clase

//1) Diseñe la función que
// utilizando multiplicaciones sucesivas por 10,
// devuelva el total de cifras que tiene un número.

int cuentaCifras (int num)
{
    int i=1, cont=0;
    if(num<0) num=num*-1; //SI ES NEGATIVO, SE LO HACE POSITIVO
    while(i<=num)
    {
        i=i*10;
        cont++;
    }
    return cont;
}
//3) Diseñe la función recursiva que sume
// los n primeros números primos
bool primo(int num)
{
    bool esPrimo= true;
    int i=2;
    while(i<=num/2 && esPrimo)
    {
      if(num%i==0)
          esPrimo= false;
      i++;
    }
    return esPrimo;
}

int sumaprimos(int n)
{
    int i=1; int cont=1;
    int sum=0;
    while(i<=n){
        cont ++;
      if(primo(cont))
      {
          sum+= cont;
          i++;
      }
    }
    return sum;
}
int sumaprimosrecursivo(int limite, int n)
{
    if(limite>0){
        if(primo(n))
            return sumaprimosrecursivo(limite-1,n+1)+n;
        else
            return sumaprimosrecursivo(limite,n+1);
    }
    else
        return 0;

}
void adivinaELNumero(int oportunidades)
{
    srand(time(NULL));
    //Numro aleatorios entre 0 y 50:
    int num=1+ (rand ()%51);
    bool adivinastes=false;
    //int num=15;
    int n;
    cout<<endl<<"ADIVINIA EL NUMERO ENTRE 1 Y 50 ";

    int i=1;
    while(i<= oportunidades && adivinastes== false)
    {
        cout<<endl<<"OPORTUNIDAD #: "<<i;
        cout<<endl<<"INGRESA TU NUMERO: ";
        cin>>n;
        if(n > num)
            cout<<endl<<"DEBES INGRESAR UN NUMERO MAS BAJO...";
        else if(n < num)
            cout<<endl<<"DEBES INGRESAR UN NUMERO MAS ALTO...";
        else{
            cout<<endl<<"FELICIDADES, GANASTES UN PASAJE A GALAPAGOS...";
            adivinastes= true;
        }
         i++;
    }
      if(adivinastes)
          cout<<endl<<"ERES CAMPEON";
      else
      cout<<endl<<"PERDISTES, VUELVE A INTENTARLO...";
}
//El juego de dados:
//Diseñe la función que simule el lanzamiento de 2 dados. Cada dado
// debe generar un número entre 1 y 6. Se pide usar números aleatorios.
//El usuario tiene entre entre 2 o 3 oportunidades
// (usted decide si son 2 o 3 oportunidades).
//El usuario gana cuando los números de ambos dados coinciden o si saca un 11, es decir,
// gana si saca par de unos (1 y 1),
// par de dos (2 y 2) , . . . .o par de seis ( 6 y 6) o también si saca un 11 ( 5 y 6).
//Se pide imprimir la cantidad de "*" según sea el número que sacó el dado, por ejemplo:
//si el dado sacó 5 se imprimirá *****; si sacó 3 se imprime ***;
// se sacó 6 se imprime ******; etc.
//Para tirar los dados puede usar:
//1) presiona enter para tirar los dados
//string cad
//getline(cin, cad);
//2) Ingresa 1 para tirar los dados; 2 para salir
//3) Deseas tirar los dados (S/N)

int input (int mensajes)
{
    if (mensajes == 1)
    {
        cout << "Presione \"ENTER\" LANZAR DADO1"<<endl;
        cin.ignore ();
    }
    else
    {
        cout << "\nPresione \"ENTER\" LANZAR DADO2"<<endl;
    }
    cin.ignore ();
}

int tirardado ()
{
    int ran;
    srand (time (0));
    ran = rand () % 6 + 1;
    cout << " El dado obtuvo " << ran <<endl;
    for (int i=1; i<=ran; i++)
    {
        printf("*");
    }
    return ran;
}
int dado (int primerdado, int segundodado)
{
    if (primerdado==segundodado){
        cout<<endl<<"FELICIDADES GANASTES, TUS DADOS SON PARES";
    }
    else{

        cout<<endl<<"HAS PERDIDO TUS DADOS NO SON PARES Y LA SUMA ES "<<primerdado+segundodado << ", INTENTALO DE NUEVO";
    }
}

int main() {
    int num=-890;
   cout<<endl<<"El numero "<<num<< "Tiene" <<cuentaCifras(num)<< "Cifras" ;
    cout<<endl;
    num=11;
    if(primo(7))
        cout<<num<<"Es primo";
    else
        cout<<num<<"No es primo";

    cout<<endl<<"La suma de los 4 primeros primos es:(2+3+5+7+11) "<<sumaprimos(5);
    cout<<endl<<"La suma recursiva de los 4 primeros primos es:(2+3+5+7+11) "<<sumaprimosrecursivo(5,2);

    srand(time(NULL));
    // Número aleatorios entre 0 y 50:
    num=rand()%51;
    cout<<endl<<"Aleatorios: "<<num;
int opcion;
bool salir=false;
    while(true){
        cout<<endl<<endl<<"MENU PRINCIPAL - ADIVINIA EL NUMERO";
        cout<<endl<<"1. JUGAR";
        cout<<endl<<"2. SALIR";
        cout<<endl<<"CUAL ES TU OPCION: ";
        cin>>opcion;
        switch (opcion){
            case 1:
                adivinaELNumero(5);
                break;
            case 2:
                salir= true;
                break;
            default:
                cout<<endl<<"OPCION NO VALIDAD";

        }
        if(salir)
            break;
    }

    int primerdado, segundodado;
    int opcion1;
    bool salir2=false;
    while(true){
        cout<<endl<<endl<<"JUEGOS DE DADOS";
        cout<<endl<<"1. LANZAR DADOS";
        cout<<endl<<"2. SALIR";
        cout<<endl<<" CUAL ES TU OPCION: ";
        cin>>opcion;

        switch (opcion){
            case 1:
                input (1);
                primerdado = tirardado ();
                input (2);
                segundodado = tirardado ();
                dado(primerdado, segundodado);
                break;
            case 2:
                salir2= true;
                break;
            default:
                cout<<endl<<"OPCION NO VALIDAD";

        }
        if(salir2)
            break;
    }
    return 0;
}
