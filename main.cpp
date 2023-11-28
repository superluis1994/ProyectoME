/** LIBRERIAS DEL SISTEMA */
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <ctime>


using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

/** PROCEDIMIENTOS DEL SISTEMA */
void Ingresos();
void buscar();
void sumar();
void restar();
void consultas();
void modificaciones();
void Facturar();
void salir();
void menu();
void FactProd();
void MostrarFact();

/** VARIABLES GLOBALES DEL SISTEMA*/
char nombre[30];
int Codigo = 0;
int auxCodigo = 0;
int CantExistente = 0;
float GranTotal = 0;
float PrecioUnit = 0;
float Total = 0;
float TotalAux = 0;
bool encontrado = false;

int main(int argc, char const *argv[])
{
    system("cls");
    menu();
    return 0;
    system("PAUSE");
}
/**PROCEDIMIENTO PARA EJECUTAR EL MENU*/
void menu(){
    int opcion = 0;

    do{
        system("cls");
        cout<<endl;
        SetConsoleTextAttribute(hConsole,4);
        cout<<"\tOPCIONES DEL INVENTARIO"<<endl<<endl;
        SetConsoleTextAttribute(hConsole,8);
        cout<<"1. Registrar producto en el inventario"<<endl;
        cout<<"2. Mostrar productos del inventario"<<endl;
        cout<<"3. Buscar Producto del inventario"<<endl;
        cout<<"4. Ingresar producto al inventario"<<endl;
        cout<<"5. Extraer producto al inventario"<<endl;
        cout<<"6. Facturar"<<endl;
        cout<<"7. Mostrar Facturas"<<endl;
        cout<<"8. Salir"<<endl;
        SetConsoleTextAttribute(hConsole,2);
        cout<<"Introduce la opcion: "<<endl;
        SetConsoleTextAttribute(hConsole,8);
        cin>>opcion;
        switch (opcion)
        {
        case 1:
          system("cls");
          Ingresos();
          system("pause");
            break;
        case 2:
          system("cls");
          consultas();
          system("pause");
            break;
        case 3:
          system("cls");
          buscar();
          system("pause");
            break;
        case 4:
          system("cls");
          sumar();
          system("pause");
            break;
        case 5:
          system("cls");
          restar();
          system("pause");
            break;
        case 6:
          system("cls");
          Facturar();
          system("pause");
            break;
        case 7:
          system("cls");
          MostrarFact();
          system("pause");
            break;
        case 8:
          system("cls");
          salir();
          system("pause");
            break;

        default:
        cout<<"�Opcion Incorrecta!"<<endl;
            break;
        }

    }while (opcion!=8);
}
/** PROCEDIMIENTO PARA LOS INGRESOS */
void Ingresos(){
    ofstream escritura;
    ifstream consulta;
    bool repetido = false;
    escritura.open("inventario.txt",ios::out|ios::app);
    consulta.open("inventario.txt",ios::in);
    if(escritura.is_open() && consulta.is_open()){
        SetConsoleTextAttribute(hConsole,1);
        cout<<"\tINGRESAR LOS DATOS DEL PRODUCTO"<<endl;
        SetConsoleTextAttribute(hConsole,8);
        cout<<"\tIngrese el codigo del prodcuto: "<<endl;
        cin>>auxCodigo;
        consulta>>Codigo;
        while(!consulta.eof()){
            consulta>>nombre>>CantExistente>>PrecioUnit>>Total;
            if(Codigo == auxCodigo){
                SetConsoleTextAttribute(hConsole,4);
                cout<<"Ya Existe un Registro con este codigo: "<<endl<<endl;
                SetConsoleTextAttribute(hConsole,7);
                repetido=true;
                break;
            }
            consulta>>Codigo;
        }
        if (repetido==false)
        {
            SetConsoleTextAttribute(hConsole,8);
        cout<<"Ingrese el nombre del prodcuto: ";
        cin>>nombre;
        cout<<"Ingrese la cantidad Existente: ";
        cin>>CantExistente;
        cout<<"Ingrese el precio unitario: $.";
        cin>>PrecioUnit;
        cout<<endl<<endl;

        Total = CantExistente*PrecioUnit;
        GranTotal = GranTotal + Total;
        escritura<<endl;
        escritura<<auxCodigo<<"\t"<<nombre<<"\t\t"<<CantExistente<<"\t\t"<<PrecioUnit<<"\t\t"<<Total<<endl;
        SetConsoleTextAttribute(hConsole,2);
        cout<<"\t REGISTRO AGREGADO EXITOSAMENTE"<<endl<<endl;
        SetConsoleTextAttribute(hConsole,7);
        }


    }else{
        SetConsoleTextAttribute(hConsole,4);
        cout<<"\tError, el Archivo no se pudo abrir o no ha sido creado"<<endl<<endl;
        SetConsoleTextAttribute(hConsole,7);
    }
    escritura.close();
    consulta.close();
}
/** CONSULTAS DEL SISTEMA*/
void consultas(){
    ifstream lectura;
    lectura.open("inventario.txt",ios::out|ios::in);
    if(lectura.is_open()){
        lectura>>Codigo;
        SetConsoleTextAttribute(hConsole, 4);
        cout<<"\t\t\t*** DATOS DEL PRODUCTO"<<endl<<endl;
        SetConsoleTextAttribute(hConsole,1);
        cout << "Codigo" <<"\t\tnombre" << "\t\tCantidad" << "\tPrecio U" << "\t  Total" << "\t\tTotal Acumulado" <<endl;
        SetConsoleTextAttribute(hConsole,8);
        cout<<"================================================================================================"<< endl;
        while (!lectura.eof())
        {
           lectura>>nombre>>CantExistente>>PrecioUnit>>Total;
           cout<<"  "<<Codigo;
           cout<<"\t\t"<<nombre;
           cout<<"\t\t"<<"  "<<CantExistente;
           cout<<"\t\t"<<"  $"<<PrecioUnit;
           cout<<"\t\t"<<"    $"<<Total<<endl<<endl;
           lectura>>Codigo;
        }
        cout<<"=============================================================================================="<< endl;
        SetConsoleTextAttribute(hConsole,7);
    }else{
        SetConsoleTextAttribute(hConsole,4);
        cout<<"\tError, el archivo no se pudo abrir, no ha sido creado"<<endl;
        SetConsoleTextAttribute(hConsole,7);
    }
    lectura.close();
    }
/** BUSCAR ENTRE LOS PRODUCTOS DEL SISTEMA*/
void buscar(){

    ifstream lectura;
    lectura.open(" inventario.txt",ios::out|ios::in);
    encontrado=false;
    if(lectura.is_open()){
        SetConsoleTextAttribute(hConsole,1);
        cout<<endl;
        cout<<"CODIGO DEL PRODUCTO A BUSCAR: ";
        SetConsoleTextAttribute(hConsole,8);
        cin>>auxCodigo;
        cout<<endl<<endl;
        lectura>>Codigo;

        while (!lectura.eof())
        {
           if(auxCodigo==Codigo){
            SetConsoleTextAttribute(hConsole,4);
            cout<<"\t DATOS DEL PRODUCTO"<<endl;
            SetConsoleTextAttribute(hConsole,8);
            cout<<"======================================"<<endl;
            cout<<"Codigo: "<<"\t\t\t"<<Codigo<<endl;
            cout<<"Nombre del Producto: "<<"\t\t"<<nombre<<endl;
            cout<<"Cantidad Existente: "<<"\t\t"<<CantExistente<<endl;
            cout<<"Precio Unitario: "<<"\t\t$"<<PrecioUnit<<endl;
            cout<<"Total: "<<"\t\t\t\t$"<<Total<<endl;
            cout<<"======================================"<<endl;
            encontrado = true;
            
           }
        }
        

    }
}