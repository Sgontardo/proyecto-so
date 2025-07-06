#ifndef PRIORITY_H
#define PRIORITY_H

#include <vector>
#include "../process.h"

// Estructura para comparar procesos por prioridad
struct ComparePriority {
    bool operator()(const process& a, const process& b) const {
        // Procesos con menor valor de prioridad tienen mayor prioridad
        return a.get_priority() > b.get_priority();
    }
};

class priority
{
public:
    priority(bool preemptive);
    void add_process(const process& p);
    void execute();
    void calculate_metrics();

    // Métricas
    double get_avg_turnaround_time() const;
    double get_avg_waiting_time() const;
    double get_avg_response_time() const;
    double get_cpu_utilization() const;

    const std::vector<process>& get_processes() const;

private:
    std::vector<process> processes;
    bool preemptive; // Indica si es con desalojo

    // Métricas
    double avg_turnaround_time;
    double avg_waiting_time;
    double avg_response_time;

    int idle_time; // Tiempo total de inactividad de la CPU
};

#endif // PRIORITY_H