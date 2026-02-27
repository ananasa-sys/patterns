#include <iostream>
#include <string>
using namespace std;

/// \brief Интерфейс для создания напитка
class Beverage
{
public:
	virtual string getDescription() = 0;
	virtual double cost() = 0;
};

/// \brief Класс для напитка ЭСПРЕССО
class Espresso : public Beverage
{
	/**
	* \brief Функция для получения описания напитка
	* \return string - строку, название напитка
	* \remark получаем только название, тк это учебный код
	*/
public:
	/**
	* \brief Функция для получения стоимости напитка
	* \return double - стоимость напитка
	* \note ни на что не влияет, тк учебный код
	*/
	string getDescription() override { return "Эспрессо"; }
	double cost() override { return 1.99; }
};

class Tea : public Beverage
{
	/**
	* \brief Функция для получения описания напитка
	* \return string - строку, название напитка
	* \remark получаем только название, тк это учебный код
	*/
public:
	/**
	* \brief Функция для получения стоимости напитка
	* \return double - стоимость напитка
	* \note ни на что не влияет, тк учебный код
	*/
	string getDescription() override { return "Чай"; }
	double cost() override { return 1.50; }
};

/**
* \brief Декоратор для добавок к напиткам
*/
class CondinentDecorator : public Beverage
{
protected:
	Beverage* beverage;
public:
	/**
	* \brief Конструктор декоратора
	* Указатель на напиток, который нужно декорировать
	*/
	CondinentDecorator(Beverage* b) : beverage(b) {}
	/**
	* \brief Функция для получения описания напитка с добавками
	* \return string - строку с описанием
	*/
	string getDescription() override { return beverage->getDescription(); }
	/**
	* \brief Функция для получения стоимости напитка с добавками
	* \return double - общую стоимость
	*/
	double cost() override { return beverage->cost(); }
};

class Milk : public CondinentDecorator
{
public:
	/**
	* \brief Конструктор декоратора молока
	* Указатель на напиток, в который добавляем молоко
	*/
	Milk(Beverage* b) : CondinentDecorator(b) {}
	/**
	* \brief Функция для получения описания напитка с молоком
	* \return string - строку с описанием
	*/
	string getDescription() override { return beverage->getDescription() + ", Молоко"; }
	/**
	* \brief Функция для получения стоимости напитка с молоком
	* \return double - общую стоимость с учетом добавки
	*/
	double cost() override { return beverage->cost() + 0.05; }
};

class Sugar : public CondinentDecorator
{
public:
	/**
	* \brief Конструктор декоратора сахара
	* Указатель на напиток, в который добавляем сахар
	*/
	Sugar(Beverage* b) : CondinentDecorator(b) {}
	/**
	* \brief Функция для получения описания напитка с сахаром
	* \return string - строку с описанием
	*/
	string getDescription() override { return beverage->getDescription() + ", Сахар"; }
	/**
	* \brief Функция для получения стоимости напитка с сахаром
	* \return double - общую стоимость с учетом добавки
	*/
	double cost() override { return beverage->cost() + 0.15; }
};

class Syrup : public CondinentDecorator
{
public:
	/**
	* \brief Конструктор декоратора сиропа
	* Указатель на напиток, в который добавляем сироп
	*/
	Syrup(Beverage* b) : CondinentDecorator(b) {}
	/**
	* \brief Функция для получения описания напитка с сиропом
	* \return string - строку с описанием
	*/
	string getDescription() override { return beverage->getDescription() + ", Сироп"; }
	/**
	* \brief Функция для получения стоимости напитка с сиропом
	* \return double - общую стоимость с учетом добавки
	*/
	double cost() override { return beverage->cost() + 0.10; }
};

class Chocolate : public CondinentDecorator
{
public:
	/**
	* \brief Конструктор декоратора шоколада
	* Указатель на напиток, в который добавляем шоколад
	*/
	Chocolate(Beverage* b) : CondinentDecorator(b) {}
	/**
	* \brief Функция для получения описания напитка с шоколадом
	* \return string - строку с описанием
	*/
	string getDescription() override { return beverage->getDescription() + ", Шоколад"; }
	/**
	* \brief Функция для получения стоимости напитка с шоколадом
	* \return double - общую стоимость с учетом добавки
	*/
	double cost() override { return beverage->cost() + 0.20; }
};

/// \brief Функция для запуска конвеера
/// \note Используется для учебного кода
int main()
{
	setlocale(LC_ALL, "ru");

	/**
	* \brief Создание напитков с добавками/без и вывод их общей стоимости
	*/
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

