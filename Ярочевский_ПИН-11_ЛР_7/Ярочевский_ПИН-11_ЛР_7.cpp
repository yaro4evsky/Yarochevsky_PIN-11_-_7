#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct date {
    int Number;
    char* Month;
    int Year;
    int Deadline;
};

struct fio {
    char* Name;
    char* Surname;
};

struct artical {
    char* NameJournal;
    int NumberJournal;
    date date;
    fio fio;
};

void Search(artical* articals, int ValueJournals)
{
    
    for (int i = 0; i < ValueJournals; i++)
    {
        int NumberMonth;
        for (int j = 0; j < 12; j++)
        {
            if (articals[i].date.Month[0] == 'J' && articals[i].date.Month[1] == 'a' && articals[i].date.Month[2] == 'n' && articals[i].date.Month[3] == 'u')
            {
                NumberMonth = 1;
            }
            else if (articals[i].date.Month[0] == 'F' && articals[i].date.Month[1] == 'e')
            {
                NumberMonth = 2;
            }
            else if (articals[i].date.Month[0] == 'M' && articals[i].date.Month[1] == 'a' && articals[i].date.Month[2] == 'r')
            {
                NumberMonth = 3;
            }
            else if (articals[i].date.Month[0] == 'A' && articals[i].date.Month[1] == 'p')
            {
                NumberMonth = 4;
            }
            else if (articals[i].date.Month[0] == 'M' && articals[i].date.Month[1] == 'a' && articals[i].date.Month[2] == 'y')
            {
                NumberMonth = 5;
            }
            else if (articals[i].date.Month[0] == 'J' && articals[i].date.Month[1] == 'u' && articals[i].date.Month[2] == 'n')
            {
                NumberMonth = 6;
            }
            else if (articals[i].date.Month[0] == 'J' && articals[i].date.Month[1] == 'u' && articals[i].date.Month[2] == 'l')
            {
                NumberMonth = 7;
            }
            else if (articals[i].date.Month[0] == 'A' && articals[i].date.Month[1] == 'u')
            {
                NumberMonth = 8;
            }
            else if (articals[i].date.Month[0] == 'S' && articals[i].date.Month[1] == 'e')
            {
                NumberMonth = 9;
            }
            else if (articals[i].date.Month[0] == 'O' && articals[i].date.Month[1] == 'c')
            {
                NumberMonth = 10;
            }
            else if (articals[i].date.Month[0] == 'N' && articals[i].date.Month[1] == 'o')
            {
                NumberMonth = 11;
            }
            else if (articals[i].date.Month[0] == 'D' && articals[i].date.Month[1] == 'e')
            {
                NumberMonth = 12;
            }
            else {
                NumberMonth = 0;
            }
            
        }
        if (NumberMonth != 0 && (24252 - (articals[i].date.Deadline + articals[i].date.Year*12 + NumberMonth)) < 0  )
        {

            cout << endl << "Не сдан журнал с названием и номером :" << endl;
            cout << "Название журнала - " << articals[i].NameJournal << endl;
            cout << "Номер журнала - " << articals[i].NumberJournal << endl << endl;
        }
        else {
            cout <<endl<< "Введен неверный месяц, либо должников нет!" << endl<<endl;
        }
    }
}
void Info(artical* articals, int n)
{
    ifstream io;
    string str;
    io.open("File.txt");
    while(!io.eof())
    {
        str = "";
        cout << endl << "Название журнала - ";
        getline(io, str);
        cout << str << endl;
        str = "";
        cout << "Номер журнала - ";
        getline(io, str);
        cout << str << endl;
        str = "";
        cout << "Дата взятия журнала" ;
        cout << "Число - ";
        getline(io, str);
        cout << str << endl;
        str = "";
        cout << "Месяц - ";
        getline(io, str);
        cout << str << endl;
        str = "";
        cout << "Год - ";
        getline(io, str);
        cout << str << endl;
        str = "";
        cout << "Фамилия автора журнала - ";
        getline(io, str);
        cout << str << endl;
        str = "";
        cout << "Имя автора журнала - ";
        getline(io, str);
        cout << str << endl;
        str = "";
        cout << "Срок - ";
        getline(io, str);
        cout << str << endl;
        str = "";
        io.close();
    }
    for (int i = n - 1; i < n; i++)
    {
        cout << endl << "Название журнала - " << articals[i].NameJournal << endl;
        cout << "Номер журнала - " << articals[i].NumberJournal << endl;
        cout << "Дата взятия журнала"<< endl;
        cout << "Число - " << articals[i].date.Number << endl;
        cout << "Месяц - "<< articals[i].date.Month << endl;
        cout << "Год - " << articals[i].date .Year << endl;
        cout << "Фамилия автора журнала - " << articals[i].fio.Surname << endl;
        cout << "Имя автора журнала - " << articals[i].fio.Name<< endl;
        cout << "Срок - " << articals[i].date.Deadline << " месяц(ев)" << endl << endl;
        
    }
}

void CreateJournal(artical* articals, int n)
{
    ofstream fs;
    string file = "File.txt";
    fs.open(file);
    for (int i = n - 1; i < n; i++)
    {
        articals[i].date.Month = new char();
        articals[i].NameJournal = new char();
        articals[i].NumberJournal = n;
        articals[i].fio.Surname = new char();
        articals[i].fio.Name = new char();

        cout << "Введите название журнала" << endl;
        cin >> articals[i].NameJournal;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].NameJournal;
        }
        fs << articals[i].NameJournal << "\n";;
        cout << "Введите дату взятия журнала " << endl;
        cout << "Число" << endl;
        cin >> articals[i].date.Number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].date.Number;
        }
        fs << articals[i].date.Number << "\n";
        while (true)
        {
            if (articals[i].date.Number > 31 || articals[i].date.Number < 1)
            {
                cout <<endl<< "Введите число из диапазона 1 - 31  " << endl;
                cin >> articals[i].date.Number;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка, повторите ввод -  ";
                    cin >> articals[i].date.Number;
                }
            }
            else
            {
                break;
            }
        }
        cout << "Месяц (January, February,March,April,May,June,Jule,August,September, October,November,December)" << endl;
        cin >> articals[i].date.Month;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].date.Month;
        }
        fs << articals[i].date.Month << "\n";
        cout << "Год" << endl;
        cin >> articals[i].date.Year;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].date.Year;
        }
        fs << articals[i].date.Year << "\n";;
        cout << "Введите фамилию автора журнала "  << endl;
        cin >> articals[i].fio.Surname;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].fio.Surname;
        }
        fs << articals[i].fio.Surname << "\n";;
        cout << "Введите имя автора журнала" << endl;
        cin >> articals[i].fio.Name;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].fio.Name;
        }
        fs << articals[i].fio.Name << "\n";;
        cout << "Введите срок, на который берется журнал" << endl;
        cin >> articals[i].date.Deadline;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, повторите ввод -  ";
            cin >> articals[i].date.Deadline;
        }
        fs << articals[i].date.Deadline << "\n";
        fs.close();
    }
}

int main()
{
        setlocale(LC_ALL, "Russian");
        artical* articals = new artical();
        int ValueJournals = 0;
        bool f = true;
        bool m = true;
        while (m)
        {
            int menu;
            cout << "Выберите пункт" << endl;
            cout << "Добавить журнал, нажмите - 1" << endl;
            cout << "Распечатать информацию о журналах, нажмите 2" << endl;
            cout << "Найти жуналы заданного автора, нажмите 3" << endl;
            cout << "Вывести список должников, нажмите 4" << endl;
            cout << "Выход из программы, нажмите 5"<< endl;
            cin >> menu;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка, повторите ввод -  ";
                cin >> menu;
            }

            while ((menu != 1 && f == true) && (menu != 5 && f == true))
            {
                    cout << "Сначала нужно добавить журнал, повторите ввод!" << endl;
                    cin >> menu;
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ошибка, повторите ввод -  ";
                        cin >> menu;
                    }
                    if (menu == 1 || menu == 5)
                    {
                        f = false;
                    }
            }

            switch (menu)
            {
            case 1:
            {
                int Num;
                cout << "Введите номер, под который добавить журнал (Вводить по порядку, начиная с 1)" << endl;
                cin >> Num;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка, повторите ввод -  ";
                    cin >> Num;
                }
                CreateJournal(articals, Num);
                ValueJournals++;
                break;
            }
            case 2:
            {
                int n;
                cout << "Введите номер журнала, который нужно вывести" << endl;
                cin >> n;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка, повторите ввод -  ";
                    cin >> n;
                }
                Info(articals, n);
                break;
            }
            case 3:
            {
                int av;
                cout << "Список авторов" << endl;
                for (int i = 0; i < ValueJournals; i++)
                {
                    cout << i + 1 << ". - " << articals[i].fio.Surname << articals[i].fio.Name << endl;
                }
                cout << "Выберите автора, введите номер из списка" << endl;
                cin >> av;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка, повторите ввод -  ";
                    cin >> av;
                }
                cout << "Название журнала - " << articals[av - 1].NameJournal << endl;
                cout << "Номер журнала - " << articals[av - 1].NumberJournal << endl;
                cout << "Дата взятия журнала" << endl;
                cout << "Число - " << articals[av - 1].date.Number << endl;
                cout << "Месяц - " << articals[av - 1].date.Month << endl;
                cout << "Год - " << articals[av - 1].date.Year << endl;
                cout << "Срок - " << articals[av - 1].date.Deadline << endl << endl;
                break;
            }
            case 4:
            {
                Search(articals, ValueJournals);
            }
            case 5:
            {
                m = false;
            }
            }
        }
}