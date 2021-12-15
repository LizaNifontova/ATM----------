#include<iostream>
#include<conio.h>
#include<string>
#include <list>
#include <iterator>
#include <time.h>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;
list <long int> spisok;

class ATMCard;

class ATM
{
private:
	string Location = "ул. Профессора Дедюкина, 24";
	string BranchName = "809508";
	int cash = 214748364;
public:
	ATM()
	{

	}
	string showStreet() {
		return Location;
	}
	string showNumber() {
		return BranchName;
	}
	int getCash()
	{
		return cash;
	}
	void setCash(int dep)
	{
		cash -= dep;
	}
};

class Transaction {
public:
	void Trans(int BALANCE)
	{
		spisok.push_back(BALANCE);
	}

};

class ATMCard : public ATM {
private:
	int PIN;
	long int ID;
public:
	ATMCard()
	{}
	void setPIN(int PIN)
	{
		this->PIN = PIN;
	}
	void setID(long int ID)
	{
		this->ID = ID;
	}
	long int getID()
	{
		return ID;
	}
	int getPIN()
	{
		return PIN;
	}
};

class Account : public ATMCard, public Transaction {
private:
	string Name;
	long int rate;
	ATMCard c;
	long int Balance;
public:
	Account()
	{

	}
	void setData(long int ID, string name, int PIN, double balance)
	{
		c.setID(ID);
		Name = name;
		c.setPIN(PIN);
		Balance = balance;
	}
	long int getAccount()
	{
		return c.getID();
	}

	string getName()
	{
		return Name;
	}

	int getPINcode()
	{
		return c.getPIN();
	}

	long int getBalance()
	{
		return Balance;
	}

	void setBalance(int bal)
	{
		Balance = bal;
	}

	int receiveCash(int amount)
	{
		Balance = getBalance();
		if (amount > 0 && amount < Balance && amount < getCash())           //проверяет действительность введенной суммы
		{
			Balance = Balance - amount;
			c.setCash(amount);
			cout << "Пожалуйста, заберите свои наличные." << endl;
			cout << "Доступный Баланс: " << Balance << endl;
			getch();                                      //getch() удерживает экран до тех пор, пока пользователь не нажмет любую клавишу
		}
		else if (amount > getCash())
		{
			cout << "Недостаточно средств в банкомает, попробуйте сумму менtее чем: " << getCash();
			getch();
		}
		else
		{

			cout << "Недостаточно средств.";
			getch();

		}

		Trans(Balance);

		return 0;
	}

	int putCash(int amount) {

		Balance = getBalance();
		if (amount > 0)
		{
			Balance = Balance + amount;
			setCash(amount);
			cout << "Баланс пополнен." << endl;
			cout << "Доступный баланс: " << Balance << endl;
			getch();
		}
		Trans(Balance);
		return 0;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int amount = 0;
	int enterPIN;
	long int account;
	time_t now = time(0);
	char* dt = ctime(&now);

	Account user1;
	Transaction T;
	ATM atm;
	do
	{
		system("cls");
		user1.setData(1234567, "Irshad", 4567, 50000000);

		cout << "\n\t*****ДОБРО ПОЖАЛОВАТЬ*****" << endl;

		cout << "\n\tВведите номер аккаунта: " << endl;
		cin >> account;

		cout << "\n\tВведите пароль: " << endl;
		cin >> enterPIN;

		if (account == user1.getAccount() && enterPIN == user1.getPINcode()) {
			do {
				int option = 0;
				system("cls");
				cout << "\n\tГЛАВНОЕ МЕНЮ" << endl;
				cout << "\t1. Проверить баланс. \n\t2. Снять наличные. \n\t3. Пополнить баланс. \n\t4. Посмотреть транзакции.\n\t5. Выход." << endl;
				cin >> option;

				switch (option)
				{
				case 1: cout << "Баланс:" << user1.getBalance() << endl;
					getch();
					break;

				case 2: cout << "Введите сумму: " << endl;
					cin >> amount;
					user1.receiveCash(amount);
					user1.setBalance(user1.getBalance());
					break;

				case 3: cout << "Введите сумму: " << endl;
					cin >> amount;
					user1.putCash(amount);
					user1.setBalance(user1.getBalance());
					break;

				case 4:
					cout << "Список транзакций: " << endl;
					for (int n : spisok) {
						cout << "Время: " << dt;
						cout << "Баланс: " << n << endl;
						cout << "	" << endl;
					}
					getch();
					break;

				case 5:
					exit(1);
					break;

				default: cout << "Вы ввели неверные данные." << endl;
				}
				cin.clear();
			} while (1);
		}
		else
		{
			cout << "Данные пользователя не действительны." << endl;
			getch();
		}
	} while (1);

	return 0;
}