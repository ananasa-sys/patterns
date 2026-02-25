#include <iostream>
#include <string>
using namespace std;

class Beverage
{
public:
	virtual string getDescription() = 0;
	virtual double cost() = 0;
};

class Espresso : public Beverage
{
public:
	string getDescription() override { return "Эспрессо"; }
	double cost() override { return 1.99; }
};


class CondinentDecorator : public Beverage
{
protected:
	Beverage* beverage;
public:
	CondinentDecorator(Beverage* b) : beverage(b) {}
	string getDescription() override { return beverage->getDescription(); }
	double cost() override { return beverage->cost(); }
};

class Milk : public CondinentDecorator
{
public:
	Milk(Beverage* b) : CondinentDecorator(b) {}
	string getDescription() override { return beverage->getDescription() + ", Молоко"; }
	double cost() override { return beverage->cost() + 0.05; }
};

class Sugar : public CondinentDecorator
{
public:
	Sugar(Beverage* b) : CondinentDecorator(b) {}
	string getDescription() override { return beverage->getDescription() + ", Сахар"; }
	double cost() override { return beverage->cost() + 0.15; }
};

class Syrup : public CondinentDecorator
{
public:
	Syrup(Beverage* b) : CondinentDecorator(b) {}
	string getDescription() override { return beverage->getDescription() + ", Сироп"; }
	double cost() override { return beverage->cost() + 0.10; }
};

int main()
{
	setlocale(LC_ALL, "ru");

	Beverage* drink = new Espresso();
	drink = new Milk(drink);
	drink = new Sugar(drink);
	drink = new Syrup(drink);

	cout << drink->getDescription() << " стоит $" << drink->cost() << endl;

	Beverage* simpledrink = new Espresso();
	cout << drink->getDescription() << " стоит $" << simpledrink->cost() << endl;

	delete drink;
	delete simpledrink;
}

