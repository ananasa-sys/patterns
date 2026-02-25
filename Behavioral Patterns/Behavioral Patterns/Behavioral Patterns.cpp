#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ComputerSystem
{
public:
	void openFile(const string& file) { cout << "Открываем файл: " << file << endl; }
	void shutDown() { cout << "Выключаем компьютер: " << endl; }
	void launchBrowser() { cout << "Запускаем браузер: " << endl; }
	void restart() { cout << "Перезагружаем компьютер: " << endl; }
};

class Command
{
public:
	virtual void execute() = 0;
	virtual void undo() = 0; // отмена (опц)
};

class OpenFileCommand : public Command
{
private:
	ComputerSystem* system;
	string fileName;
public:
	OpenFileCommand(ComputerSystem* s, const string& fn) : system(s), fileName(fn) {}
	void execute() override { system->openFile(fileName); }
	void undo() override { cout << "Закрываем файл: " << fileName << endl; }
};

class ShutDownCommand : public Command
{
private:
	ComputerSystem* system;
public:
	ShutDownCommand(ComputerSystem* s) : system(s) {}
	void execute() override { system->shutDown(); }
	void undo() override { cout << "Отмена: Включаем компьютер обратно" << endl; }
};

class LaunchBrowserCommand : public Command
{
private:
	ComputerSystem* system;
public:
	LaunchBrowserCommand(ComputerSystem* s) : system(s) {}
	void execute() override { system->launchBrowser(); }
	void undo() override { cout << "Закрываем браузер" << endl; }
};

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

class RestartCommand : public Command
{
private:
	ComputerSystem* system;
public:
	RestartCommand(ComputerSystem* s) : system(s) {}
	void execute() override { system->restart(); }
	void undo() override { cout << "Отмена: Выключаем перезагрузку" << endl; }
};

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

