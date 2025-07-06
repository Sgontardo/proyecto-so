#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include "../process.h"

class fcfs
{
public:
    fcfs();
    void add_process(const process& p);
    void execute();
    void calculate_metrics();

    double get_avg_turnaround_time() const;
    double get_avg_waiting_time() const;
    double get_avg_response_time() const;
    double get_cpu_utilization() const;

    const std::vector<process>& get_processes() const;

private:
    std::vector<process> processes;
    double avg_turnaround_time;
    double avg_waiting_time;
    double avg_response_time;
};

#endif // FCFS_H