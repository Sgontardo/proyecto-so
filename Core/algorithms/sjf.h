#ifndef SJF_H
#define SJF_H

#include <vector>
#include "../process.h"

class sjf
{
public:
    sjf();
    void add_process(const process& p);
    void execute();
    void calculate_metrics();

    double get_avg_turnaround_time() const;
    double get_avg_waiting_time() const;
    double get_avg_response_time() const;

private:
    std::vector<process> processes;
    double avg_turnaround_time;
    double avg_waiting_time;
    double avg_response_time;
};

#endif // SJF_H