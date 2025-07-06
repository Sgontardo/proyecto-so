#include "process_generator.h"
#include <cstdlib>
#include <ctime>

std::vector<process> process_generator::generate_random_processes(int count) {
    std::srand(std::time(nullptr)); // Semilla para números aleatorios
    std::vector<process> processes;
    for (int i = 0; i < count; ++i) {
        int arrival = std::rand() % 10; // Tiempo de llegada entre 0 y 9
        int burst = (std::rand() % 10) + 1; // Tiempo de ráfaga entre 1 y 10
        int priority = (std::rand() % 5) + 1; // Prioridad entre 1 y 5
        processes.emplace_back(i + 1, arrival, burst, priority);
    }
    return processes;
}