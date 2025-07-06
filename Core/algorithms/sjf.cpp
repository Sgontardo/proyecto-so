#include "sjf.h"
#include <algorithm>

sjf::sjf() : avg_turnaround_time(0), avg_waiting_time(0), avg_response_time(0) {}

void sjf::add_process(const process& p) {
    processes.push_back(p);
}

void sjf::execute() {
    // Ordenar los procesos por ráfaga (y por llegada si las ráfagas son iguales)
    std::sort(processes.begin(), processes.end(), [](const process& a, const process& b) {
        if (a.get_burst_time() == b.get_burst_time()) {
            return a.get_arrival_time() < b.get_arrival_time();
        }
        return a.get_burst_time() < b.get_burst_time();
    });

    int current_time = 0;
    for (auto& p : processes) {
        if (current_time < p.get_arrival_time()) {
            current_time = p.get_arrival_time();
        }
        p.set_response_time(current_time - p.get_arrival_time());
        current_time += p.get_burst_time();
        p.set_turnaround_time(current_time - p.get_arrival_time());
        p.set_waiting_time(p.get_turnaround_time() - p.get_burst_time());
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

const std::vector<process>& sjf::get_processes() const {
    return processes;
}