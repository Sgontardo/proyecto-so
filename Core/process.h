#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class process {
public:
    process(int id, int arrival, int burst, int priority);

    int get_id() const;
    int get_arrival_time() const;
    int get_burst_time() const;
    int get_priority() const;
    int get_remaining_time() const;
    bool is_in_queue() const;

    void set_in_queue(bool in_queue);
    void execute(int time);
    void set_completion_time(int time);
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
    int remaining_time;
    bool in_queue;

    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

#endif // PROCESS_H