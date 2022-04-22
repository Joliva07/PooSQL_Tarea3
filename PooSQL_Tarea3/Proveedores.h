#pragma once
#include <mysql.h>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Proveedores{
public:
	string proveedor, nit, direccion, telefono;
	int idpro;

public:
	Proveedores() {
	}
	Proveedores(int idp,string prov, string n, string dir, string tel) {
		idpro = idp;
		proveedor = prov;
		nit = n;
		direccion = dir;
		telefono = tel;
	}

	void crear() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.ab_conexion();

		if (cn.getConectar()) {
			string insertar = "insert into proveedores(proveedor,nit,direccion,telefono) values('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "');";
			const char* i = insertar.c_str();
			q_query = mysql_query(cn.getConectar(), i);
			if (!q_query) {
				cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.ce_conexion();
	}

	void leer() {
		int q_query;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.ab_conexion();

		if (cn.getConectar()) {
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_query = mysql_query(cn.getConectar(), c);
			cout << "\n---------- Proveedores ----------\n";
			cout << "\nId Proveedor, Proveedor, Nit, Direccion, telefono\n\n";
			if (!q_query) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << endl;

				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.ce_conexion();
	}

	void actualizar() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.ab_conexion();

		if (cn.getConectar()) {
			string p = to_string(idpro);
			string update = "update proveedores set proveedor='" + proveedor + "',nit='" + nit + "',direccion='" + direccion + "',telefono='" + telefono + "' where idProveedores=" + p + ";";
			const char* i = update.c_str();
			q_query = mysql_query(cn.getConectar(), i);
			if (!q_query) {
				cout << "Actualizacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.ce_conexion();

	}

	void eliminar() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.ab_conexion();

		if (cn.getConectar()) {
			string p = to_string(idpro);
			string elimin = "delete from proveedores where idProveedores=" + p + ";";
			const char* i = elimin.c_str();
			q_query = mysql_query(cn.getConectar(), i);
			if (!q_query) {
				cout << "Eliminacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.ce_conexion();
	}

};

