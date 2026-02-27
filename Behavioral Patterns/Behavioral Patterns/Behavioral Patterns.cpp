#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// \brief Класс, представляющий компьютерную систему
/// \note Содержит действия, которые могут быть выполнены над системой
class ComputerSystem
{
public:
	/**
	* \brief Функция для открытия файла и строка с именем файла для открытия
	* \note не влияет ни на что, тк учебный код
	* \todo добавить проверку существования файла
	*/
	void openFile(const string& file) { cout << "Открываем файл: " << file << endl; }
	/**
	* \brief Функция для выключения компьютера
	* \note не влияет ни на что, тк учебный код
	*/
	void shutDown() { cout << "Выключаем компьютер: " << endl; }
	/**
	* \brief Функция для запуска браузера
	* \note не влияет ни на что, тк учебный код
	*/
	void launchBrowser() { cout << "Запускаем браузер: " << endl; }
	/**
	* \brief Функция для перезагрузки компьютера
	* \note не влияет ни на что, тк учебный код
	*/
	void restart() { cout << "Перезагружаем компьютер: " << endl; }
};

/**
* \brief Базовый интерфейс для всех команд
* Используется для примера работы паттерна проектирования Command
*/
class Command
{
public:
	virtual void execute() = 0;
	virtual void undo() = 0; // отмена (опц)
};

/// \brief Класс команды для открытия файла
class OpenFileCommand : public Command
{
private:
	ComputerSystem* system;
	string fileName;
	/**
	* \brief Конструктор команды открытия файла
	*/
public:
	OpenFileCommand(ComputerSystem* s, const string& fn) : system(s), fileName(fn) {}
	/**
	* \brief Выполнение команды открытия и закрытия файла
	*/
	void execute() override { system->openFile(fileName); }
	/**
	* \brief Отмена команды открытия файла
	*/
	void undo() override { cout << "Закрываем файл: " << fileName << endl; }
};

/// \brief Класс команды для выключения компьютера
class ShutDownCommand : public Command
{
private:
	ComputerSystem* system;
public:
	/**
	* \brief Конструктор команды выключения
	*/
	ShutDownCommand(ComputerSystem* s) : system(s) {}
	/**
	* \brief Выполнение команды выключения
	*/
	void execute() override { system->shutDown(); }
	/**
	* \brief Отмена команды выключения
	*/
	void undo() override { cout << "Отмена: Включаем компьютер обратно" << endl; }
};

/// \brief Класс команды для запуска браузера
class LaunchBrowserCommand : public Command
{
private:
	ComputerSystem* system;
public:
	/**
	* \brief Конструктор команды запуска браузера
	*/
	LaunchBrowserCommand(ComputerSystem* s) : system(s) {}
	/**
	* \brief Выполнение команды запуска браузера
	*/
	void execute() override { system->launchBrowser(); }
	/**
	* \brief Отмена команды запуска браузера
	*/
	void undo() override { cout << "Закрываем браузер" << endl; }
};

/**
* \brief Класс пульта управления
*  Хранит и выполняет команды
*/
class RemoteControl
{
private:
	vector<Command*> commands;
public:

	void addCommand(Command* cmd) { commands.push_back(cmd); }
	void pressButton()
	{
		for (auto cmd : commands)
			cmd->execute();
	}
	void undoLast()
	{
		if (!commands.empty())
		{
			commands.back()->undo();
			commands.pop_back();
		}
	}
};

/// \brief Класс команды для перезагрузки компьютера
class RestartCommand : public Command
{
private:
	ComputerSystem* system;
public:
	/**
	* \brief Конструктор команды перезагрузки
	*/
	RestartCommand(ComputerSystem* s) : system(s) {}
	/**
	* \brief Выполнение команды перезагрузки
	*/
	void execute() override { system->restart(); }
	/**
	* \brief Отмена команды перезагрузки
	*/
	void undo() override { cout << "Отмена: Выключаем перезагрузку" << endl; }
};

/// \brief Функция для запуска конвеера
/// \note Используется для учебного кода
int main()
{
	setlocale(LC_ALL, "ru");

	ComputerSystem system;

	Command* openCmd = new OpenFileCommand(&system, "document.txt");
	Command* shutdownCmd = new ShutDownCommand(&system);
	Command* browserCmd = new LaunchBrowserCommand(&system);
	Command* restartCmd = new RestartCommand(&system);

	RemoteControl remote;
	remote.addCommand(openCmd);
	remote.addCommand(browserCmd);
	remote.addCommand(shutdownCmd);
	remote.addCommand(restartCmd);

	remote.pressButton();

	remote.undoLast();

	delete openCmd;
	delete shutdownCmd;
	delete browserCmd;
	delete restartCmd;
}

