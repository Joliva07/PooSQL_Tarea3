
#include <iostream>
#include <string>
#include "Proveedores.h"
using namespace std;

int main()
{
    string  prove, nit, direccion, telefono;
    int idprov=0, op = 0;
    Proveedores l = Proveedores(idprov, prove, nit, direccion, telefono);
    cout << "1. Insertar datos\n2. Ver informacion\n3. Actualizar datos\n4. Eliminar informacion";
    cout << "\nIngrese el numero de la accion que desea realizar: ";
    cin >> op;
    

     if (op == 1) {
         cin.ignore();
         cout << "Ingrese nombre del proveedor: ";
         getline(cin, prove);
         cout << "Ingrese nit del proveedor: ";
         getline(cin, nit);
         cout << "Ingrese direccion del proveedor: ";
         getline(cin, direccion);
         cout << "Ingrese el telefono del proveedor: ";
         getline(cin, telefono);
         
         Proveedores p=Proveedores(idprov, prove, nit, direccion, telefono);
         p.crear();
     }
     if (op==2) {
         l.leer();
     }
     if (op==3) {
         l.leer();
         cout << "\nIngrese el id del proveedor que desea actualizar: ";
         cin >> idprov;
         cin.ignore();
         cout << "Ingrese nombre del proveedor: ";
         getline(cin, prove);
         cout << "Ingrese nit del proveedor: ";
         getline(cin, nit);
         cout << "Ingrese direccion del proveedor: ";
         getline(cin, direccion);
         cout << "Ingrese el telefono del proveedor: ";
         getline(cin, telefono);
         Proveedores p = Proveedores(idprov, prove, nit, direccion, telefono);
         p.actualizar();
     }
     if (op == 4) {
         l.leer();
         cout << "\nIngrese el id del proveedor que desea eliminar: ";
         cin >> idprov;
         Proveedores p = Proveedores(idprov, prove, nit, direccion, telefono);
         p.eliminar();
     }

}

