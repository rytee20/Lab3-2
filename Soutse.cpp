#include "Storage.h"

//DATE

Date::Date()
{
    day = 0;
    mounth = 0;
    year = 0;
}

Date& Date::operator=(const Date& equal)
{
    /*if (this == &equal)
        return *this;*/

    day=equal.day;
    mounth=equal.mounth;
    year=equal.year;
    return *this;
    //this->SetDay(equal.GetDay());
    //this->SetMounth(equal.GetMounth());
    //this->SetYear(equal.GetYear());
}


//STORAGE

char* Storage::GetName() { return name; }
double Storage::GetCost() { return cost; }
int Storage::GetAmount() { return amount; }
int Storage::GetSectionnumber() { return sectionnumber; }

void Storage::SetName(char* new_name)
{
    name = new char[50];
    strcpy(name, new_name);
};
void Storage::SetCost(double new_cost) {
    cost = new_cost;
}
void Storage::SetAmount(int new_amount) {
    amount = new_amount;
}
void Storage::SetSectionnumber(int new_sectionnumber) {
    sectionnumber = new_sectionnumber;
}

Storage::Storage()
{
    name = new char[5];
    strcpy(name, "mane");
    cost = 0.0;
    amount = 0;
    sectionnumber = 0;
    count++;
}

Storage& Storage::operator=(const Storage& equal)
{
    /*if (this == &equal)
        return *this;*/
    name=equal.name;
    cost = equal.cost;
    amount = equal.amount;
    sectionnumber = equal.sectionnumber;
    arriveddate = equal.arriveddate;
    return *this;
}

bool operator>(Storage& Obj, Date& fdate)
{
    if ((fdate.year<Obj.arriveddate.year) || (fdate.year == Obj.arriveddate.year && fdate.mounth < Obj.arriveddate.mounth)||(fdate.year == Obj.arriveddate.year && fdate.mounth == Obj.arriveddate.mounth && fdate.day < Obj.arriveddate.day))
        return 1;
    else
        return 0;
}


//BOX

Storage_box::Storage_box()
{
    StorageBase = new Storage[0];
}

void Storage_box::addElement() {
    Storage* tmp;
    tmp = (Storage*)realloc(StorageBase, (Storage::count + 1) * sizeof(Storage));
    if (tmp != nullptr) {
        StorageBase = tmp;
        СreateBase(StorageBase, Storage::count);
        Storage::count++;
        cout << "Памят выделена" << endl;
    }
    else {
        cout << "Не получилос" << endl;
    }
}

Storage_box::~Storage_box() {
    delete[] StorageBase;
    cout << "Почистилос" << endl;
}


//CONTROLS

int controlCommand()
{

    while (true) {

        int checkcommand;
        cin >> checkcommand;

        if (cin.fail() or (checkcommand <= 0) or (checkcommand > 6))
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
        {
            return checkcommand;
            cin.clear();
            cin.ignore(32767, '\n');
        }

    }

}

double ControlCost() //КОНТРОЛЬ ЦЕНЫ
{

    cout << "Введите цену товара (если число - десятичная дробь, следует отделить дробную часть точкой): ";

    while (true)
    {
        double checkcost;
        cin >> checkcost;

        if (cin.fail() or (checkcost <= 0.0))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка ввода" << endl;
        }
        else
        { 
            return checkcost;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}

char* ControlName() //КОНТОРЛЬ ЧАР
{
    int i;
    int count = 0;
    char* str;
    str = new char[50];

    do
    {
        cin >> str;

        for (i = 0; str[i]; i++) count++;

        for (i = 0; str[i]; i++)
            if ((str[i] >= '0' and str[i] <= '9' and str[i]) or (str[i] <= '/' and str[i] >= '!') or (str[i] <= '@' and str[i] >= ':') or (str[i] <= '`' and str[i] >= '[') or (str[i] <= '~' and str[i] >= '{'))
                break;

        if (str[i])
            cout << "Введены не буквы(" << endl << "Повторите ввод" << endl;

    } while (str[i]);
    
    char* Obj = new char[strlen(str) + 1];
    strcpy(Obj, str);

    return Obj;
    cin.clear();
    cin.ignore(32767, '\n');
}

int ControlAmountAndSection()
{
    while (true) { // цикл продолжается до тех пор, пока пользователь не введет корректное значение

        int check;
        cin >> check;

        if (cin.fail() or (check <= 0)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Ошибка ввода" << endl;
        }
        else // если всё хорошо, то возвращаем checkind
        {
            return check;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}

int ControlYear()
{
    while (true) { // цикл продолжается до тех пор, пока пользователь не введет корректное значение

        int check;
        cin >> check;
        cin.clear();
        cin.ignore(32767, '\n');

        if (cin.fail() or (check <= 1954) or (check >= 2023)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Введены либо не цифры, либо вы путешественник во времени" << endl;
        }
        else // если всё хорошо, то возвращаем checkind
        {
            return check;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}

int ControlMounth()
{
    while (true) { // цикл продолжается до тех пор, пока пользователь не введет корректное значение

        int check;
        cin >> check;

        if (cin.fail() or (check <= 0) or (check >= 13)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Ну надо циферками ввести (месяцев 12 если что)" << endl;
        }
        else // если всё хорошо, то возвращаем checkind
        {
            return check;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}

int ControlDay(int fyear, int fmounth)
{
    while (true) { // цикл продолжается до тех пор, пока пользователь не введет корректное значение

        int check;
        cin >> check;

        if (cin.fail() or (check <= 0) or (fyear%4==0 and fmounth==2 and check>=30) or (fyear % 4 != 0 and fmounth == 2 and check>=29) or ((fmounth==1 or fmounth == 3 or fmounth == 5 or fmounth == 7 or fmounth == 8 or fmounth == 10 or fmounth == 12) and check>=32) or (check>=31 and (fmounth == 4 or fmounth == 6 or fmounth == 9 or fmounth == 11))) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            if (fmounth == 2) cout << "Вы накосячили с февралем" << endl;
            else cout << "Ну что-то не то, откройте календарь" << endl;
        }
        else // если всё хорошо, то возвращаем checkind
        {
            return check;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
}


//WORK_WITH_BASE

void PrintBase(Storage* Obj, int fcount)
{
    cout << "Содержимое файла:" << endl << "НАЗВАНИЕ  ДАТА  ЦЕНА  КОЛИЧЕСТВО  СЕКЦИЯ" << endl;
    for (int fnumber = 0; fnumber < fcount; fnumber++)
    {
        cout << Obj[fnumber].GetName() << " " << Obj[fnumber].arriveddate.day << "." << Obj[fnumber].arriveddate.mounth << "." << Obj[fnumber].arriveddate.year << " " << Obj[fnumber].GetCost() << " " << Obj[fnumber].GetAmount() << " " << Obj[fnumber].GetSectionnumber()<< endl;
    }
}

void SaveBase(Storage* Obj, int fcount) //СОХРАНИТЬ БАЗУ В ФАЙЛ
{
    ofstream record("Base.txt", ios::out);

    if (record)
    {
        for (int i = 0; i < fcount - 1; i++)
        {
            record << Obj[i].GetName() << " " << Obj[i].arriveddate.day << " " << Obj[i].arriveddate.mounth << " " << Obj[i].arriveddate.year << " " << Obj[i].GetCost() << " " << Obj[i].GetAmount() << " " << Obj[i].GetSectionnumber() << endl;

        }
        record << Obj[fcount-1].GetName() << " " << Obj[fcount - 1].arriveddate.day << " " << Obj[fcount - 1].arriveddate.mounth << " " << Obj[fcount - 1].arriveddate.year << " " << Obj[fcount - 1].GetCost() << " " << Obj[fcount - 1].GetAmount() << " " << Obj[fcount - 1].GetSectionnumber();
    }
    else
    {
        cout << "ОШИБКА ЗАПИСИ ДАННЫХ НА ДИСК" << endl;
    }
    record.close();
}

void СreateBase(Storage* Obj, int fcount) //СОЗДАТЬ БАЗУ
{
    cout << "Введите название таовара (если в названии несколько слов, пишите слитно, каждое слово с большой буквы): ";
    Obj[fcount].name=ControlName();
    Obj[fcount].cost=ControlCost();
    cout << "Введите количество товара: ";
    Obj[fcount].amount=ControlAmountAndSection();
    cout << "Введите секцию товара: ";
    Obj[fcount].sectionnumber=ControlAmountAndSection();
    cout << "Введите год поступления товара: ";
    Obj[fcount].arriveddate.year=ControlYear();
    cout << "Введите месяц поступления товара: ";
    Obj[fcount].arriveddate.mounth=ControlMounth();
    cout << "Введите день поступления товара: ";
    Obj[fcount].arriveddate.day=ControlDay(Obj[fcount].arriveddate.year, Obj[fcount].arriveddate.mounth);
    cout << endl;
}

void ReadBase(Storage*& Obj, int fcount) //СЧИТАТЬ БАЗУ С ФАЙЛА
{

    ifstream fin;
    int count1 = 0;
    fin.open("Base.txt");
    char* str = new char[1024];
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin.getline(str, 1024, '\n');
            count1++;
            if (str[0] == EOF)
            {
                count1 = 0;
                break;
            }
        }
        delete[] str;

        if (count1 == 0) cout << "Файл пуст" << endl;
        else
        {
            fcount = count1;
            cout << "Считано " << fcount << " объектов из файла\n";

            Obj = new Storage[fcount];
            fin.close();
            fin.open("Base.txt");

            char* fname=new char[50];
            int fday;
            int fmounth;
            int fyear;
            double fcost;
            int famount;
            int fsectionnumber;

            for (int i = 0; i < fcount; i++) {
                fin >> fname >> fday >> fmounth >> fyear >> fcost >> famount >> fsectionnumber;
                strcpy(Obj[i].name,fname);
                Obj[i].arriveddate.day=fday;
                Obj[i].arriveddate.mounth=fmounth;
                Obj[i].arriveddate.year=fyear;
                Obj[i].cost=fcost;
                Obj[i].amount=famount;
                Obj[i].sectionnumber=fsectionnumber;
                cout << Obj[i].name << " ";
            }
        }
        Storage::count = fcount;
    }
    fin.close();
}


//FUNCTIONS

void SearchProductBySection(Storage* Obj, int fcount)
{
    int fsection;
    int count1 = 0;
    cout << "Введите номер секции: " << endl;
    fsection = ControlAmountAndSection();
    int fnumber = 0;

    cout << "Товары в заданной секции: " << endl << "НАЗВАНИЕ  ДАТА  ЦЕНА  КОЛИЧЕСТВО  СЕКЦИЯ" << endl;

    while (fnumber < fcount)
    {
        if (Obj[fnumber].GetSectionnumber() == fsection)
        {
            count1++;
            cout << Obj[fnumber].GetName() << " " << Obj[fnumber].arriveddate.day << "." << Obj[fnumber].arriveddate.mounth << "." << Obj[fnumber].arriveddate.year << " " << Obj[fnumber].GetCost() << " " << Obj[fnumber].GetAmount() << " " << Obj[fnumber].GetSectionnumber() << endl;
        }
        fnumber++;
    }

    if (count1 == 0) cout << "Не найдено товаров в заданной секции" << endl;
}

void SortByAmountDescending(Storage* Obj, int fcount) //СОРТИРОВКА
{


    for (int j = 0; j < fcount - 1; j++)
    {

        for (int l = j + 1; l < fcount; l++)

            if (Obj[j].GetCost() < Obj[l].GetCost())
            {

                swap(Obj[j], Obj[l]);

            }

    }
    cout << "Отсортировано" << endl;
}

int CountFor3thCase(Storage* Obj1, Date& fdate, int fcount)
{
    cout << "Итак введите дату, и все товаты поступившие после будут выведены на экран и сложены в массив" << endl << "Введите год: ";
    fdate.year = ControlYear();
    cout << "Введите месяц: ";
    fdate.mounth = ControlMounth();
    cout << "Введите день: ";
    fdate.day = ControlDay(fdate.year, fdate.mounth);
    int fCountProductsWhatWeNeed = 0;
    for (int i = 0; i < fcount; i++)
    {
        if (Obj1[i] > fdate)
        {
            fCountProductsWhatWeNeed++;
        }
    }
    return fCountProductsWhatWeNeed;
}

void For3thCase(Storage* Obj1, Storage*& Obj2, Date& fdate, int fcount)
{
    int fCountAgain = 0;
    for (int i = 0; i < fcount; i++)
    {
        if (Obj1[i] > fdate)
        {
            //Massive = (Storage*)realloc(StorageBase, (CountProductsWhatWeNeed + 1) * sizeof(Storage));
            Obj2[fCountAgain] = Obj1[i];
            cout << Obj2[fCountAgain].GetName() << " " << Obj2[fCountAgain].arriveddate.day << "." << Obj2[fCountAgain].arriveddate.mounth << "." << Obj2[fCountAgain].arriveddate.year << " " << Obj2[fCountAgain].GetCost() << " " << Obj2[fCountAgain].GetAmount() << " " << Obj2[fCountAgain].GetSectionnumber() << endl;
            fCountAgain++;
        }
    }
}
