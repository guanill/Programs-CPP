#ifndef HEADER_H
#define HEADER_H
class Inventory {
private:
	int itemNumber, quantity;
	double cost, totalCost;

public: 
	Inventory();
	Inventory(int itemNumber1, int quantity1, double cost1);
	void setItemNumber();
	void setQuantity();
	void setCost();
	void setTotalCost();
	int getItemNumber();
	int getQuantity();
	double getCost();
	double getTotalCost();
	~Inventory();
};

void menu(Inventory*, int&, int);
void addInstance(Inventory*, int&, int);
void deleteInstance(Inventory*, int&, int);
void editInstance(Inventory*, int);
void printInstance(Inventory*, int);
void printAllInstances(Inventory*, int);



#endif
