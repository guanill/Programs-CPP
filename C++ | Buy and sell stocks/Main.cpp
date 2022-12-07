/*
Angel Guanill #137916
Andrés Rodríguez #113408
CECS 2222-22
*/

#include <iostream>
#include <iomanip>
using namespace std;
void getAmountOfShare(int*);
float* getPricePerShare();
float* getPercentCommision();
float* getBrokerCommission(int*, float*, float*);
float* getTotal(int*, float*, float*);
void display(int*, float*, float*, float*, float*);

int main() {
    int* amountOfshare = nullptr;
    float* pricePerShare = nullptr;
    float* percentCommision = nullptr;
    float* brokerCommission = nullptr;
    float* total = nullptr;

    amountOfshare = new int;
    pricePerShare = new float;
    percentCommision = new float;
    total = new float;
    getAmountOfShare(amountOfshare);
    pricePerShare = getPricePerShare();
    percentCommision = getPercentCommision();
    cout << "\nACCIONES COMPRADAS\n\n";
    brokerCommission = getBrokerCommission(amountOfshare, pricePerShare, percentCommision);
    total = getTotal(amountOfshare, pricePerShare, brokerCommission);
    display(amountOfshare, pricePerShare, percentCommision, brokerCommission, total);

    return 0;
}

//Funcion que pide la cantidad de acciones
void getAmountOfShare(int* amountOfshare) {
    cout << "Entre la cantidad de acciones: ";
    cin >> *amountOfshare;
}

//Funcion que pide el precio por accion
float* getPricePerShare() {
    float* pricePerShare;
    pricePerShare = new float;
    cout << "Entre el precio de la accion: ";
    cin >> *pricePerShare;
    return pricePerShare;
}

//Funcion que pide el porciento de comision
float* getPercentCommision() {
    float* percentCommision;
    percentCommision = new float;
    cout << "Entre el porcentaje del corredor de la bolsa: ";
    cin >> *percentCommision;
    return percentCommision;
}

//Funcion que calcula la comisión del corredor de la bolsa
float* getBrokerCommission(int* amountOfshare, float* pricePerShare, float* percentCommision) {
    float *brokerCommission = nullptr, *subtotal = nullptr;
    brokerCommission = new float;
    subtotal = new float;
    *subtotal = *amountOfshare * *pricePerShare;
    *brokerCommission = *subtotal * (*percentCommision / 100.0);
    return brokerCommission;
}

//Funcion que calcula el total a pagar
float* getTotal(int* amountOfshare, float* pricePerShare, float* brokerCommission) {
    float* total = nullptr;
    total = new float;
    *total = *amountOfshare * *pricePerShare + *brokerCommission;
    return total;
}

//Funcion que muestra los datos
void display(int* amountOfshare, float* pricePerShare, float* percentCommision, float* brokerCommission, float* total) {
    cout << fixed << setprecision(2) << "La cantidad de acciones es: " << *amountOfshare << endl;
    cout << "El precio de la accion es: $" << *pricePerShare << endl;
    cout << "El porcentaje del corredor de la bolsa es: " << *percentCommision << "%\n";
    cout <<"La comision al corredor es: $" << *brokerCommission << endl;
    cout << "El total a pagar es: $" << *total << endl;
}
