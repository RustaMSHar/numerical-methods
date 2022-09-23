#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

double get_f(double x)
{
	return pow(x, 4) + -18 * x * x + 6;
}

double bisection(double a, double b, double e) //бисекция
{
    double x;
    while (b - a > 2 * e)
    {
        double c = (a + b) / 2;
        if (get_f(a) * get_f(c) <= 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    x = (a + b) / 2;
    return x ;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Задание 1. Отделение корней и нахождение решения с помощью метода Бисекции\n";
    cout << "Функция x^4-18x^2+6 ; e = 0.001\n"; 
    double x0 , xn , f, h, N = 100, y1, y2, x, count = 0, a, b, e = 0.001; 
   //можно сделать так, чтобы точность была входным параметром, а не задаваемым программно
    vector<pair<double, double>> interval;

    cout << "Введите границы отрезка:\n"; 
    cout << "x_0 = "; cin >> x0; cout << "x_n = "; cin >> xn;
    //границы отрезка можно не задавать так, а назначить программно, так как корни лежат в интервал от -5 до 5. 
    //Но так типа понтовее
    //Также N (кол-во разбиений отрезка) также можно задавать пользователем, а не программно
    //Это N нужно, чтобы понять на каких именно отрезка есть корни
    h = (xn - x0) / N;
    y1 = get_f(x0);
    //отделение корней на отрезке
    while (x0 <= xn)
    {
        x = x0 + h;
        y2 = get_f(x);
        if (y1 * y2 <= 0)
        {
            interval.push_back(pair<double, double>(x0, x));
            count++;
        }
        x0 = x;
        y1 = y2;
    }
    cout << "Отрезки перемены знака: ";
    for (int i = 0; i < interval.size(); ++i)
    {
        cout << "[" << interval[i].first << ";"
            << interval[i].second << "]" << " ; ";
    }
    cout << "\nКоличество отрезков, содержищих корень = " << count << "\n\n";

    //Находим приближённые значения методом бисекции
    for (int i = 0; i < interval.size(); ++i)
    {
        cout<<"x_"<<i+1<<" = "<<bisection(interval[i].first, interval[i].second, e)<<"\n";
    }
    return(0);
}

