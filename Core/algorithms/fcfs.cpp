#include "fcfs.h"
#include <algorithm>

fcfs::fcfs() : avg_turnaround_time(0), avg_waiting_time(0), avg_response_time(0) {}

void fcfs::add_process(const process& p) {
    processes.push_back(p);
}

void fcfs::execute() {
    std::sort(processes.begin(), processes.end(), [](const process& a, const process& b) {
        return a.get_arrival_time() < b.get_arrival_time();
    });

    int current_time = 0;
    for (auto& p : processes) {
        if (current_time < p.get_arrival_time()) {
            current_time = p.get_arrival_time();
        }
        p.set_response_time(current_time - p.get_arrival_time());
        current_time += p.get_burst_time();
        p.set_completion_time(current_time); // Establecer el tiempo de finalización
        p.set_turnaround_time(current_time - p.get_arrival_time());
        p.set_waiting_time(p.get_turnaround_time() - p.get_burst_time());
    }
    calculate_metrics();
}

void fcfs::calculate_metrics() {
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

double fcfs::get_cpu_utilization() const {
    int total_burst_time = 0; // Tiempo total de CPU ocupada
    int arrival_time_min = INT_MAX; // Menor tiempo de llegada
    int completion_time_max = 0; // Mayor tiempo de finalización

    for (const auto& p : processes) {
        total_burst_time += p.get_burst_time(); // Sumar tiempos de ráfaga
        arrival_time_min = std::min(arrival_time_min, p.get_arrival_time()); // Encontrar el menor tiempo de llegada
        completion_time_max = std::max(completion_time_max, p.get_completion_time()); // Encontrar el mayor tiempo de finalización
    }

    int total_time = completion_time_max - arrival_time_min; // Tiempo total transcurrido
    return (total_time > 0) ? (static_cast<double>(total_burst_time) / total_time) * 100 : 0.0;
}

double fcfs::get_avg_turnaround_time() const {
    return avg_turnaround_time;
}

double fcfs::get_avg_waiting_time() const {
    return avg_waiting_time;
}

double fcfs::get_avg_response_time() const {
    return avg_response_time;
}

const std::vector<process>& fcfs::get_processes() const {
    return processes;
}