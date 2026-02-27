#include <iostream>
#include <string>
using namespace std;

/// \brief Интерфейс для персонажей
class Character
{
public:
	virtual string getType() = 0;
	virtual void attack() = 0;
};

/// \brief Класс с настройками для персонажа ВОИН
class Warrior : public Character
{
	/**
	* \brief Функция для получения типа персонажа
	* \return string - строку, название персонажа
	* \remark получаем только имя персонажа, тк это учебный код
	*/
public:
	string getType() override { return "Воин"; }
	/**
	* \brief Функция для выполнения действий персонажа
	* \note не влияет ни на что, тк учебный код
	* \todo добавить возможность отбирать жизни у того, на кого нападаем
	*/
	void attack() override { cout << "Воин атакует мечом!" << endl; }
};
/// \brief Класс с настройками для персонажа МАГ
class Mage : public Character
{
	/**
	* \brief Функция для получения типа персонажа
	* \return string - строку, название персонажа
	* \remark получаем только имя персонажа, тк это учебный код
	*/
public:
	string getType() override { return "Маг"; }
	/**
	* \brief Функция для выполнения действий персонажа
	* \note не влияет ни на что, тк учебный код
	* \todo добавить возможность отбирать жизни у того, на кого нападаем
	*/
	void attack() override { cout << "Маг кастует огненный шар!" << endl; }
};
/// \brief Класс с настройками для персонажа ЛУЧНИК
class Archer : public Character
{
	/**
	* \brief Функция для получения типа персонажа
	* \return string - строку, название персонажа
	* \remark получаем только имя персонажа, тк это учебный код
	*/
public:
	string getType() override { return "Лучник"; }
	/**
	* \brief Функция для выполнения действий персонажа
	* \note не влияет ни на что, тк учебный код
	* \todo добавить возможность отбирать жизни у того, на кого нападаем
	*/
	void attack() override { cout << "Лучник стреляет из лука!" << endl; }
};
/// \brief Класс с настройками для персонажа РЫЦАРЬ
class Knight : public Character
{
	/**
	* \brief Функция для получения типа персонажа
	* \return string - строку, название персонажа
	* \remark получаем только имя персонажа, тк это учебный код
	*/
public:
	string getType() override { return "Рыцарь"; }
	/**
	* \brief Функция для выполнения действий персонажа
	* \note не влияет ни на что, тк учебный код
	* \todo добавить возможность отбирать жизни у того, на кого нападаем
	*/
	void attack() override { cout << "Рыцарь атакует копьем!" << endl; }
};

/**
* \brief Абстрактная фабрика для генерации персонажей
* 
* Используется для примера работы паттерна проектирования Creational 
*/
class CharacterFactory
{
public:
	virtual Character* createCharacter() = 0;
	/**
	* \brief Функция для создания персонажей и выполнения базовых его действий
	* \note После создания объекта, выполняет действие персонажа и уничтожает объект
	* \warning Нельзя будет использовать созданных персонажей в других частях кода
	*/
	void spamAndAttack()
	{
		Character* chara = createCharacter();
		cout << "Создан " << chara->getType() << ". ";
		chara->attack();
		delete chara;
	}
};


/// \brief Класс для создания Воина
class WarriorFactory : public CharacterFactory
{
public:
	/**
	* \brief Функция для выделения памяти на класс персонажа
	* \return Возвращает указатель на созданного персонажа
	*/
	Character* createCharacter() override { return new Warrior(); }
};
class MageFactory : public CharacterFactory
{
	/**
	* \brief Функция для выделения памяти на класс персонажа
	* \return Возвращает указатель на созданного персонажа
	*/
public:
	Character* createCharacter() override { return new Mage(); }
};
class ArcherFactory : public CharacterFactory
{
	/**
	* \brief Функция для выделения памяти на класс персонажа
	* \return Возвращает указатель на созданного персонажа
	*/
public:
	Character* createCharacter() override { return new Archer(); }
};
class KnightFactory : public CharacterFactory
{
	/**
	* \brief Функция для выделения памяти на класс персонажа
	* \return Возвращает указатель на созданного персонажа
	*/
public:
	Character* createCharacter() override { return new Knight(); }
};


/// \brief Функция для запуска конвеера
/// \note Используется для учебного кода
int main()
{
	setlocale(LC_ALL, "ru");

	CharacterFactory* factory = new WarriorFactory();
	factory->spamAndAttack();

	factory = new MageFactory();
	factory->spamAndAttack();

	factory = new ArcherFactory();
	factory->spamAndAttack();

	factory = new KnightFactory();
	factory->spamAndAttack();

	delete factory;
}

