#ifndef RR_HPP
#define RR_HPP

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "process.hpp"

class RR {
public:
    explicit RR(int quantum);

    void add_process(const std::string& name, int arrival_time, int burst_time);
    void process_ready_queue(int& current_time, std::vector<Process>& ready_queue);
    void run();

private:
    std::vector<Process> processes_;
    int quantum_;
};

#endif // RR_HPP
