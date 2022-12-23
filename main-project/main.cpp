
#include <iostream>
#include "constants.h"
#include "phone_talk.h"
#include "file_reader.h"

using namespace std;
void dateOutput(date date) {
    static const char* months[12] = { "январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" };
    std::cout << date.day << ' ' << months[date.month - 1] << ' ' << date.year << " г.";
}

void timeOutput(Time time) {
    cout.width(2);
    cout.fill('0');
    cout << time.hour << ':';
    cout.width(2);
    std::cout.fill('0');
    cout << time.minute << ':';
    cout.width(2);
    cout.fill('0');
    cout << time.second;
}

int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Лабораторная работа №9. GIT\n";
    cout << "Вариант №9. Телефонный разговор\n";
    cout << "Автор: Арина Панизник\n\n";
    phone_talk* talks[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", talks, size);
        for (int i = 0; i < size; i++)
        {
            cout << talks[i]->number << '\n';
            dateOutput(talks[i]->date);
            cout << '\n';
            cout << "Время звонка: ";
            timeOutput(talks[i]->time);
            cout << '\n';
            cout << "Продолжительность звонка: ";
            timeOutput(talks[i]->duration);
            cout << '\n';
            cout << talks[i]->rate << '\n';
            cout << "Стоимоть: " << talks[i]->cost << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete talks[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}