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
void menu();
void Ingresos();
void consultas();
void buscar();
void sumar();
void restar();
void modificaciones();
void Facturar();
void salir();
void FactProd();
// void MostrarFact();

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
        // cout<<"7. Mostrar Facturas"<<endl;
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
        // case 7:
        //   system("cls");
        //   MostrarFact();
        //   system("pause");
        //     break;
        case 8:
          system("cls");
          salir();
          system("pause");
            break;

        default:
        cout<<"!Opcion Incorrecta!"<<endl;
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
        cout<<"\tIngrese el codigo del producto: "<<endl;
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
        cout<<"Ingrese el nombre del producto: ";
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
    lectura.open("inventario.txt",ios::out|ios::in);
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
    //    minuto del video 6:55 url del video: https://www.youtube.com/watch?v=orNpC4TZ1H0&t=834s&ab_channel=Fher-nandoChal%C3%AD
    //    linea del codigo: 222
           }
           lectura>>Codigo;
           SetConsoleTextAttribute(hConsole, 7);
        }
        if(encontrado==false) {
           SetConsoleTextAttribute(hConsole, 4);
            cout<<"\tNO EXISTE EL REGISTRO CON EL CODIGO "<<auxCodigo<<endl<<endl<<endl;
           SetConsoleTextAttribute(hConsole, 7);
        }


    }else{
           SetConsoleTextAttribute(hConsole, 4);
            cout<<"\tNO SE PUEDE ABRIR EL ARCHIVO, AUN NO HA SIDO CREADO "<<endl<<endl;
           SetConsoleTextAttribute(hConsole, 7);
    }
    lectura.close();
}

void sumar(){
    ofstream aux;
    ifstream lectura;
    encontrado = false;
    int auxCodigo = 0;
    int auxCant;
    aux.open("auxiliar.txt",ios::out);
    lectura.open("inventario.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        SetConsoleTextAttribute(hConsole, 1);
        cout<<endl<<endl;
        cout<<"INGRESE EL CODIGO DEL PRODUCTO A CARGAR: ";
        cin>>auxCodigo;
        cout<<endl<<endl;
        lectura>>Codigo;
        while (!lectura.eof())
        {
            lectura>>nombre>>CantExistente>>PrecioUnit>>Total;
            if(auxCodigo == Codigo){
                encontrado = true;
                SetConsoleTextAttribute(hConsole, 4);
                cout<<"\tDATOS DEL PRODUCTO AL QUE DESEA CARGAR"<<endl;
                SetConsoleTextAttribute(hConsole, 8);
                cout<<"========================================"<<endl;
                cout<<"Codigo: "<<"\t\t\t"<<Codigo<<endl;
                cout<<"Nombre del Producto: "<<"\t\t"<<nombre<<endl;
                cout<<"Cantidad Existente: "<<"\t\t"<<CantExistente<<endl;
                cout<<"Precio Unitario: "<<"\t\t$"<<PrecioUnit<<endl;
                cout<<"Total: "<<"\t\t\t\t$"<<Total<<endl;
                cout<<"========================================"<<endl;
                SetConsoleTextAttribute(hConsole, 1);
                cout<<"INGRESE LA CANTIDAD DE "<<nombre<<" A CARGAR  ";
                cin>>auxCant;
                SetConsoleTextAttribute(hConsole, 7);
                if(auxCant>0){
                    CantExistente = CantExistente+auxCant;
                    Total = CantExistente*PrecioUnit;
                    aux<<Codigo<<"\t"<<nombre<<"\t"<<CantExistente<<"\t"<<PrecioUnit<<"\t"<<Total<<endl;
                    SetConsoleTextAttribute(hConsole, 2);
                    cout<<endl<<endl;
                    cout<<"\tCANTIDAD ACTUALIZADA"<<endl<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else{
                    SetConsoleTextAttribute(hConsole, 4);
                    cout<<endl<<endl;
                    cout<<"\tCANTIDAD NO VALIDA"<<endl<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    aux<<Codigo<<"\t"<<nombre<<"\t"<<CantExistente<<"\t"<<PrecioUnit<<"\t"<<Total<<endl;

                }
            }else{
                    aux<<Codigo<<"\t"<<nombre<<"\t"<<CantExistente<<"\t"<<PrecioUnit<<"\t"<<Total<<endl;

            }
            lectura>>Codigo;
        }


    }else{
        SetConsoleTextAttribute(hConsole, 4);
        cout<<endl<<endl;
        cout<<"\tNO SE PUDO ABRIR ELARCHIVO O AUN NO HA SIDO CREADO"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);

    }
    if (encontrado == false)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<"\tNO EXISTEN REGISTROS CON EL CODIGO "<<auxCodigo<<endl<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
    }
    aux.close();
    lectura.close();
    remove("inventario.txt");
    rename("auxiliar.txt","inventario.txt");

}

void restar(){
    ofstream aux;
    ifstream lectura;
    encontrado = false;
    int auxCodigo = 0;
    int auxCant;
    aux.open("auxiliar.txt",ios::out);
    lectura.open("inventario.txt",ios::in);
    if (aux.is_open() && lectura.is_open())
    {
        SetConsoleTextAttribute(hConsole, 1);
        cout<<"INGRESE EL CODIGO EL PRODUCTO A DESCARGAR: ";
        cin>>auxCodigo;
        cout<<endl<<endl;
        lectura>>Codigo;
        while (!lectura.eof())
        {
            lectura>>nombre>>CantExistente>>PrecioUnit>>Total;
            if(auxCodigo == Codigo){
                encontrado=true;
                SetConsoleTextAttribute(hConsole, 4);
                cout<<"\tDATOS DEL PRODUCTO AL QUE SERA DESCARGADO"<<endl;
                SetConsoleTextAttribute(hConsole, 8);
                cout<<"========================================"<<endl;
                cout<<"Codigo: "<<"\t\t\t"<<Codigo<<endl;
                cout<<"Nombre del Producto: "<<"\t\t"<<nombre<<endl;
                cout<<"Cantidad Existente: "<<"\t\t"<<CantExistente<<endl;
                cout<<"Precio Unitario: "<<"\t\t$"<<PrecioUnit<<endl;
                cout<<"Total: "<<"\t\t\t\t$"<<Total<<endl;
                cout<<"========================================"<<endl;
                SetConsoleTextAttribute(hConsole, 1);
                cout<<"INGRESE LA CANTIDAD A DESCARGAR DEL INVENTARIO DEL PRODUCTO"<<nombre<<": ";
                SetConsoleTextAttribute(hConsole, 8);
                cin>>auxCant;
                cout<<endl;
                if (auxCant <= CantExistente)
                {
                    CantExistente = CantExistente-auxCant;
                    Total = CantExistente*PrecioUnit;
                    aux<<Codigo<<"\t"<<nombre<<"\t"<<CantExistente<<"\t"<<PrecioUnit<<"\t"<<Total<<endl;
                    SetConsoleTextAttribute(hConsole, 2);
                    cout<<"\tREGISTRO MODIFICADO"<<endl<<endl<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else{
                    SetConsoleTextAttribute(hConsole, 4);
                    cout<<"\tNO HAY"<<auxCant<<" UNIDADES DISPONIBLES"<<endl<<endl<<endl;
                    aux<<Codigo<<"\t"<<nombre<<"\t"<<CantExistente<<"\t"<<PrecioUnit<<"\t"<<Total<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }else{
                aux<<Codigo<<"\t"<<nombre<<"\t"<<CantExistente<<"\t"<<PrecioUnit<<"\t"<<Total<<endl;
            }
            lectura>>Codigo;
        }

    }else{
        SetConsoleTextAttribute(hConsole, 4);
        cout<<"\tNO SE PUDO ABRIR EL ARCHIVO O AUN NO HA IDO CREADO"<<endl<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
    }
    if (encontrado == false)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout<<"\tNO EXISTENTE RESGITROS CON EL CODIGO"<<auxCodigo<<endl<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 7);
    }
    aux.close();
    lectura.close();
    remove("inventario.txt");
    rename("auxiliar.txt","inventario.txt");
}
void Facturar(){
    ofstream escritura;
    ofstream aux;
    ifstream lectura;
    encontrado = false;
    int auxCodigo = 0;
    int auxCant;
    int DUI;
    char NombreCliente[50];
    float superTotal;

    escritura.open("FACTURA.txt",ios::out|ios::app);
    std::time_t t = std::time(0);

    escritura<<endl;
    escritura<<"\t\tDOCUMENTO TRIBUTARIO ELECTRONICO"<<endl<<endl;
    escritura<<"\t\t\tFACTURA ELECTRONICA"<<endl;
    escritura<<"\t\t\txxxxxxxxxxxxxxxxxxx"<<endl;
    escritura<<"======================= DATOS DEL EMISOR =========================="<<endl;
    escritura<<"\t\t\tDUI: 111111111"<<endl;
    escritura<<"\t\t\tCOMERCIAL LA U"<<endl;
    escritura<<"\t"<<"      "<<"Santa Ana 24.av Norte"<<endl;
    escritura<<"\t\t"<<"      "<<"El SALVADOR"<<endl<<endl;
    escritura<<"======================= DATOS DEL COMPROBANTE ====================="<<endl;
    std::tm* now =std::localtime(&t);
    escritura<<"Fecha: ";
    escritura<<now->tm_mday <<'-'<<(now->tm_mon + 1) << '-' << (now->tm_year + 1900)<< "\n";
    cout<<"INGRESE EL DUI DEL CONTRIBUYENTE"<<endl;
    cin>>DUI;
    escritura<<"DUI: "<<DUI<<endl;
    cout<<"INGRESE EL NOMBRE"<<endl;
    cin>>NombreCliente;
    escritura<<"NOMBRE: "<<NombreCliente<<endl<<endl<<endl;
    escritura<<"======================= DESCRIPCION DE LA FACTURA =================="<<endl;
    escritura<<"Cod."<<"\tPRODUCTO"<<"\tCant."<<"\t\tPRECIO"<<"\t\tTotal"<<endl;

    int Opc = 0;
    do
    {
       system("cls");
       aux.open("auxiliar.txt",ios::out);
       lectura.open("inventario.txt",ios::in);
       cout<<endl;
       SetConsoleTextAttribute(hConsole, 4);
       cout<<"\tAGREGAR PRODUCTO A LA FACTURA"<<endl<<endl;
       SetConsoleTextAttribute(hConsole, 8);
       cout<<"1. FACTURAR UN PRODUCTO"<<endl;
       cout<<"2. SALIR"<<endl;
       SetConsoleTextAttribute(hConsole, 2);
       cout<<"QUE DESEAS HACER? ";
       SetConsoleTextAttribute(hConsole, 8);
       cin>>Opc;
       switch (Opc)
       {
       case 1:
             system("cls");
             if(aux.is_open() && lectura.is_open()){
                SetConsoleTextAttribute(hConsole, 1);
                 cout<<"INGRESE EL CODIGO DEL A FACTURAR: ";
                 cin>>auxCodigo;
                 cout<<endl<<endl;
                 lectura>>Codigo;
                 while (!lectura.eof())
                 {
                    lectura>>nombre>>CantExistente>>PrecioUnit>>Total;
                    if(auxCodigo == Codigo){
                        encontrado = true;


                        SetConsoleTextAttribute(hConsole, 4);
                        cout<<"\tDATOS DEL PRODUCTO A FACTURAR"<<endl;
                        SetConsoleTextAttribute(hConsole, 8);
                        cout<<"========================================"<<endl;
                        cout<<"Codigo: "<<"\t\t\t"<<Codigo<<endl;
                        cout<<"Nombre del Producto: "<<"\t\t"<<nombre<<endl;
                        cout<<"Cantidad Existente: "<<"\t\t"<<CantExistente<<endl;
                        cout<<"Precio Unitario: "<<"\t\t$"<<PrecioUnit<<endl;
                        cout<<"Total: "<<"\t\t\t\t$"<<Total<<endl;
                        cout<<"========================================"<<endl;
                        SetConsoleTextAttribute(hConsole, 1);
                        cout<<"INGRESE LA CANTIDAD A DESCARGAR DEL INVENTARIO DEL PRODUCTO"<<nombre<<": ";
                        SetConsoleTextAttribute(hConsole, 8);
                        cin>>auxCant;
                        cout<<endl;
                        if(auxCant <= CantExistente){
                            CantExistente  = CantExistente - auxCant;
                            Total = CantExistente*PrecioUnit;
                            TotalAux = auxCant*PrecioUnit;
                            superTotal = superTotal + TotalAux;
                            aux<<Codigo<<"\t"<<CantExistente<<"\t"<<PrecioUnit<<"\t"<<Total<<endl;
                            escritura<<" "<<auxCodigo<<"\t"<<nombre<<"\t\t"<<" "<<auxCant<<"\t\t"<<" $."<<PrecioUnit<<"\t\t"<<" $."<<Total<<endl;
                            SetConsoleTextAttribute(hConsole, 2);
                            cout<<"\t REGISTRO MODIFICADO"<<endl<<endl<<endl;
                            SetConsoleTextAttribute(hConsole, 7);
                        }else{
                            SetConsoleTextAttribute(hConsole, 4);
                            cout<<"\tNO HAY "<<auxCant<<" UNIDADES DISPONIBLES"<<endl<<endl<<endl;
                            aux<<Codigo<<"\t"<<nombre<<"\t"<<CantExistente<<"\t"<<PrecioUnit<<"\t"<<Total<<endl;
                            SetConsoleTextAttribute(hConsole, 7);
                        }

                    }else{
                            aux<<Codigo<<"\t"<<nombre<<"\t"<<CantExistente<<"\t"<<PrecioUnit<<"\t"<<Total<<endl;

                    }
                    lectura>>Codigo;
                 }

             }else{
                SetConsoleTextAttribute(hConsole, 4);
                cout<<"\tNO SE PUDO ABRIR EL ARCHIVO O AUN NO HA SIDO CREADO"<<endl<<endl<<endl;
                SetConsoleTextAttribute(hConsole, 7);
             }
             if(encontrado == false){
                SetConsoleTextAttribute(hConsole, 4);
                cout<<"\tNO EXISTEN REGISTROS CON EL CODIGO"<<auxCodigo<<endl<<endl<<endl;
                SetConsoleTextAttribute(hConsole, 7);
             }
             aux.close();
             lectura.close();
             remove("inventario.txt");
             rename("auxiliar.txt","inventario.txt");
             system("pause");
        break;
        case 2:
                system("cls");
                salir();

       default:
            cout<<"!Opcion Incorrecta"<<endl;
        break;
       }
    } while (Opc!=2);
    escritura<<"\t\t\t\t\t--------------------------------"<<endl;
    escritura<<"\t\t\t\t\tTotal "<<"\t\t"<<" $."<<superTotal;
    escritura<<endl<<endl<<endl;
    escritura<<"\t\t"<<"      "<<"SUJETO A PAGOS TRIMESTRALES"<<endl<<endl;
    escritura<<"\t\t\tDATOS DEL CERTIFICADOR"<<endl;
    escritura<<"\t\t\t"<<"    "<<"DUI: 111111111"<<endl;
    escritura<<"\t\t"<<"     "<<"FACTURA DE NIÑÁ MARY"<<endl<<endl;
    escritura<<"\tCAJERO: EMMANUEL EYES"<<endl;
    escritura<<"\tCODIGO: 23344556"<<endl;
    escritura<<endl<<endl<<endl<<endl<<endl;
    escritura.close();
}
// void MostrarFact(){
//     char cadena[100];

//     ifstream apertura("FACTURA.txt");
//     if(apertura.fail()){
//         cout<<"EL ARCHIVO NO EXISTE"<<endl;
//     }else{
//         while (apertura.getline(cadena,100) != NULL)
//         {
//             cout<<cadena<<endl;
//         }

//     }
// }

void salir(){
    SetConsoleTextAttribute(hConsole, 2);
    cout<<endl<<endl;
    cout<<"\t\tPROGRAMA FINALIZADO"<<endl<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 7);
}
