#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Atributos
{
public:
    bool viaje;
    int coste;
    Atributos()
    {
        viaje=0;
        coste=0;
    }
    void imprimir()
    {
        cout << "Estado: " ;
        if (viaje)
        {
            cout << "Activo" << endl;
            cout << "Coste: " << coste << endl;
        }
        else
        {
            cout << "Inactivo" << endl;
        }
    }
    void imprimirT()
    {
        if(viaje)
        {
            cout << "V:" << coste;
        }
        else
        {
            cout << "F";
        }
    }
};

Atributos tabla[10][10];
string destinos[10];
int indice;

void agregar();
void eliminar();
void modificar();
void buscar();
void mostrar();

void escribir();
void leer();

int main()
{
    indice=0;

    int opc;
    leer();
    do
    {
        system("clear");
        cout << "\t\t\tTablas de Destinos" << endl << endl;

        cout << "1) Agregar" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Modificar" << endl;
        cout << "4) Buscar" << endl;
        cout << "5) Eliminar" << endl;
        cout << "0) Salir " << endl << endl;

        cout << "Seleccione una opcion" << endl;
        cin >> opc;
        cin.ignore();

        switch(opc)
        {
        case 1:
            agregar();
            break;
        case 2:
            mostrar();
            break;
        case 3:
        	modificar();
            break;
        case 4:
            buscar();
            break;
        case 5:
            eliminar();
            break;
        case 0:
            cout << "Hasta pronto" << endl;
            break;
        default:
            cout << "Esa no es una opcion valida" << endl;
            break;
        }//Fin del switch
        cout << "Presione enter para continuar...";
        cin.ignore();
    }
    while(opc!=0);
    escribir();
    return 0;
}

void agregar()
{
    bool viajeT=false;
    int costeT=0;
    int i=0;
    do
    {
        cout << "Ingrese el nombre del destino" << endl;
        getline(cin,destinos[indice]);
    }
    while(destinos[indice].empty());

    for (i = 0; i <indice; ++i)
    {
        costeT=0;
        cout << "Desea agregar una relacion con " << destinos[i] << " ?" << endl;
        cout << "Ingrese 0 para no y 1 para si: ";
        cin >> viajeT;
        cin.ignore();
        if (viajeT==true)
        {
            cout << "Cual desea que sea el coste del viaje: ";
            cin >> costeT;
            cin.ignore();
        }
        tabla[indice][i].coste=costeT;
        tabla[indice][i].viaje=viajeT;
        //tabla[indice][i].activo=true;

        tabla[i][indice].coste=costeT;
        tabla[i][indice].viaje=viajeT;
        //tabla[i][indice].activo=true;

        cout << "La relacion ha sido creada" << endl;
        cout << destinos[indice] << " hacia " << destinos[i] << endl;
        tabla[indice][i].imprimir();
    }
    cout << "El destino " << destinos[indice] << " ha sido agregado" << endl;
    indice++;
}

void mostrar()
{
    cout << "Destinos";
    for (int i = 0; i < indice; ++i)
    {
        cout << "\t" << destinos[i];
    }
    cout << endl;
    for (int i = 0; i < indice; ++i)
    {
        cout << destinos[i] << "\t";

        for (int j = 0; j < indice; ++j)
        {
            cout << "\t";
            tabla[i][j].imprimirT();
        }
        cout << endl;
    }
}

void eliminar()
{
    string temp;
    int ubicacion;

    cout << "Ingrese el nombre del destino a eliminar: ";
    getline(cin,temp);
    for (int i = 0; i <= indice; ++i)
    {
        if(destinos[i]==temp)
        {
            cout << "Coincidencia encontrada" << endl;
            ubicacion=i;
            for (int i = ubicacion; i < indice; ++i)
            {
                for (int j = 0; j < indice; ++j)
                {
                    tabla[i][j]=tabla[i+1][j];
                }
            }
            for (int j = ubicacion; j < indice; ++j)
            {
                for (int i = 0; i < indice; ++i)
                {
                    tabla[i][j]=tabla[i][j+1];
                }
            }
            for (int i = ubicacion; i < indice; ++i)
            {
                destinos[i]=destinos[i+1];
            }
            indice--;
            cout << "Elemento eliminado" << endl;
            return;
        }
    }
    cout << "Destino no encontrado :c" << endl;
}
void buscar()
{
    string temp;
    int ubicacion;
    cout << "Ingrese el nombre del destino a buscar: ";
    getline(cin,temp);

    for (int i = 0; i < indice; ++i)
    {
        if (destinos[i]==temp)
        {
            cout << "Elemento encontrado" << endl;
            ubicacion=i;
            cout << endl << "Relaciones de " << destinos[ubicacion] << endl;
            for (int i =0; i < indice; ++i)
            {
                if(tabla[ubicacion][i].viaje==true)
                {
                    cout << "Hay una conexion con " << destinos[i] << endl;
                    cout << "Por un coste de: " << tabla[ubicacion][i].coste << endl;
                }
            }
            return;
        }
    }
    cout << "El destino " << temp << "No fue encontrado" << endl;

}
void modificar()
{
    string temp;
    int ubicacion;
    bool decision;
    int costeT;
    cout << "Ingrese el nombre del destino a modificar: ";
    getline(cin,temp);

    for (int i = 0; i < indice; ++i)
    {
        if (destinos[i]==temp)
        {
            cout << "Elemento encontrado" << endl;
            ubicacion=i;
            cout << "Desea cambiar cambiar el nombre del destino?" << endl;
            cout << "1 para cambiar o 0 para dejarlo como " << destinos[ubicacion] << endl;
            cin >> decision;
            cin.ignore();
            if(decision==true)
            {
                cout << "Cual desea que sea el nuevo nombre: ";
                getline(cin,destinos[ubicacion]);
                cout << "Nombre cambiado correctamente\n" << endl;
            }
            for (int i = 0; i < indice; ++i)
            {
            	if (i!=ubicacion)
            	{

            	costeT=0;
                cout << "Desea agregar una relacion con " << destinos[i] << " ?" << endl;
                cout << "Ingrese 0 para no y 1 para si: ";
                cin >> decision;
                cin.ignore();
                if (decision==true)
                {
                    cout << "Cual desea que sea el coste del viaje: ";
                    cin >> costeT;
                    cin.ignore();
                }
                tabla[ubicacion][i].coste=costeT;
                tabla[ubicacion][i].viaje=decision;

                tabla[i][ubicacion].coste=costeT;
                tabla[i][ubicacion].viaje=decision;

                cout << "La relacion ha sido creada" << endl;
                tabla[ubicacion][i].imprimir();
            	}
            }

            return;
        }
    }
    cout << "El destino " << temp << "No fue encontrado" << endl;

}

void escribir()
{
	remove("Destinos.txt");
	remove("Tabla.txt");
	ofstream escribirDest("Destinos.txt",ios::app);
	ofstream escribirTabla("Tabla.txt",ios::app);

	escribirTabla.write((char*)&indice,sizeof(int));
	for (int i = 0; i < indice; ++i)
	{
		escribirDest << destinos[i] << '|';
	}

	for (int i = 0; i < indice; ++i)
	{
		for (int j = 0; j < indice; ++j)
		{
			escribirTabla.write((char*)&tabla[i][j],sizeof(Atributos));
		}
	}
	escribirDest.close();
	escribirTabla.close();
}

void leer()
{
	ifstream leerDest("Destinos.txt");
	ifstream leerTabla("Tabla.txt");

	leerTabla.read((char*)&indice,sizeof(int));
	for (int i = 0; i < indice; ++i)
	{
		getline(leerDest,destinos[i],'|');
	}

	for (int i = 0; i < indice; ++i)
	{
		for (int j = 0; j < indice; ++j)
		{
			leerTabla.read((char*)&tabla[i][j],sizeof(Atributos));
		}
	}
	leerTabla.close();
	leerDest.close();
}