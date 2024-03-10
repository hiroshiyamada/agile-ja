#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <limits>

/*----これらの関数を変更する必要はありません----*/
std::vector<std::string> names{"Nick", "Lewis", "Nikos"};

bool contains(const std::string &name, const std::vector<std::string> &list_of_names)
{
    return std::find(list_of_names.begin(), list_of_names.end(), name) != list_of_names.end();
}

std::string get_name(const std::string &name, const std::vector<std::string> &list_of_names)
{
    if (contains(name, list_of_names))
    {
        return name;
    }
    else
    {
        return "";
    }
}

void add_name(const std::string &name, std::vector<std::string> &list_of_names)
{
    list_of_names.push_back(name);
}

int add_two(int num)
{
    return num + 2;
}

double divide_by_two(double num)
{
    return num / 2;
}

std::string greeting(const std::string &name, double num)
{
    std::string message{"Hello, " + name + ". It is " + std::to_string(num) + " degrees warmer today than yesterday"};
    std::cout << message << std::endl;
    return message;
}

/*----ここにコードを書いてください----*/
/*----難易度: 富士----*/

// `my_assert` をここに定義し、以降のテストに使用してください。
void my_assert(bool expr, std::string msg = "Test failed!")
{
    if (!expr)
    {
        throw std::runtime_error(msg);
    }
    std::cout << "Test passed!" << std::endl;
}

// `contains` 用のテスト `test_contains` を作成してください
void test_contains()
{
    try
    {
        my_assert(contains("Lewis", names) == true);
        my_assert(contains("Yamada", names) == false);
    }
    catch(std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
// `get_name` 用のテスト `test_get_name` を作成してください
void test_get_name()
{
    try
    {
        my_assert(get_name("Lewis", names) == "Lewis");
        my_assert(get_name("Yamada", names) == "");
    }
    catch(std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
// `add_name` 用のテスト `test_add_name` を作成してください
void test_add_name()
{
    try
    {
        add_name("Lewis", names);
        my_assert(names.back() == "Lewis");
    }
    catch(std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
// `add_two` 用のテスト `test_add_two` を作成してください
void test_add_two()
{
    try
    {
        my_assert(add_two(3) == 5);
    }
    catch(std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
// `divide_by_two` 用のテスト `test_divide_by_two` を作成してください​
void test_divide_by_two()
{
    constexpr double e = std::numeric_limits<double>::epsilon();
    try
    {
        my_assert(std::abs(divide_by_two(3) - 1.5) <= e);
    }
    catch(std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
// `greeting` 用のテスト `test_greeting` を作成してください
void test_greeting()
{
    try
    {
        my_assert(greeting("Yamada", 2) == "Hello, Yamada. It is 2.000000 degrees warmer today than yesterday");
    }
    catch(std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main(){
    test_contains();
    test_get_name();
    test_add_name();
    test_add_two();
    test_divide_by_two();
    test_greeting();
    return 0;
}
