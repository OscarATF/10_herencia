#include <iostream>
#include <string>
using namespace std;

class Vehiculo{
	protected:
		string numeroPlaca;
		string color;
		string marca;
		float velocimetro;
	public:
		Vehiculo(string,string,string,float);
		void mostrarDatos();
		void cambiarVelocidad(float);
};

Vehiculo::Vehiculo(string n,string c,string m,float v) {
	numeroPlaca=n;
	color=c;
	marca=m;
	velocimetro=v;
}

void Vehiculo::mostrarDatos() {
	cout<<"Numero de placa: "<<numeroPlaca<<endl;
	cout<<"Color: "<<color<<endl;
	cout<<"Marca: "<<marca<<endl;
	cout<<"velocimetro: "<<velocimetro<<endl;
}

void Vehiculo::cambiarVelocidad(float velocidad) {
	velocimetro=velocidad;
}

//Clase derivada Automovil
class Automovil:public Vehiculo{
	private:
		int cantidadPuertas;
		int cantidadPasajeros;
	public:
		Automovil(string,string,string,float,int,int);
		void mostrarAutomovil();
		void subirPasajeros(int);
		void bajarPasajeros(int);
};

Automovil::Automovil(string n,string c,string m,float v,int cPuertas,int cPasajeros) : Vehiculo(n,c,m,v) {
	cantidadPuertas=cPuertas;
	cantidadPasajeros=cPasajeros;
}

void Automovil::mostrarAutomovil() {
	mostrarDatos();
	cout<<"Cantidad de Puertas: "<<cantidadPuertas<<endl;
	cout<<"Cantidad de Pasajeros: "<<cantidadPasajeros<<endl;
}

void Automovil::subirPasajeros(int pasajeros) {
	cantidadPasajeros+=pasajeros;
}

void Automovil::bajarPasajeros(int pasajeros) {
	cantidadPasajeros-=pasajeros;
}

//Clase derivada Camion
class Camion:public Vehiculo{
	private:
		string carga;
	public:
		Camion(string,string,string,float,string);
		void mostrarCamion();
		void cambiarCarga(string);
};

Camion::Camion(string n,string c,string m,float v,string _carga) : Vehiculo(n,c,m,v) {
	carga=_carga;
}

void Camion::mostrarCamion() {
	mostrarDatos();
	cout<<"Carga: "<<carga<<endl;
}

void Camion::cambiarCarga(string cambio) {
	carga=cambio;
}

int main() {
	Vehiculo obj("12Y-U76","verde","Ford",26.);
	obj.mostrarDatos(); cout<<endl;
	Automovil obj1("56G-B23","rojo","Hyundai",30.,4,5);
	obj1.cambiarVelocidad(40.5);
	obj1.bajarPasajeros(4);
	obj1.subirPasajeros(1);
	obj1.mostrarAutomovil(); cout<<endl;
	Camion obj2("71G-A34","blanco","Honda",25.,"Papa");
	obj2.cambiarCarga("Arroz");
	obj2.mostrarCamion();
	return 0;
}
