#include "round_robin.h"
#include <algorithm>
#include <queue>
#include <iostream>

round_robin::round_robin(int quantum) : quantum(quantum), avg_turnaround_time(0), avg_waiting_time(0), avg_response_time(0), idle_time(0) {}

void round_robin::add_process(const process& p) {
    processes.push_back(p);
}

void round_robin::execute() {
    if (processes.empty()) return;

    // Ordenar procesos por tiempo de llegada
    std::sort(processes.begin(), processes.end(), [](const process& a, const process& b) {
        return a.get_arrival_time() < b.get_arrival_time();
    });

    int current_time = 0;
    int completed_processes = 0;
    size_t next_process_index = 0;
    std::queue<size_t> ready_queue;
    std::vector<int> remaining_burst(processes.size());
    std::vector<bool> response_calculated(processes.size(), false);
    int idle_time = 0; // Tiempo de inactividad de la CPU

    // Inicializar tiempos restantes
    for (size_t i = 0; i < processes.size(); ++i) {
        remaining_burst[i] = processes[i].get_burst_time();
    }

    while (completed_processes < processes.size()) {
        // Agregar procesos que han llegado y no están completados
        while (next_process_index < processes.size() &&
               processes[next_process_index].get_arrival_time() <= current_time) {
            if (remaining_burst[next_process_index] > 0) {
                ready_queue.push(next_process_index);
            }
            next_process_index++;
        }

        if (ready_queue.empty()) {
            // Registrar tiempo de inactividad
            if (next_process_index < processes.size()) {
                idle_time += processes[next_process_index].get_arrival_time() - current_time;
                current_time = processes[next_process_index].get_arrival_time();
            } else {
                current_time++;
                idle_time++;
            }
            continue;
        }

        // Obtener el próximo proceso a ejecutar
        size_t current_index = ready_queue.front();
        ready_queue.pop();

        // Registrar tiempo de respuesta si es la primera ejecución
        if (!response_calculated[current_index]) {
            processes[current_index].set_response_time(current_time - processes[current_index].get_arrival_time());
            response_calculated[current_index] = true;
        }

        // Ejecutar el proceso por quantum o tiempo restante
        int execution_time = std::min(quantum, remaining_burst[current_index]);
        remaining_burst[current_index] -= execution_time;
        current_time += execution_time;

        // Verificar si el proceso ha terminado
        if (remaining_burst[current_index] == 0) {
            processes[current_index].set_completion_time(current_time); // Establecer tiempo de finalización
            processes[current_index].set_turnaround_time(current_time - processes[current_index].get_arrival_time());
            processes[current_index].set_waiting_time(
                processes[current_index].get_turnaround_time() - processes[current_index].get_burst_time());
            completed_processes++;
        } else {
            // Si no terminó, volver a colocarlo en la cola
            ready_queue.push(current_index);
        }
    }

    // Guardar el tiempo de inactividad en una variable de clase (opcional)
    this->idle_time = idle_time;

    calculate_metrics();
}

// Calcula las métricas promedio de turnaround, waiting y response time
void round_robin::calculate_metrics() {
    double total_turnaround_time = 0;
    double total_waiting_time = 0;
    double total_response_time = 0;

    for (const auto& p : processes) {
        total_turnaround_time += p.get_turnaround_time();
        total_waiting_time += p.get_waiting_time();
        total_response_time += p.get_response_time();
    }

    avg_turnaround_time = total_turnaround_time / processes.size();
    avg_waiting_time = total_waiting_time / processes.size();
    avg_response_time = total_response_time / processes.size();
}

// Devuelve el tiempo promedio de turnaround
double round_robin::get_avg_turnaround_time() const {
    return avg_turnaround_time;
}

// Devuelve el tiempo promedio de espera
double round_robin::get_avg_waiting_time() const {
    return avg_waiting_time;
}

// Devuelve el tiempo promedio de respuesta
double round_robin::get_avg_response_time() const {
    return avg_response_time;
}

// Devuelve la lista de procesos
const std::vector<process>& round_robin::get_processes() const {
    return processes;
}

// Calcula la utilización de la CPU
double round_robin::get_cpu_utilization() const {
    int total_execution_time = 0; // Tiempo total de CPU ocupada
    int arrival_time_min = INT_MAX; // Menor tiempo de llegada
    int completion_time_max = 0; // Mayor tiempo de finalización

    for (const auto& p : processes) {
        total_execution_time += p.get_burst_time(); // Sumar tiempos de ráfaga
        arrival_time_min = std::min(arrival_time_min, p.get_arrival_time()); // Encontrar el menor tiempo de llegada
        completion_time_max = std::max(completion_time_max, p.get_completion_time()); // Encontrar el mayor tiempo de finalización
    }

    int total_time = completion_time_max - arrival_time_min; // Tiempo total transcurrido
    int active_time = total_time - idle_time; // Tiempo activo de la CPU
    return (total_time > 0) ? (static_cast<double>(active_time) / total_time) * 100 : 0.0;
}