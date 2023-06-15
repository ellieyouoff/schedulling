#ifndef SJF_HPP
#define SJF_HPP

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "process.hpp"


class SJF {
public:
    void add_process(const std::string& name, int arrival_time, int burst_time);

    void run();

private:
    std::vector<Process> processes_;
};

#endif // SJF_HPP
