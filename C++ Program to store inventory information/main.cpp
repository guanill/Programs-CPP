/*
Angel Guanill #137916
Andres Rodriguez #113408
CECS 2222-22

*/

#include "header.h"
#include <iostream>
using namespace std;

int main() {
	int size;
	cout << "Ingrese la cantidad de elementos maximo: ";
	cin >> size;
	Inventory *inventario = nullptr;
	inventario = new Inventory[size];
	
	int counter = 0;

	menu(inventario, counter, size);
}