#ifndef SRT_HPP
#define SRT_HPP

#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "process.hpp"

class SRT {
public:
    void add_process(const std::string& name, int arrival_time, int burst_time);
    void run();

private:
    std::queue<Process> processes_;
    std::vector<Process> waiting_processes_;
    std::map<std::string, int> remaining_times_;
};

#endif // SRT_HPP
