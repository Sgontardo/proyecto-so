#ifndef PROCESS_GENERATOR_H
#define PROCESS_GENERATOR_H

#include "../Core/process.h"
#include <vector>

class process_generator
{
public:
    std::vector<process> generate_random_processes(int count);
};

#endif // PROCESS_GENERATOR_H