#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    size_t count{};

    std::cout << "Enter the number of elements from 25 to 50: ";

    std::string input;
    getline(std::cin, input);
    std::stringstream ss(input);
    ss >> count;

    if (count < 25 || count > 50) {
        count = 30;
    }

    std::vector<int> vector_start(count, 0);
    std::map<size_t, int> map_start;

    for (size_t i{0}; i < count; ++i) {
        vector_start[i] = rand()%9 + 1;
        map_start[i] = rand()%9 + 1;
    }

    int del_elem_vec{rand()%15 + 1};

    for (int i{0}; i < del_elem_vec; ++i) {
        size_t k{rand()%(count - i)};
        vector_start.erase(vector_start.begin() + k);
    }

    int del_elem_map{rand()%15 + 1};

    while (map_start.size() != (count - del_elem_map)) {
        size_t k{rand()%(count)};
        map_start.erase(k);
    }

    std::vector<int> vector_result{};
    std::map<size_t, int> map_result;
    count = 0;

    for (auto it_m : map_start) {
        for (auto it_v = vector_start.begin(); it_v != vector_start.end(); ++it_v) {
            if (it_m.second == *it_v) {
                vector_result.push_back(*it_v);
                map_result[count] = it_m.second;
                vector_start.erase(it_v);
                ++count;
                break;
            }
        }
    }

    std::cout << "vec: ";
    for (auto it : vector_result) {
        std::cout << it << " ";
    }
    std::cout << "\nmap: ";
    for (auto it : map_result) {
        std::cout << it.second << " ";
    }
    std::cout << "\n";

    return 0;
}
