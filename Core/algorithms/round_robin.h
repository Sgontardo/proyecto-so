#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <vector>
#include <queue>
#include <utility> // Para std::pair
#include "../process.h"

class round_robin
{
public:
    round_robin(int quantum);
    void add_process(const process& p);
    void execute();
    void calculate_metrics();

    // Métricas
    double get_avg_turnaround_time() const;
    double get_avg_waiting_time() const;
    double get_avg_response_time() const;
    double get_cpu_utilization() const;

    // Obtener procesos con métricas calculadas
    const std::vector<process>& get_processes() const;

    // Nueva función para obtener la secuencia de ejecución
    const std::vector<std::pair<int, int>>& get_execution_sequence() const;

private:
    int quantum;
    std::vector<process> processes;
    
    // Secuencia de ejecución: (ID del proceso, tiempo de inicio)
    std::vector<std::pair<int, int>> execution_sequence;

    // Métricas
    double avg_turnaround_time;
    double avg_waiting_time;
    double avg_response_time;

    int idle_time; // Tiempo total de inactividad de la CPU
};

#endif // ROUND_ROBIN_H