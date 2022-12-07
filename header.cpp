#include "header.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Funcion contructora default
Inventory::Inventory() {
	itemNumber = 0;
	quantity = 0;
	cost = 0;
	totalCost = 0;
}

//Funcion constructora con parametros
Inventory::Inventory(int itemNumber1, int quantity1, double cost1) {
	itemNumber = itemNumber1;
	quantity = quantity1;
	cost = cost1;
	setTotalCost();
}

//Funcion que pide el numero de articulo
void Inventory::setItemNumber() {

	cout << "Entre numero de articulo: ";
	cin >> itemNumber;
	while (itemNumber < 0)
	{
		cout << "\nEl numero de articulo no puede ser negativo, entre de nuevo. ";
		cout << "\nNumero de articulo: ";
		cin >> itemNumber;
	}
}

//Fucnion que pide la cantidad del articuolo
void Inventory::setQuantity() {

	cout << "Entre cantidad del articulo: ";
	cin >> quantity;
	while (quantity < 0)
	{
		cout << "\nLa cantidad del articulo no puede ser negativo, entre de nuevo.";
		cout << "\nCantidad del articulo: ";
		cin >> quantity;
	}
	setTotalCost();
}

//Funcion que pide el costo del articulo
void Inventory::setCost() {

	cout << "Entre el costo del articulo: $";
	cin >> cost;
	while (cost < 0)
	{
		cout << "\nEl costo del articulo no puede ser negativo, entre de nuevo.";
		cout << "\nCosto del articulo: ";
		cin >> cost;
	}
	setTotalCost();
}

//Funcion que calcula el costo total
void Inventory::setTotalCost() {

	totalCost = quantity * cost;
}

//Funcion que retorna el numero de articulo 
int Inventory::getItemNumber() {
	return itemNumber;
}

//Funcion que retorna la cantidad del articulo
int Inventory::getQuantity() {
	return quantity;
}

//Funcion que retorna el costo del articulo
double Inventory::getCost() {
	return cost;
}

//Funcion que retorna el costo total del articulo
double Inventory::getTotalCost() {
	return totalCost;
}

//Funcion destructorra
Inventory::~Inventory() {

}


//Funcion que muestra el menu
void menu(Inventory *inventario,int &counter, int size) {
	int option = 0;


	do {


		cout << "\n1 - Anadir una instancia\n2 - Remover instancia\n3 - Modificar instancia\n4 - Imprimir contenido del arreglo\n5 - Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> option;
		while (option > 5 || option < 1) 
		{
			cout << "Opcion no existente.\nOpcion: ";
			cin >> option;
		}
		switch (option) {
		case 1:
			addInstance(inventario, counter, size);
			break;
		case 2:
			deleteInstance(inventario, counter, size);
			break;
		case 3:
			editInstance(inventario, counter);
			break;
		case 4:
			printAllInstances(inventario, counter);
			break;
		}
	} while (option != 5);
}

//Funcion que añade una instancia
void addInstance(Inventory *inventario, int &counter, int size) {

	if (counter != size)
	{
		inventario[counter].setItemNumber();
		inventario[counter].setQuantity();
		inventario[counter].setCost();
		inventario[counter].setTotalCost();
		counter++;
	}
	else
	{
		cout << "\nHAS LLEGADO AL LIMITE DE ARTICULOS\n";
	}
}

//Funcion que elimina una instancia
void deleteInstance(Inventory *inventario, int& counter, int size) {
	
	if (counter > 0) 
	{
		int itemNumber, temp = counter;
		cout << "Entre el numero de articulo de la instancia que desea eliminar: ";
		cin >> itemNumber;

		for (int i = 0; i < counter; i++)
		{
			if (inventario[i].getItemNumber() == itemNumber)
			{
				inventario[i] = inventario[counter-1];
				counter--;
				cout << "\nARTICULO ELIMINADO CORRECTAMENTE\n";
			}
			
		}
		if (temp == counter)
		{
			cout << "\nARTICULO NO ENCONTRADO\n";
		}
	}
	else
	{
		cout << "\nNO ES POSIBLE ELIMINAR, NO HAY ARTICULOS INGRESADOS\n";
	}
}

//Funcion que edita una instancia
void editInstance(Inventory* inventario, int counter) {
	if (counter > 0)
	{
		int itemNumber;
		cout << "Entre el numero de articulo de la instancia que desea editar: ";
		cin >> itemNumber;
		int *option = nullptr;
       
		for (int i = 0; i < counter; i++)
		{
			if (inventario[i].getItemNumber() == itemNumber)
			{
				cout << "\nARTICULO ENCONTRADO\n\n";
				printInstance(inventario, i);

				
				cout << "\n1 - Numero\n2 - Cantidad\n3 - Costo\nSeleccione el dato que desea editar: ";
				option = new int;
				cin >> *option;
				while (*option < 1 || *option > 3) {
					cout << "Opcion no existente\n\nSeleccione el dato que desea editar: ";
					cin >> *option;
				}

				switch (*option) {
				case 1:
					inventario[i].setItemNumber();
					break;
				case 2:
					inventario[i].setQuantity();
					break;
				case 3:
					inventario[i].setCost();
					break;
				}

				cout << "\nINFORMACION EDITADA CORRECTAMENTE\n";
			}
			else if (i == counter - 1 && option == 0) 
			{
				cout << "\nARTICULO NO ENCONTRADO\n";
			}
		}
	}
	else
		cout << "\nNO ES POSIBLE EDITAR, NO HAY ARTICULOS INGRESADOS\n";

}

//Funcion que muestra la informacion de una sola instancia
void printInstance(Inventory* inventario, int instanceIndex) {
	cout << "Numero de articulo: " << inventario[instanceIndex].getItemNumber() << endl
		<< "Cantidad de articulos: " << inventario[instanceIndex].getQuantity() << endl
		<< "Costo del articulo: $"<< fixed << setprecision(2) << inventario[instanceIndex].getCost() << endl
		<< "Costo total: $" << inventario[instanceIndex].getTotalCost() << endl;
}


//Funcion que muestra la informacion de todas las intancias
void printAllInstances(Inventory* inventario, int counter) {

	if (counter > 0)
	{
		cout << "\nNumero\t\tCantidad\tCosto\t\tCosto Total\n";
		for (int i = 0; i < counter; i++)
		{
			cout << inventario[i].getItemNumber() << "\t\t" << inventario[i].getQuantity() << "\t\t"
				<< fixed << setprecision(2) << "$" << inventario[i].getCost() << "\t\t" << "$" << inventario[i].getTotalCost() << endl;
		}
	}
	else
	{
		cout << "\nNO ES POSIBLE MOSTRAR, NO HAY ARTICULOS INGRESADOS\n";
	}
}