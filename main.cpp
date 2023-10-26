#include "main.h"

Graph::Graph(int N, int m0, int m, int Q) //Q - предел суммы висячих
{
    srand(time(NULL));
    m -= 1;

    int level = 1, count = 1;
    int countQ = 0, sum = 0, child_index = 0;


    int ind = 1;

    int index = m0 + rand() % (m - m0 + 1);

    all_ver.resize(MAX_HEIGHT);
    empty_ver.resize(MAX_HEIGHT);
    without_empty_ver.resize(MAX_HEIGHT);

    if(index > 0)
        all_ver[0].emplace_back(0, index);
    else
    {
        std::cout << "First index is null" << std::endl;
        return;
    }
    next:
    while((countQ < Q) && ((count + index) < N))
    {
        child_index = index + 1;
        for ( ; ind < index + 1; ind++)
        {
            sum = m0 + rand() % (m - m0 + 1);
            if(level < 2)
                all_ver[level].emplace_back(ind, sum);
            else
            {
                for(auto & j : all_ver[level])
                {
                    if(j.first == ind)
                    {
                        j.second = sum;
                        break;
                    }
                }
            }
            countQ += ind;
            for (int i = child_index; i < (child_index + sum); i++)
            {
                countQ += i;
                if (countQ > Q) {
                    std::cout << " > Q" << std::endl;
                    goto next;
                }
                all_ver[level + 1].emplace_back(i, 0);
            }
            child_index += sum;
        }
        if((child_index - ind) >= 1)
        {
            count += child_index - 1;
            index = child_index - 1;
            tree_height = ++level;
        }
        else
            goto exit;
    }
    exit:
    create_tables();
    write_in_file();
    all_ver.clear();
    empty_ver.clear();
    without_empty_ver.clear();
}

void Graph::print(std::vector<std::vector<std::pair<int, int>>> vec)
{
    for(int i = 0; i < all_ver.size() / 20; i++)
    {
        for (int j = 0; j < all_ver[i].size() / 20; j++)
        {
            std::cout << "i: " << i << ", j: " << j << ", first: " << vec[i][j].first << ", second: " << vec[i][j].second << std::endl;
        }
    }
}


void Graph::create_tables()
{
    for(int i = 0; i < all_ver.size(); i++)
    {
        for(int j = 0; j < all_ver[i].size(); j++)
        {
            if(all_ver[i][j].second == 0)
            {
                empty_ver[i].emplace_back(all_ver[i][j].first, all_ver[i][j].second);
                empty_count++;
            }
            else
            {
                without_empty_ver[i].emplace_back(all_ver[i][j].first, all_ver[i][j].second);
                without_empty_count++;
            }
        }
    }
}

void Graph::write_in_file()
{
    std::fstream file_1;
    std::fstream file_2;
    std::fstream file_3;
    file_1.open("/Users/vladimirskobcov/Desktop/SoftWare/all_ver.txt", std::ios::app);
    file_2.open("/Users/vladimirskobcov/Desktop/SoftWare/empty_ver.txt",  std::ios::app);
    file_3.open("/Users/vladimirskobcov/Desktop/SoftWare/without_empty_ver.txt", std::ios::app);

    if(!file_1)
    {
        std::cout << "error!";
        exit(1);
    }

    for(const auto & i : all_ver)
    {
        for(const auto & j : i)
        {
            file_1 << (j.first);
            file_1 << " ";
            file_1 << (j.second);
            file_1 << " ";
        }
        file_1 << "\n";
    }

    if(!file_2)
    {
        std::cout << "error!";
        exit(1);
    }

    for(const auto & i : empty_ver) {
        for (const auto &j: i) {
            file_2 << (j.first);
            file_2 << " ";
            file_2 << (j.second);
            file_2 << " ";
        }
        file_2 << "\n";
    }

    if(!file_3)
    {
        std::cout << "error!";
        exit(1);
    }

    for(const auto & i : without_empty_ver)
    {
        for(const auto & j : i)
        {
            file_3 << (j.first);
            file_3 << " ";
            file_3 << (j.second);
            file_3 << " ";
        }
        file_3 << "\n";
    }
    file_1.close();
    file_2.close();
    file_3.close();
}
int main()
{
    //WORK2
    for(int i = 0; i < 2; i++)
    {
        Graph give_me_a_name(200, 0, 4, 350);
    }

    //
    //НЕ ПОМНЮ УСЛОВИЕ В КАКОЙ РАБОТЕ ЧО ПРОСТАВИТЬ НАДО ПОЭТОМУ СДЕЛАЮ ДЛЯ ВСЕХ ОДНО И ТОЖЕ В КОНСТРУКТОР ПЕРЕДАЙ САМ ЧО НАДО
    //ЗА ИСКЛЮЧЕНИЕМ R - оно во внешнем форе
    //ПАРАМЕТРЫ РАНДОМА 2 и 3 аргумент это левая граница и правая + 1
    //N, Q САМ ЗНАЕШЬ ДЛЯ ЧЕГО
    //

    //WORK3
    //Graph give_me_a_fucking_name(200, 0, 4, 4000, 350);
    //for(int i = 0; i < 4000; i++)
    //{
    //    Graph give_me_a_fucking_name(200, 0, 4, 350);
    //}

    //WORK4
    //Graph give_me_egor(200, 0, 4, 350);

    return 0;
}
























/*
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

double func(double x)
{
    return (-1 / (x*x*x*x + 2*x*x + 1));
}

void print(int count, double x, int flag)
{
    if(flag == 1)
        std::cout << "Dichotomy" << std::endl;
    else
        if(flag == 2)
            std::cout << "Golden" << std::endl;
        else
            std::cout << "Fibonacci" << std::endl;
    std::cout << "Func by Xmin = " << func(x) << endl;
    std::cout << "Xmin = " << x << endl;
    std::cout << "Count iter: " << count << endl;
}


void dichotomy(double a, double b, double _e)
{
    double a_in = a, b_in = b;
    double e = _e, min_x;

    double sigma = e / 4;

    int count = 0;
    do
    {
        count++;
        min_x = (a_in + b_in) / 2;

        double left = min_x - sigma;
        double right = min_x + sigma;

        if (func(left) <= func(right))
            b_in = right;
        else
            a_in = left;

    } while (fabs(b_in - a_in) > 2*e);

    print(count, min_x, 1);
}


void golden_cut(double a, double b, double e)
{
    int count = 0;

    double t = (sqrt(5) + 1) / 2;

    double x1 = b - 1 / t * (b - a);
    double x2 = a + 1 / t * (b - a);

    double fx1 = func(x1);
    double fx2 = func(x2);

    if (fx1 >= fx2)
        b = x2;
    else
        a = x1;

    bool flag;

    while (e < fabs(b - a)/2)
    {
        count++;
        if (fx2 > fx1)
        {
            b = x2;
            flag = true;
        }
        else
        {
            a = x1;
            flag = false;
        }
        x1 = b - (b - a) / t;
        x2 = a + (b - a) / t;
        if(flag)
            fx1 = func(x1);
        else
            fx2 = func(x2);
    }

    print(count, (a + b) / 2, 2);
}

double f(const size_t & n)
{
    if (n < 1)
        return 0;

    double f1 = 0;
    double f2 = 1;
    double fn = 0;

    for (size_t i = 1; i < n; ++i)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
};

void fibonacci(double a, double b, int n)
{
    double x1 = a + f(n - 2) / f(n) * (b - a);
    double x2 = a + f(n - 1) / f(n) * (b - a);

    double fx0 = func(x1);
    double fx1 = func(x2);

    int count = 1;

    std::cout << "FibSeq: ";
    while (n - 2 != count)
    {
        if (fx0 > fx1) {
            a = x1;
            x1 = x2;
            x1 = a + f(n - count - 1) / f(n - count) * (b - a);
            fx1 = func(x2);
        }
        else {
            b = x2;
            x2 = x1;

            x1 = a + f(n - count - 2) / f(n - count) * (b - a);
            fx0 = func(x1);
        }
        std::cout << f(n - count - 1);
        count++;
    }
    std::cout << std::endl;
    print(count, (b - a) / 2, 3);
}

int main()
{
    const int n = 10;

    double a = 1;
    double b = 2;

    dichotomy(a, b, 0.0001);
    std::cout << std::endl;

    fibonacci(a, b, n);
    std::cout << std::endl;

    golden_cut(1, 2, 0.0001);

}
*/