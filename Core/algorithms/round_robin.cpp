#include "round_robin.h"
#include <algorithm>
#include <iostream>

round_robin::round_robin(int quantum) : quantum(quantum), avg_turnaround_time(0), avg_waiting_time(0), avg_response_time(0) {}

void round_robin::add_process(const process& p) {
    processes.push_back(p);
}

void round_robin::execute() {
    int current_time = 0;
    std::vector<int> remaining_burst_time(processes.size());
    std::vector<bool> response_time_calculated(processes.size(), false);

    for (size_t i = 0; i < processes.size(); ++i) {
        remaining_burst_time[i] = processes[i].get_burst_time();
    }

    while (true) {
        bool done = true;

        for (size_t i = 0; i < processes.size(); ++i) {
            if (remaining_burst_time[i] > 0) {
                done = false;

                if (!response_time_calculated[i]) {
                    processes[i].set_response_time(current_time - processes[i].get_arrival_time());
                    response_time_calculated[i] = true;
                }

                if (remaining_burst_time[i] > quantum) {
                    current_time += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    current_time += remaining_burst_time[i];
                    processes[i].set_turnaround_time(current_time - processes[i].get_arrival_time());
                    processes[i].set_waiting_time(processes[i].get_turnaround_time() - processes[i].get_burst_time());
                    remaining_burst_time[i] = 0;
                }
            }
        }

        if (done) break;
    }

    calculate_metrics();
}

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

double round_robin::get_avg_turnaround_time() const {
    return avg_turnaround_time;
}

double round_robin::get_avg_waiting_time() const {
    return avg_waiting_time;
}

double round_robin::get_avg_response_time() const {
    return avg_response_time;
}