#ifndef FCFS_HPP
#define FCFS_HPP

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "process.hpp"

class FCFS {
public:
    void add_process(const std::string& name, int arrival_time, int burst_time);
    void run();

private:
    std::vector<Process> processes_;
};

#endif // FCFS_HPP
