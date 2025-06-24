#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class process
{
public:
    process(int id, int arrival_time, int burst_time, int priority);

    int get_id() const;
    int get_arrival_time() const;
    int get_burst_time() const;
    int get_priority() const;

    void set_turnaround_time(int time);
    void set_waiting_time(int time);
    void set_response_time(int time);
    void set_priority(int priority);

    int get_turnaround_time() const;
    int get_waiting_time() const;
    int get_response_time() const;

private:
    int id;
    int arrival_time;
    int burst_time;
    int priority;

    // Métricas
    int turnaround_time;
    int waiting_time;
    int response_time;
};

#endif // PROCESS_H