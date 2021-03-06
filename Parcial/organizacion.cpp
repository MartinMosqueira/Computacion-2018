#include "organizacion.h"
#include <iostream>
#include "myconnection.h"

using namespace std;
Organizacion::Organizacion()
{
    nombre="";

}

Organizacion::Organizacion(string nombre)
{
    this->setNombre(nombre);
}

void Organizacion::agregar()
{
	string stringSQL;
     stringstream values;
	 values << this->getNombre();
     stringSQL = "INSERT INTO organizacion (nombreOrganizacion) VALUES ('"+values.str()+"');";
     MyConnection::instance()->execute(stringSQL);
	 this->inicio();
}

void Organizacion::inicio(){
	cout<<"<html><head>"<<endl;
	    cout<<"<link href='https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css' rel='stylesheet' integrity='sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO' crossorigin='anonymous'>"<<endl;
	    cout << "</head>" <<endl;
	    cout << "<body>   <div class='container'>"<<endl;
	    cout<<"<div class='centrar'><h2>Organizaciones Cargadas</h2></div>"<<endl;
	    cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
	    cout << "<thead><tr>" << endl;
	    cout << "<th >ID</th>"<< endl;
	    cout << "<th >Eliminar</th>"<<endl;
	    cout << "<th >Organizaci&oacute;n</th>"<< endl;
	    cout << "</tr></thead>" << endl;
	    cout << "<tbody><tr>" << endl;
	    
	    this->listar();
	        cout << "</tr>" << endl;
	        cout << "</tr></tbody>" << endl;
	        cout << "</table>" << endl;
	        cout<<"<div class='centrar'><h2>Agregar Organizacion</h2></div>"<<endl;
	        cout<<"<form class='form-signin'  method='post'>"<<endl;
	        cout<<"<input type='text' id='dni' name='nombreOrganizacion' class='form-control' placeholder='Nombre Organizacion' required>"<<endl;
	        cout<<"<br>"<<endl;
	        cout<<"<br>"<<endl;
	        cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Enviar</button>"<<endl;
	        cout<<"</form>"<<endl;
	        cout<<"</div></body></html>"<<endl;
}

void Organizacion::listar()
{
	 MyConnection myconnection;
	    myconnection.connect();
	    sql::ResultSet* personas = myconnection.query("SELECT organizacion.id, organizacion.nombreOrganizacion FROM computacion.organizacion ORDER BY organizacion.nombreOrganizacion ASC;");

	    while (personas->next()) {
	        cout << "<td> " << personas->getString("id") << "</td>" << endl;
	        cout << "<td>" << personas->getString("nombreOrganizacion") << "</td>" << endl;
	        cout << "<a class='btn btn-danger' style='width: 100px' href='Parcial2?eliminar=" + personas->getString("id") + "'" << endl;
	        cout << ">X</a>" << endl;
	        cout << "</tr>" << endl;
	    }
}

void Organizacion::eliminar(string x){
    stringstream stringSQL;
    stringSQL <<"DELETE FROM organizacion WHERE id = "<< x <<";";
    MyConnection::instance()->execute(stringSQL.str());
}

void Organizacion::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Organizacion::getNombre()
{
    return this->nombre;
}
