#pragma once
#include <mysql.h>
#include <iostream>
class ConexionBD
{
private: MYSQL* conectar;
public:
	void ab_conexion() {
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "usr_productos", "123456j.", "db_productos", 3306, NULL, 0);
	}
	MYSQL* getConectar() {
		return conectar;
	}
	void ce_conexion() {
		mysql_close(conectar);
	}

};

