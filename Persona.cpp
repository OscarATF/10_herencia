#include <iostream>
#include <string>
using namespace std;

//Clase base persona

class Persona{
	protected:
		string nombres;
		string DNI;
		int edad;
	public:
		Persona(string, string, int); //prototipo constructor
		void mostrarDatos();
};

Persona::Persona(string n,string d,int e) { //constructor
	nombres=n;
	DNI=d;
	edad=e;
}

void Persona::mostrarDatos() {
	cout<<nombres<<" tiene el DNI# "<<DNI<<" y tiene "<<edad;
	cout<<" anios de edad."<<endl;
}

//Clase derivada Docente
class Docente:public Persona{
	private:
		int sueldo;
		string especialidad;
	public:
		Docente(string,string,int,int,string);
		void mostrarDocente();
		//void ingresarNotas();
		//void visualizarRegistro();		
};

Docente::Docente(string n,string d,int e,int s,string es) : Persona(n,d,e) {
	sueldo=s;
	especialidad=es;
}

void Docente::mostrarDocente() {
	mostrarDatos();
	cout<<"\tes un docente con un sueldo de S/"<<sueldo;
	cout<<" y tiene la especialidad: "<<especialidad<<endl;
}

//Clase derivada Estudiante
class Estudiante:public Persona{
	private:
		int notas[5];
		int nNotas;
		string codigo;
	public:
		Estudiante(string,string,int,int[],int,string);
		//void visualizarNotas();
		void mostrarEstudiante();
};

Estudiante::Estudiante(string n,string d,int e,int no[],int nn,string c)
	:Persona(n,d,e) {
		nNotas=nn;
		for(int i=0;i<nn;i++) {
			notas[i]=no[i];
		}
		codigo=c;
} 

void Estudiante::mostrarEstudiante() {
	mostrarDatos();
	cout<<"\tes un estudiante con codigo "<<codigo<<" y tiene "<<nNotas<<" notas: ";
	for (int i=0;i<nNotas;i++) {
		cout<<notas[i]<<" ";
	}
	cout<<endl;
}

int main() {
	string nombre;
	Persona p("Juan Perez","40302010",25);
	p.mostrarDatos(); cout<<endl;
	Docente d("Pablo Iglesias","10203040",54,3000,"Auditoria informatica");
	d.mostrarDocente(); cout<<endl;
	int nota[]={20,19,18};
	cout<<"Ingrese nombre de estudiante: "; fflush(stdin); getline(cin,nombre);
	Estudiante e(nombre,"90706050",19,nota,3,"2021-123");
	e.mostrarEstudiante(); cout<<endl;
	return 0;
}