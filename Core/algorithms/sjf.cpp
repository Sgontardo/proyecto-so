#include "sjf.h"
#include <algorithm>

sjf::sjf() : avg_turnaround_time(0), avg_waiting_time(0), avg_response_time(0) {}

void sjf::add_process(const process& p) {
    processes.push_back(p);
}

void sjf::execute() {
    // SJF no-preemptivo
    std::vector<process> ready_queue;
    std::vector<bool> finished(processes.size(), false);
    int completed = 0;
    int current_time = 0;

    while (completed < processes.size()) {
        // Buscar procesos que han llegado y no han terminado
        ready_queue.clear();
        for (size_t i = 0; i < processes.size(); ++i) {
            if (!finished[i] && processes[i].get_arrival_time() <= current_time) {
                ready_queue.push_back(processes[i]);
            }
        }

        if (ready_queue.empty()) {
            current_time++;
            continue;
        }

        // Seleccionar el proceso con menor burst_time
        auto it = std::min_element(ready_queue.begin(), ready_queue.end(),
            [](const process& a, const process& b) {
                return a.get_burst_time() < b.get_burst_time();
            });

        // Encontrar el índice real en processes
        int idx = -1;
        for (size_t i = 0; i < processes.size(); ++i) {
            if (!finished[i] && processes[i].get_id() == it->get_id()) {
                idx = static_cast<int>(i);
                break;
            }
        }

        if (idx == -1) continue;

        // Calcular tiempos
        processes[idx].set_response_time(current_time - processes[idx].get_arrival_time());
        current_time += processes[idx].get_burst_time();
        processes[idx].set_turnaround_time(current_time - processes[idx].get_arrival_time());
        processes[idx].set_waiting_time(processes[idx].get_turnaround_time() - processes[idx].get_burst_time());
        finished[idx] = true;
        completed++;
    }

    calculate_metrics();
}

void sjf::calculate_metrics() {
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

double sjf::get_avg_turnaround_time() const {
    return avg_turnaround_time;
}

double sjf::get_avg_waiting_time() const {
    return avg_waiting_time;
}

double sjf::get_avg_response_time() const {
    return avg_response_time;
}