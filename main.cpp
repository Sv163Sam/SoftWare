#include "main.h"

Graph::Graph(int N, int m0, int m, int R, int Q) //Q - предел суммы висячих
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
        exit(1);

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
    file_1.open("/Users/vladimirskobcov/Desktop/SoftWare/all_ver.txt", std::fstream ::out | std::fstream ::in);
    file_2.open("/Users/vladimirskobcov/Desktop/SoftWare/empty_ver.txt",  std::fstream ::out | std::fstream ::in);
    file_3.open("/Users/vladimirskobcov/Desktop/SoftWare/without_empty_ver.txt", std::fstream ::out | std::fstream ::in);

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
    file_1 << "\n\n";

    if(!file_2)
    {
        std::cout << "error!";
        exit(1);
    }

    for(const auto & i : empty_ver)
    {
        for(const auto & j : i)
        {
            file_2 << (j.first);
            file_2 << " ";
            file_2 << (j.second);
            file_2 << " ";
        }
        file_2 << "\n";
    }
    file_2 << "\n\n";

    if(!file_3)
    {
        std::cout << "error!";
        exit(1);
    }

    for(const auto & i : without_empty_ver)
    {
        file_3 << "\n";
        for(const auto & j : i)
        {
            file_3 << (j.first);
            file_3 << " ";
            file_3 << (j.second);
            file_3 << " ";
        }
    }
    file_3 << "\n\n";


    file_1.close();
    file_2.close();
    file_3.close();
}

int main()
{
    //WORK2
    for(int i = 0; i < 1; i++) {
        Graph give_me_a_name(200, 0, 4, 3, 350);
    }
    //WORK3
    //Graph give_me_a_fucking_name(200, 0, 4, 4000, 350);
    //WORK4
    //Graph give_me_egor(200, 0, 4, 1, 350);

    return 0;
}