// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <list>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int TAMANO_REGISTRO = 14;
//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    if(!out.is_open()){
        out.open(nombre_archivo.c_str());
    }

    out.seekp(posicion*40);
    out.write((char*)&mascota->edad,4);
    out.write(mascota->nombre.c_str(),36);
    out.close();

    /*FILE * archivo= new FILE(nombre_archivo);
    archivo = fopen(nombre_archivo,"rb+");
    fseek(archivo,posicion,SEEK_SET);
    int size= sizeof(string);
    char * data= new char[size+4];
    int pos=0;
    memcpy(&data[pos],&mascota->edad,4);
    pos+=4;
    memcpy(&data[pos],&mascota->nombre,size);
    pos+=size;
    fwrite(data,posicion,12,archivo);
    archivo=fclose(nombre_archivo);*/
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{

    Mascota *m = new Mascota(-1,"");
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*40);
    int edad;
    char nombre[36];
    in.read((char*)&edad,4);
    in.read(nombre,36);
    m->edad = edad;
    m->nombre = nombre;
    return m;}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo) {
    for (int c = 0; c < nombre_archivo.length();c++) {
        char nombre[10];
        int edad;
        ifstream in(nombre_archivo.c_str());
        in.seekg(c * TAMANO_REGISTRO);
        in.read(nombre, 10);
        in.read((char *) &edad, 4);
        vector<Mascota *> respuesta;
        return respuesta;
    }
}
int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}