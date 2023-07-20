#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    std::cout << "Before sleep." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "After sleep." << std::endl;
    return 0;
}
