// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
int tamano_registro = 14;
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in|ios::out);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion* tamano_registro);
    out.write((char*)&mascota->edad,4);
    out.write(mascota->nombre.c_str(),10);
    out.close();
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
    int edad;
    char nombre[10];
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion * tamano_registro);
    in.read((char*)&edad,4);
    in.read(nombre,10);
    Mascota *m = new Mascota(edad,nombre);
    return m;
    
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

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta;
    Mascota * mascotaNueva;
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,ios::end);
    int tamano_bytes = in.tellg();
    double cantidad_mascotas = tamano_bytes/tamano_registro;
    int edad;
    char nombre[10];

    for(int i=0;i<cantidad_mascotas;i++)
    {
        in.seekg(i * tamano_registro);
        in.read((char*)&edad,4);
        in.read(nombre,10);
        mascotaNueva = new Mascota(edad,nombre);
        respuesta.push_back(mascotaNueva);
    }
        in.close();
    return respuesta;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
