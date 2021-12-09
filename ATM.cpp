#include<iostream>
#include<conio.h>
#include<string>
#include <list>
#include <iterator>
#pragma warning(disable : 4996)
using namespace std;

list <long int> spisok;

class atm                                              
{
private: 
    long int account;                         
    string name;
    int PIN;
    long int balance;
    long int rate;

public:   
    atm()
    {

    }
    void setData(long int account_t, string name_a, int PIN_a, double balance_a, double rate_a) // Функция setData устанавливает данные в закрытые переменные-члены
    {
        account = account_t;
        name = name_a;
        PIN = PIN_a;                          
        balance = balance_a;
        rate = rate_a;
    }
    long int getAccount()
    {
        return account;
    }

    string getName()
    {
        return name;
    }

    int getPIN()
    {
        return PIN;
    }

    long int getRate()
    {
        return rate;
    }

    void setRate(int bal)
    {
        rate = bal;
    }

    long int getBalance() 
    {
        return balance;
    }

    void setBalance(int bal) 
    {
        balance = bal;
    }

};

class actionBalance : public atm {
private:
    long int Balance;
public:
    actionBalance()
    {

    }
    int cashWithDraw(int amount_a, atm a)
    {
        Balance = a.getBalance();
        if (amount_a > 0 && amount_a < Balance)           //проверяет действительность введенной суммы
        {
            Balance = Balance - amount_a;
            cout << "Пожалуйста, заберите свои наличные." << endl;
            cout << "Доступный Баланс: " << Balance << endl;
            getch();                                      //getch() удерживает экран до тех пор, пока пользователь не нажмет любую клавишу
        }
        else
        {

            cout << "Недостаточно средств.";
            getch();

        }
        spisok.push_back(Balance);
        return 0;
    }

    int getDeposit(int amount_a, atm a) {

        Balance = a.getBalance();
        if (amount_a > 0)           //проверяет действительность введенной суммы
        {
            Balance = Balance + amount_a;
            cout << "Баланс пополнен." << endl;
            cout << "Доступный баланс: " << Balance << endl;
            getch();                                      //getch() удерживает экран до тех пор, пока пользователь не нажмет любую клавишу
        }
        spisok.push_back(Balance);
        return 0;
    }
    
    long int getBalance()
    {
        return Balance;
    }
};

class actionRate : public atm {
private:
    long int Balance;
    long int Rate;
public:
    actionRate()
    {

    }
    int cashWithDraw(int amount_a, atm a)
    {
        Rate = a.getRate();
        Balance = a.getBalance();
        if (amount_a > 0 && amount_a < Rate)           //проверяет действительность введенной суммы
        {
            Rate = Rate - amount_a;
            Balance = Balance + amount_a;
            cout << "Операция выполнена." << endl;
            cout << "Доступный баланс счёта: " << Rate << endl;
            getch();                                      //getch() удерживает экран до тех пор, пока пользователь не нажмет любую клавишу
        }
        else
        {
            cout << "Недостаточно средств.";
            getch();

        }
        spisok.push_back(Rate);
        return 0;
    }

    int getDepositRate(int amount_a, atm a) {

        Rate = a.getRate();
        Balance = a.getBalance();
        if (amount_a > 0)           
        {
            Rate = Rate + amount_a;
            Balance = Balance - amount_a;
            cout << "Баланс счёта пополнен." << endl;
            cout << "Доступный баланс счёта: " << Rate << endl;
            getch();                                      //getch() удерживает экран до тех пор, пока пользователь не нажмет любую клавишу
        }
        spisok.push_back(Rate);
        return 0;
    }
    long int getRate()
    {
        return Rate;
    }

    long int getBalance()
    {
        return Balance;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    int amount = 0;
    int enterPIN;
    long int account;

    system("cls");

    atm user1;
    atm user2;
    atm user3;
    actionBalance BAL;
    actionRate R;

    user1.setData(1234567, "Irshad", 4567, 50000000, 0);

    do
    {
        system("cls");
        cout << "\n\t*****ДОБРО ПОЖАЛОВАТЬ*****" << endl;
        cout << "\n\tВведите номер аккаунта: " << endl;
        cin >> account;

        cout << "\n\tВведите пароль: " << endl;
        cin >> enterPIN;


        if (account == user1.getAccount() && enterPIN == user1.getPIN())
        {
         
            do {
                int option = 0;
                int choice = 0;
                system("cls");
                cout << "\n\tГЛАВНОЕ МЕНЮ" << endl;
                cout << "\t1. Баланс \n\t2. Сберегательный счёт \n\t3. Посмотреть детали аккаунта \n\t4. Выход." << endl;
                cin >> option;

                switch (option) {
                case 1:
                    system("cls");
                    cout << "\n\n\tБАЛАНС" << endl;
                    cout << "\t1. Проверить баланс\n\t2. Снять наличные\n\t3. Пополнить баланс\n\t4. Посмотреть список транзакций\n\t6. Выход" << endl;
                    cin >> choice;                                 

                    switch (choice)                                
                    {
                    case 1: cout << "Баланс:" << user1.getBalance() << endl;
                        getch();
                        break;                                        

                    case 2: cout << "Введите сумму: " << endl;
                        cin >> amount;
                        BAL.cashWithDraw(amount, user1);
                        user1.setBalance(user2.getBalance());
                        break;

                    case 3: cout << "Введите сумму: " << endl;
                        cin >> amount;
                        BAL.getDeposit(amount, user1);
                        user1.setBalance(user2.getBalance());
                        break;

                    case 4:
                        cout << "Список транзакций: " << endl;
                        copy(spisok.begin(), spisok.end(), ostream_iterator<long int>(cout, "\n"));
                        getch();
                        break;

                    case 5:
                        exit(1);
                        break;
                    }
                    
                    break;

                 case 2:
                       system("cls");
                       cout << "\n\n\tСБЕРЕГАТЕЛЬНЫЙ СЧЁТ" << endl;
                       cout << "\t1. Проверить баланс счёта\n\t2. Перевести на баланс\n\t3. Перевести на счёт\n\t4. Посмотреть список транзакций\n\t6. Выход" << endl;
                       cin >> choice;       

                       switch (choice)
                       {
                       case 1: cout << "Баланс счёта:" << user1.getRate() << endl;
                                getch();
                                break;

                       case 2: cout << "Введите сумму: " << endl;
                                cin >> amount;
                                R.cashWithDraw(amount, user1);
                                user1.setRate(R.getRate());
                                user1.setBalance(R.getBalance());
                                break;

                       case 3: cout << "Введите сумму: " << endl;
                                cin >> amount;
                                R.cashWithDraw(amount, user1);
                                user1.setRate(R.getRate());
                                user1.setBalance(R.getBalance());
                                break;

                       case 4:
                                cout << "Список транзакций: " << endl;
                                copy(spisok.begin(), spisok.end(), ostream_iterator<long int>(cout, "\n"));
                                getch();
                                break;

                        case 5:
                                exit(1);
                                break;
                        }

                       break;

                case  3:
                    system("cls");
                    cout << "\n\n\tАККАУНТ" << endl;
                    cout << "\t1. Детали аккаунта\n\t2. Выход" << endl;
                    cin >> choice;
                    switch (choice)
                           {  
                           case 1:
                               system("cls");
                               cout << "\n\tДЕТАЛИ АККАУНТА" << endl;
                               cout << "\n\tНомер аккаута:" << user1.getAccount() << endl;
                               cout << "\n\tИмя:" << user1.getName() << endl;                //getting and printing user detauls
                               cout << "\n\tБаланс:" << user1.getBalance() << endl;
                               cout << "\n\tСберегательный счёт:" << user1.getRate() << endl;
                               getch();
                               exit(1);
                               break;

                           case 2:
                               exit(1);
                               break;
                           }
                  
                case 4:
                {
                    exit(1);
                     break;
                }
                               
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
