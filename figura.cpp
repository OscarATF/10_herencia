#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Figura{
	protected:
		string color;
	public:
		Figura(string); //prototipo constructor
		void mostrarColor();
	};

Figura::Figura(string _color) { //constructor
	color=_color;
}

void Figura::mostrarColor() {
	cout<<"Color: "<<color<<endl;
}

class Circulo:public Figura{
	private:
		float radio;
	public:
		Circulo(string,float);
		float calcularArea();
		float calcularPerimetro();
};

Circulo::Circulo(string _color,float _radio) : Figura(_color) {
	radio=_radio;
}

float Circulo::calcularArea() {
	return M_PI*pow(radio,2);
}

float Circulo::calcularPerimetro() {
	return 2*M_PI*radio;
}

class Rectangulo:public Figura{
	private:
		float base;
		float altura;
	public:
		Rectangulo(string,float,float);
		float calcularArea();
};

Rectangulo::Rectangulo(string _color,float _base,float _altura) : Figura(_color) {
	base=_base;
	altura=_altura;
}

float Rectangulo::calcularArea() {
	return base*altura;
}

class Triangulo:public Figura{
	private:
		float base;
		float altura;
		string tipo;
	public:
		Triangulo(string,float,float,string);
		float calcularArea();
};

Triangulo::Triangulo(string _color,float _base,float _altura,string _tipo) : Figura(_color) {
	base=_base;
	altura=_altura;
	tipo=_tipo;
}

float Triangulo::calcularArea() {
	return (base*altura)/2;
}


int main() {
	Triangulo obj1("verde",4.,5.,"rectangulo");
	obj1.mostrarColor();
	cout<<obj1.calcularArea()<<endl;
	Rectangulo obj2("rojo",5.,4.);
	obj2.mostrarColor();
	cout<<obj2.calcularArea()<<endl;
	Circulo obj3("azul",3.);
	obj3.mostrarColor();
	cout<<obj3.calcularArea()<<endl;
	cout<<obj3.calcularPerimetro()<<endl;
}