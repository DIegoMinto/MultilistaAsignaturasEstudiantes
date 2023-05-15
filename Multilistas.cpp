//Estudiante: Minto Arze Javier Diego
//Carrrera: Ingenieria de Sistemas
//Grupo Teo: 2
//Grupo Lab: 2
#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

class nodoestudiante{
public:
	string codigo, nombre, direccion, sexo;
	struct nodoestudiante *siguienteEs;
};

class nodoasig{
public:
	string codigo, descripcion;
	int cantidad;
	struct nodoasig *siguiente;
	struct nodoasig *anterior;
	struct nodoestudiante * pestudiante;
};

nodoasig *primero,*ultimo; 
nodoestudiante *primeroEs, *ultimoEs;

void iniciar()
{
	primero=NULL;
	ultimo=NULL;
	primeroEs=NULL;
	ultimoEs=NULL;
}

int vacia()
{
	if (primero==NULL)
		return 1;
	else
		return 0;
}

class Asignatura{
public:
	
	void insertar_delante ( string cod, string nomb, int cant)
	{
		nodoasig *nodo;
		nodo= new nodoasig;
		nodo->siguiente=NULL;
		nodo->anterior=NULL;
		nodo->pestudiante=NULL;
		nodo->codigo=cod;
		nodo->descripcion=nomb;
		nodo->cantidad=cant;
		if (vacia())
		{
			primero=nodo;
			primero->siguiente=NULL;
			primero->anterior=NULL;
			ultimo=nodo;
		}
		else
		{
			nodo->siguiente=primero;
			nodo->anterior=NULL;
			primero=nodo;
		}
		return;
	}
	
	void mostrar ()
	{
		nodoasig *p;
		if (vacia())
			cout<<"Lista vacia";
		else
		{
			p = primero ;
			while (p != NULL){
				cout<< p->codigo<<endl;
				cout<< p->descripcion<<endl;
				cout<< p->cantidad<<endl;
				p = p->siguiente;
				getchar();
			}
		}
		return;
	}
	
	void eliminar(string valor)
	{
		nodoasig *p,*q;
		q=primero;
		p=primero;
		while ((p!= NULL) && (p->codigo!=valor))
		{
			q=p; 
			p = p->siguiente;
		}
		if (p==NULL)
			cout<<"No existe ese elemento en la lista";
		else
		{
			if (primero==ultimo)
			{
				primero=NULL;
				ultimo=NULL;
			}
			else
			{
				q->siguiente=p->siguiente; 
				if (p==primero)
					primero=p->siguiente;
				else
					if (p==ultimo)
						ultimo=q;
			}
		}
		return;
	}
	
	void cantidadAsignaturas()
	{
		nodoasig *p;
		int contasig = 0;
		p=primero;
		
		do{
			contasig=contasig+1;
			p=p->siguiente;
		}while(p!=NULL);
		cout<<"Cantidad de asignaturas que es imparten: "<<contasig<<endl;
		getchar();
	}
	
	
	
};
class Estudiante{
public:
	
	nodoasig *Buscar_Asignatura(string valor)
	{
		nodoasig *p,*q;
		q=primero;
		p=primero;
		while ((p!= NULL) && (p->codigo!=valor))
		{
			q=p; 
			p = p->siguiente;
		}
		return p;
	}
	
	void insertar_estudiante ( string codasig, string codest, string nomb, string dir, string sexo)
{
	nodoestudiante *nodo;
	nodoasig *p;
	nodo= new nodoestudiante;
	nodo->siguienteEs=primeroEs;
	nodo->codigo=codest;
	nodo->nombre=nomb;
	nodo->direccion=dir;
	nodo->sexo=sexo;
	p=Buscar_Asignatura(codasig);
	if (p==NULL)
		cout<<"No existe esa asignatura";
	else
	{
		nodo->siguienteEs=p->pestudiante;
		p->pestudiante=nodo;
	}
	return;
}

void mostrar_estudiantes (string valor)
{
	nodoasig *p;
	nodoestudiante *q;
	p=Buscar_Asignatura(valor);
	if (p==NULL) cout<<"No existe esa asignatura";
	else
	{
		q= p->pestudiante ;
		do{
			cout<< q->codigo<<endl;
			cout<< q->nombre<<endl;
			cout<< q->direccion<<endl;
			cout<< q->sexo<<endl;
			q = q->siguienteEs;
		}while (q != primeroEs);
	}
	getchar();
	return;
}

void mostrar_todo ()
{
	nodoasig *p;
	nodoestudiante *q;
	if (vacia())
		cout<<"Lista vacia";
	else
	{
		p = primero ;
		while (p != NULL){
			cout<< p->codigo<<endl;
			cout<< p->descripcion<<endl;
			cout<< p->cantidad<<endl;
			q=p->pestudiante;
			do{
				cout<< q->codigo<<endl;
				cout<< q->nombre<<endl;
				cout<< q->direccion<<endl;
				cout<< q->sexo<<endl;
				q=q->siguienteEs;
				getchar();
			}while (q != primeroEs);
			p = p->siguiente;
			getchar();
		}
	}
	return;
}

void eliminar_estudiante(string valor1, string valor2)
{
	nodoasig *p;
	nodoestudiante *q,*r;
	p=Buscar_Asignatura(valor1);
	if (p==NULL)
		
		cout<<"No existe esa asignatura";
	else
	{
		q=p->pestudiante;
		r=q;
		while ((q!= NULL) && (q->codigo!=valor2))
		{
			r=q; 
			q = q->siguienteEs;
		}
		if (q==NULL)
			cout<<"Ese estudiante no cursa esa asignatura";
		else
		{
			r->siguienteEs=q->siguienteEs; 
			if (q==p->pestudiante)
				p->pestudiante=q->siguienteEs;
		}
	}
	return;
}

void cantidadEstudiantes(string valorBusc)
{
	nodoasig *p;
	nodoestudiante *q;                            
	p=Buscar_Asignatura(valorBusc);
	int cont=0;
	q = p->pestudiante;
	do{
		cont=cont+1;
		q = q->siguienteEs;
	}while(q!=NULL);
	cout<<"cantidad de estudiantes en esta asignatura: "<<cont<<endl;
	getchar();
}
void MostrarSexoMas(string valor)
{
	nodoasig *p;
	nodoestudiante *q;
	p=Buscar_Asignatura(valor);
	if (p==NULL) cout<<"No existe esa asignatura";
	else
	{
		q= p->pestudiante ;
		do{
			if(q->sexo=="Mas"){
			cout<< q->codigo<<endl;
			cout<< q->nombre<<endl;
			cout<< q->direccion<<endl;
			cout<< q->sexo<<endl;
			q = q->siguienteEs;
			}
			else
			q = q->siguienteEs;
		}while (q != primeroEs);
	}
	getchar();
	return;
}
void MostrarSexoFem(string valor)
{
	nodoasig *p;
	nodoestudiante *q;
	p=Buscar_Asignatura(valor);
	if (p==NULL) cout<<"No existe esa asignatura";
	else
	{
		q= p->pestudiante ;
		do{
			if(q->sexo=="Fem"){
				cout<< q->codigo<<endl;
				cout<< q->nombre<<endl;
				cout<< q->direccion<<endl;
				cout<< q->sexo<<endl;
				q = q->siguienteEs;
			}
			else
			   q = q->siguienteEs;
		}while (q != primeroEs);
	}
	getchar();
	return;
}
};
int main(int argc, char *argv[]) {
	int cant;
	string cod, nombre, c,c1, sexo;
	string codest,nombreest,direst, valorBusc;
	int opc;
	Asignatura o1;
	Estudiante o2;
	iniciar();
	do
	{
		system("cls");
		cout<<" LISTA DE ASIGNATURAS"<<endl;
		cout<<" Seleccione la opcion a realizar\n\n";
		cout<<" 1.- Insertar una asignatura\n";
		cout<<" 2.- Eliminar una asignatura\n";
		cout<<" 3.- Mostrar toda la lista de asignaturas\n";
		cout<<" 4.- Insertar un estudiante en una asignatura\n";
		cout<<" 5.- Eliminar un estudiante\n";
		cout<<" 6.- Mostrar todos los estudiantes de una asignatura\n";
		cout<<" 7.- Mostrar toda la multilista\n";
		cout<<" 8.- Mostrar cantidad de Estudiantes en una asignatura\n";
		cout<<" 9.- Mostrar cantidad de asignaturas que se imparten\n";
		cout<<" 10.- Mostrar Estudiantes Masculinos de una Asignatura\n";
		cout<<" 11.- Mostrar Estudiantes Femeninos de una Asignatura\n";
		cout<<" \n\n\nOpcion(1-12): ";
		
		
		cin>>opc;
		switch(opc)
		{
		case 1:
			cod="";
			nombre="";
			cant=0;
			cout<<"Entre los Datos de la Asignatura:\n ";
			cout<<"Codigo o siglas de la Asignatura: \n";
			cin>>cod;
			cout<<"Nombre de la Asignatura: \n";
			cin>>nombre;
			cout<<"Cantidad de Horas:\n ";
			cin>>cant;
			o1.insertar_delante(cod,nombre,cant);
			break;
		case 2:
			cout<<"codigo de la Asignatura a eliminar: \n";
			cin>>c;
			o1.eliminar(c);
			getchar();
			break;
		case 3:
			o1.mostrar();
			cout<<"Oprima una tecla para salir";
			getchar();
			break;
		case 4:
			cout<<"Entre los Datos de la Asignatura y del Estudiante:\n ";
			cout<<"Codigo o siglas de la Asignatura: \n";
			cin>>cod;
			cout<<"Identificador del estudiante: \n";
			cin>>codest;
			cout<<"Nombre del estudiante: \n";
			cin>>nombreest;
			cout<<"Direccion del Estudiante:\n ";
			cin>>direst;
			cout<<"Sexo del Estudiante(Mas/Fem):\n ";
			cin>>sexo;
			o2.insertar_estudiante(cod, codest,nombreest,direst, sexo);
			cout<<"Oprima una tecla para salir";
			getchar();
			break;
		case 5:
			cout<<"codigo de la Asignatura que cursa el estudiante: \n";
			cin>>c;
			cout<<"codigo del estudiante: \n";
			cin>>c1;
			o2.eliminar_estudiante(c, c1);
			getchar();
			break;
		case 6:
			cout<<"codigo de la Asignatura a Mostrar sus estudiantes: \n";
			cin>>c;
			o2.mostrar_estudiantes(c);
			cout<<"Oprima una tecla para salir";
			getchar();
			break;
		case 7:
			o2.mostrar_todo();
			cout<<"Oprima una tecla para salir";
			getchar();
			break;
		case 8:
			cout<<"Codigo de la Asignatura para mostrar sus estudiantes: \n";
			cin>>valorBusc;
			o2.cantidadEstudiantes(valorBusc);
			cout<<"Oprima una tecla para salir";
			getchar();
			break;
		case 9:
			o1.cantidadAsignaturas();
			cout<<"Oprima una tecla para salir";
			getchar();
			break;
		case 10:
			string valor;
			cout<<"Ingrese Codigo de la Asignatura:"<<endl;
			cin>>valor;
			o2.MostrarSexoMas(valor);
			getchar();
			break;
		}
		if(opc==11)
		{
			string valor;
			cout<<"Ingrese Codigo de la Asignatura:"<<endl;
			cin>>valor;
			o2.MostrarSexoFem(valor);
			getchar();
		}
	}
	while ((opc!=12));
	return 0;
}
