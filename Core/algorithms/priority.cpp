#include "priority.h"
#include <algorithm>
#include <queue>
#include <iostream>

priority::priority(bool preemptive) : preemptive(preemptive), avg_turnaround_time(0), avg_waiting_time(0), avg_response_time(0), idle_time(0) {}

void priority::add_process(const process& p) {
    processes.push_back(p);
}

void priority::execute() {
    if (preemptive) {
        auto compare = [](process* a, process* b) {
            if (a->get_priority() == b->get_priority()) {
                return a->get_arrival_time() > b->get_arrival_time();
            }
            return a->get_priority() > b->get_priority();
        };

        std::priority_queue<process*, std::vector<process*>, decltype(compare)> ready_queue(compare);
        int current_time = 0;
        int completed_processes = 0;
        int idle_time = 0; // Tiempo de inactividad de la CPU

        while (completed_processes < processes.size()) {
            // Agregar procesos que han llegado a la cola de listos
            for (auto& p : processes) {
                if (p.get_arrival_time() <= current_time && p.get_remaining_time() > 0 && !p.is_in_queue()) {
                    ready_queue.push(&p);
                    p.set_in_queue(true);
                }
            }

            if (ready_queue.empty()) {
                // Registrar tiempo de inactividad
                idle_time++;
                current_time++;
                continue;
            }

            // Ejecutar el proceso con mayor prioridad
            process* current_process = ready_queue.top();
            ready_queue.pop();

            // Ejecutar el proceso por 1 unidad de tiempo
            current_process->execute(1);
            current_time++;

            // Si el proceso ha terminado, calcular sus métricas
            if (current_process->get_remaining_time() == 0) {
                current_process->set_completion_time(current_time);
                current_process->set_turnaround_time(current_time - current_process->get_arrival_time());
                current_process->set_waiting_time(current_process->get_turnaround_time() - current_process->get_burst_time());
                completed_processes++;
            } else {
                // Si no ha terminado, volver a agregarlo a la cola
                ready_queue.push(current_process);
            }
        }

        // Guardar el tiempo de inactividad en una variable de clase (opcional)
        this->idle_time = idle_time;
    } else {
        // Algoritmo de prioridad sin desalojo
        std::sort(processes.begin(), processes.end(), [](const process& a, const process& b) {
            if (a.get_priority() == b.get_priority()) {
                return a.get_arrival_time() < b.get_arrival_time();
            }
            return a.get_priority() < b.get_priority();
        });

        int current_time = 0;
        int idle_time = 0; // Tiempo de inactividad de la CPU

        for (auto& p : processes) {
            if (current_time < p.get_arrival_time()) {
                idle_time += p.get_arrival_time() - current_time; // Registrar tiempo de inactividad
                current_time = p.get_arrival_time(); // Esperar si el proceso aún no ha llegado
            }

            // Calcular tiempos
            p.set_response_time(current_time - p.get_arrival_time());
            current_time += p.get_burst_time();
            p.set_completion_time(current_time); // Registrar tiempo de finalización
            p.set_turnaround_time(current_time - p.get_arrival_time());
            p.set_waiting_time(p.get_turnaround_time() - p.get_burst_time());
        }

        // Guardar el tiempo de inactividad en una variable de clase
        this->idle_time = idle_time;
    }

    calculate_metrics();
}

void priority::calculate_metrics() {
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

double priority::get_cpu_utilization() const {
    int total_burst_time = 0;
    int arrival_time_min = INT_MAX;
    int completion_time_max = 0;

    for (const auto& p : processes) {
        total_burst_time += p.get_burst_time(); // Sumar tiempos de ráfaga
        arrival_time_min = std::min(arrival_time_min, p.get_arrival_time()); // Encontrar el menor tiempo de llegada
        completion_time_max = std::max(completion_time_max, p.get_completion_time()); // Encontrar el mayor tiempo de finalización
    }

    int total_time = completion_time_max - arrival_time_min; // Tiempo total transcurrido
    return (total_time > 0) ? (static_cast<double>(total_burst_time) / total_time) * 100 : 0.0;
}

double priority::get_avg_turnaround_time() const {
    return avg_turnaround_time;
}

double priority::get_avg_waiting_time() const {
    return avg_waiting_time;
}

double priority::get_avg_response_time() const {
    return avg_response_time;
}

const std::vector<process>& priority::get_processes() const {
    return processes;
}