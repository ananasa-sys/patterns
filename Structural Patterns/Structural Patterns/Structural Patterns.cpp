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

class Tea : public Beverage
{
public:
	string getDescription() override { return "Чай"; }
	double cost() override { return 1.50; }
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

class Chocolate : public CondinentDecorator
{
public:
	Chocolate(Beverage* b) : CondinentDecorator(b) {}
	string getDescription() override { return beverage->getDescription() + ", Шоколад"; }
	double cost() override { return beverage->cost() + 0.20; }
};

int main()
{
	setlocale(LC_ALL, "ru");

	Beverage* drink = new Espresso();
	drink = new Milk(drink);
	drink = new Sugar(drink);
	drink = new Syrup(drink);
	drink = new Chocolate(drink);

	cout << drink->getDescription() << " стоит $" << drink->cost() << endl;

	Beverage* simpledrink = new Espresso();
	cout << simpledrink->getDescription() << " стоит $" << simpledrink->cost() << endl;

	Beverage* newdrink = new Espresso();
	newdrink = new Milk(newdrink);
	newdrink = new Sugar(newdrink);
	newdrink = new Chocolate(newdrink);

	cout << newdrink->getDescription() << " стоит $" << newdrink->cost() << endl;

	Beverage* teadrink = new Tea();
	teadrink = new Milk(teadrink);
	teadrink = new Syrup(teadrink);

	cout << teadrink->getDescription() << " стоит $" << teadrink->cost() << endl;

	delete drink;
	delete simpledrink;
	delete newdrink;
	delete teadrink;

}

