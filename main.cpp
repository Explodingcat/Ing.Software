#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

using namespace std;


const std::string currentDateTime() {

    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}

void azar(){

    int opciones[25];
    int numero,primero;
    int contador = 0;

    ifstream archivolec("sorteo.csv");
    ofstream archivoesc;

    for(int c = 0; c < 25 ; c++){

        opciones[c] = 0;
    }

    primero = rand()%(25);
    opciones[primero] = 1;
    contador++;

    while(contador < 14){

        numero = rand()%(25);

        if(opciones[numero] == 0){

            opciones[numero] = 1;
            contador++;
        }

    }

    archivoesc.open("sorteo.csv",ios::app);

    if(!archivolec.eof()){

        archivoesc << currentDateTime();
        archivoesc << " ";
        for(int i = 0; i <25 ; i++){

        if(opciones[i] == 1){

           archivoesc << i+1 << ";";

        }

    }
        archivoesc << endl;

    }


    archivoesc.close();
    archivolec.close();

    cout<< "sorteo.csv escrito correctamente" << endl;

}


int main(int argc,char *argv[]){

    string op;

    cout << "Al lote,ria \n";


        if(strcmp(argv[1], "-g") == 0){

            azar();
            cout << "Sorteo Creado \n";


        }
        else if(strcmp(argv[1], "-v") == 0){

            cout << "Integrantes y Fecha Compilacion \n";
            cout << "Felipe Roa 18340207-2 \nFelipe Veloso 17065475-7 \nRoberto Rocuant 17375963-0 \nCompilacion  20/03/2015 22:26";


        }

}



