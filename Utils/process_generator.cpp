#include "process_generator.h"
#include <cstdlib>
#include <ctime>

std::vector<process> process_generator::generate_random_processes(int count)
{
    std::srand(std::time(nullptr));
    std::vector<process> processes;
    for (int i = 0; i < count; ++i) {
        int arrival = std::rand() % 10;
        int burst = (std::rand() % 10) + 1;
        processes.emplace_back(i + 1, arrival, burst, 0);
    }
    return processes;
}