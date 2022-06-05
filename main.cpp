#include "Storage.h"

int Storage::count;

void menu(int* command)
{

    cout << "===============МЕНЮ===============" << endl;

    cout << "Доступные действия:" << endl;

    cout << "\t" << "1) Поиск товара по номеру секции" << endl;
    cout << "\t" << "2) Сортировать по быванию стоимости" << endl;
    cout << "\t" << "3) Поиск товара с датой больше, чем заданная" << endl;
    cout << "\t" << "4) Печать базы" << endl;
    cout << "\t" << "5) Добавить данные" << endl;
    cout << "\t" << "6) Завершение программы" << endl;

    cout << "==============================" << endl;

    cout << "Введите цифру от 1 до 6: " << endl;

    cout << "==============================" << endl << endl;

    *(command) = controlCommand();

}

int main() 
{
    setlocale(LC_ALL, "Russian");

    Storage_box element;
    Storage_box Massive;
    Date DateFor3thCase;
    int CountProductsWhatWeNeed=0;

    ReadBase(element.StorageBase, Storage::count);

    int command;

    do
    {

        menu(&command);
        switch (command)
        {

        case 1:
            SearchProductBySection(element.StorageBase, Storage::count);

            break;

        case 2:
            SortByAmountDescending(element.StorageBase, Storage::count);

            break;

        case 3:
            if (CountProductsWhatWeNeed != 0) 
            {
                delete[] Massive.StorageBase;
                Storage_box Massive;
            }
            CountProductsWhatWeNeed = 0;
            CountProductsWhatWeNeed = CountFor3thCase(element.StorageBase, DateFor3thCase, Storage::count);
            //Massive = (Storage*)realloc(StorageBase, (CountProductsWhatWeNeed + 1) * sizeof(Storage));
            /*for (int i = 0; i < CountProductsWhatWeNeed; i++)
            {
                Massive.addElement();
            }*/
            For3thCase(element.StorageBase, Massive.StorageBase, DateFor3thCase, Storage::count);

            break;

        case 4:
            PrintBase(element.StorageBase, Storage::count);

            break;

        case 5:
            element.addElement();
            SaveBase(element.StorageBase, Storage::count);

            break;

        case 6:
            SaveBase(element.StorageBase, Storage::count);

            break;

        default:
            cout << "Неверно введен номер действия";

            break;

        }

    } while (command != 6);

    return 0;
}
