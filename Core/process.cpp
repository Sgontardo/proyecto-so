#include "process.h"

process::process(int id, int arrival_time, int burst_time, int priority)
    : id(id), arrival_time(arrival_time), burst_time(burst_time), priority(priority),
      remaining_time(burst_time), in_queue(false),
      turnaround_time(0), waiting_time(0), response_time(0) {}

int process::get_id() const {
    return id;
}

int process::get_arrival_time() const {
    return arrival_time;
}

int process::get_burst_time() const {
    return burst_time;
}

int process::get_priority() const {
    return priority;
}

int process::get_remaining_time() const {
    return remaining_time;
}

bool process::is_in_queue() const {
    return in_queue;
}

void process::set_in_queue(bool in_queue) {
    this->in_queue = in_queue;
}

void process::execute(int time) {
    remaining_time -= time;
}

void process::set_completion_time(int time) {
    completion_time = time;
}

int process::get_completion_time() const {
    return completion_time;
}

void process::set_turnaround_time(int time) {
    turnaround_time = time;
}

void process::set_waiting_time(int time) {
    waiting_time = time;
}

void process::set_response_time(int time) {
    response_time = time;
}

void process::set_priority(int priority) {
    this->priority = priority;
}

int process::get_turnaround_time() const {
    return turnaround_time;
}

int process::get_waiting_time() const {
    return waiting_time;
}

int process::get_response_time() const {
    return response_time;
}