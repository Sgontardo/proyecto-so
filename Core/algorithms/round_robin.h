#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <vector>
#include <queue>
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

    // Obtener procesos con métricas calculadas
    const std::vector<process>& get_processes() const;

private:
    int quantum;
    std::vector<process> processes;
    std::queue<process> ready_queue;

    // Métricas
    double avg_turnaround_time;
    double avg_waiting_time;
    double avg_response_time;
};

#endif // ROUND_ROBIN_H