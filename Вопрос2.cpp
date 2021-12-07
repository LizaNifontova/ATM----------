#include <fstream>
#include <iostream>
#include <string>

class DisplayScreen;

using namespace std;
string AccountType[] = { "", "Баланс", "Сберегательный счёт" };
string response;

int AccountDetails[] = {
	1234,		// PIN
	100,		// Баланс
	600,		// Счёт
};

class ATMcard {
public:
	int pin;
	ATMcard()
	{

	}
	int ATMCard(int pin){
		if (pin == AccountDetails[0]) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Choice {
public:
	string response;
	Choice()
	{

	}
	bool proceed(string response) {
		if (response == "y" || response == "Y") {
			return true;
		}
		else if (response == "n" || response == "N") {
			string exit;
			cout << "\n\n\n\t До свидания.";
			cin >> exit;
			return false;
		}

	}
};

class Account : public Choice {
private:
	int type;		// тип аккаунта
	int balance;	// баланс
public:
	Account()
	{

	}
	Account(int type) {
		// 1 - баланс
		// 2 - сбер
		this->type = type;
		this->balance = AccountDetails[this->type];
	}
	int getWithdraw() {
		int withdrawAmount;
		cout << "Введите сумму перевода:\n " << endl;
		cin >> withdrawAmount;

		// тип счёта
		if (withdrawAmount <= this->balance) {
			int AccountBalance = this->balance -= withdrawAmount;
			cout << "Пожалуйста, подождите..." << endl;
			cout << endl;
			cout << withdrawAmount << "Р" << endl;

			// обновляем баланс
			AccountDetails[this->type] = AccountBalance;
			getBalance();

		}
		else {
			cout << "Недостаточно средств" << endl;
			getBalance();
		}

		return 0;
	}

	int getDeposit() {
		int depositAmount;
		cout << "Введите сумму:\n" << endl;
		cin >> depositAmount;

		int AccountBalance = this->balance += depositAmount;

		// обновляем баланс
		AccountDetails[this->type] = AccountBalance;

		cout << "Баланс пополнен";
		getBalance();

		return 0;
	}

	int getTransfer() {
		int AmountTransfer;
		int TransferTo = this->type == 1 ? 2 : 1;

		cout << "Введите сумму для перевода " << AccountType[TransferTo] << endl;
		cin >> AmountTransfer;

		if (AmountTransfer <= AccountDetails[this->type]) {
			// обновление баланса в учётной записи
			int NewBalance = this->balance -= AmountTransfer;
			AccountDetails[this->type] = NewBalance;

			// сумма для перевода
			int TransferedAmount = AccountDetails[TransferTo] += AmountTransfer;
			AccountDetails[TransferTo] = TransferedAmount;

			cout << "Перевод выполнен" << endl;
			getBalance();

		}
		else {
			cout << "Недостаточно средств" << endl;
			getBalance();
		}

		return 0;
	}

	int getBalance() {
		string confirmBalance;
		// получаем счёт и возвращаем остаток
		cout << "Проверить баланс? " << " (y/n)\n" << endl;
		cin >> confirmBalance;
		if (confirmBalance == "y" || confirmBalance == "Y" ) {
			cout << endl;
			cout << "Баланс: " << this->balance <<" Р\n" << endl;
		}

		cout << "\n\nВы хотите продолжить? (y/n)\n";
		cin >> response;

		if (proceed(response)) {
			DisplayScreen (this -> type); // возвращение в меню
		}
		return 0;
	}

	void DisplayScreen(int option) {
		// 1 - баланс
		// 2 - сбер
		cout << "\n\n" << AccountType[option] << "--\n\t1. Проверить баланс"
			<< "\n\t2. Снять со счёта " << AccountType[option]
			<< "\n\t3. Положить на счёт " << AccountType[option]
			<< "\n\t4. Перевод "
			<< "\n\t5. Вернуться в меню" << endl;

		Account Account(option);

		int selectMenu;
		cin >> selectMenu;

		switch (selectMenu) {
		case 1:
			cout << Account.getBalance();
			break;
		case 2:
			cout << Account.getWithdraw();
			break;
		case 3:
			cout << Account.getDeposit();
			break;
		case 4:
			cout << Account.getTransfer();
			break;
		case 5:
			menu(); // возвращение в меню.
			break;
		default:
			cout << endl;
			cout << "Вы хотите продолжить? (y/n)\n";
			cin >> response;
			proceed(response);

			if (proceed(response)) {
				menu(); // возвращение в меню.
			}
			break;
		}
	}

	void menu() {
		int option;
		cout << "\n\nГлавное меню" << endl;
		cout << "\t1. Баланс \n\t2. Сберигательный счёт \n\t3. Выход" << endl;
		cin >> option;
		switch (option) {
		case 1: DisplayScreen(option); // баланс
			break;
		case 2: DisplayScreen(option); // счёт
			break;
		default:
			cout << endl;
			cout << "Вы хотите продолжить? (y/n)\n";
			cin >> response;
			response;

			if (proceed(response)) {
				menu();
			}
			break;
		}
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	ATMcard ac;
	Account m;
	cout << "Здравствуйте.\n\tПожалуйста, введите PIN: " << endl;
	do {
		cin >> ac.pin;

		if (ac.pin) {
			m.menu(); // перейти в меню
		}
		else {
			cout << "Неверный PIN.\n\tПожалуйста, введите PIN:" << endl;
		}
	} while (!ac.pin);

	return 0;
}

