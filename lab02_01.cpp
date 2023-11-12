/********************************************************************
*              КАФЕДРА № 304 1 КУРС ИНФОРМАЦИОННЫЕ ТЕХНОЛОГИИ       *
*-------------------------------------------------------------------*
* Project Type  : Win32 Console Application                         *
* Project Name  : ЛАБОРАТОРНАЯ 2                                    *
* File Name     : lab02_01.cpp                                      *
* Programmer(s) : Андреев Максим, Пиманова Ольга                    *
* Modifyed By   :                                                   *
* Created       : 05/11/23                                          *
* Last Revision : 12/11/23                                          *
* Comment(s)    : Табулирование функций                             *
*                                                                   *
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

/*********************************************************************
*               О С Н О В Н А Я       П Р О Г Р А М М А              *
*********************************************************************/

int main()  //начало программы
{
    setlocale(LC_ALL, "RUSSIAN");   //подключение русского языка
    cout<<"Введите значения начала и конца отрезка (A и B): ";
    float A, B;    //инициализация переменных начала и конца отрезка
    cin>>A>>B;  //ввод начала и конца отрезка
    if (A > B)  //проверка корректности входных данных
    {
        cout<<"Ошибка входных данных (A>B)";
        return -1;  //выход из программы
    }
    int N;  //инициализация переменной количества интервалов
    
    cout.precision(4);  //установка фиксированной точности вывода дробных чисел
    float x, F, G;  //инициализация переменных аргумента и значений функций F(x) и G(x)
    if (A != B)     //проверка несовпадения начала и конца отрезка
    {
        //Если начало и конец отрезка не совпадают
        cout<<"Введите количесво интервалов (N): ";
        cin>>N;   //ввод количества интревалов
        if (N <= 0)    //проверка корректности входных данных
        {
            cout<<"Ошибка входных данных (N<=0)";
            return -1;  //выход из программы
        }
    }
    else
    {
        //Если начало и конец отрезка совпадают
        cout<<"______________________________________________________\n";     //печать шапки таблицы
        cout<<"i\t|\tx\t|\tF(x)\t|\tG(x)\n";   
        cout<<"______________________________________________________\n";
        x = A;  //значение аргумента равно началу(концу) отрезка
        F = sqrt((x*x + 4));    //вычисление функции F(x)
        G = powf(x+5, 3) / (1 + sin(x)*sin(x));  //вычисление функции G(x)
        cout<<"0\t|\t"<<x<<"\t|\t"<<F<<"\t|\t"<<G<<endl;   //печать результата
        cout<<"______________________________________________________\n";
        return 0;   //выход из программы
    }

    /* ЧАСТЬ, ВЫПОЛНЯЮЩАЯСЯ ТОЛЬКО КОГДА НАЧАЛО И КОНЕЦ ОТРЕЗКА НЕ СОВПАДАЮТ */
    cout<<"______________________________________________________\n";     //печать шапки таблицы
    cout<<"i\t|\tx\t|\tF(x)\t|\tG(x)\n";
    cout<<"______________________________________________________\n";
    float h = (B-A)/N;  //инициализация переменной шага
    for (int i=0;i<N+1;i++)
    {
        x = A + i*h;    //вычисления аргумента функций в следующей точке
        F = sqrt((x*x + 4));    //вычисление функции F(x)
        G = powf(x+5, 3) / (1 + sin(x)*sin(x));     //вычисление функции G(x)
        cout<<i<<"\t|\t"<<x<<"\t|\t"<<F<<"\t|\t"<<G<<endl;     //печать результата
        cout<<"______________________________________________________\n";
    }
    return 0;   //выход из программы
}   //конец программы
/**************** End of lab02_01.cpp file *****************************/