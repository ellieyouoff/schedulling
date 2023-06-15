#include "sjf.hpp"
#include <algorithm>

void SJF::add_process(const std::string& name, int arrival_time, int burst_time) {
    processes_.emplace_back(name, arrival_time, burst_time);
}

void SJF::run() {
    int current_time = 0;
    while (!processes_.empty()) {
        // Sort the processes based on arrival time and burst time
        std::sort(processes_.begin(), processes_.end(),
            [](const Process& a, const Process& b) {
                if (a.getArrivalTime() != b.getArrivalTime()) {
                    return a.getArrivalTime() < b.getArrivalTime();
                }
                return a.getBurstTime() < b.getBurstTime();
            });

        Process p = processes_.front();
        processes_.erase(processes_.begin());

        // Set the current time to the maximum of the current time and the arrival time of the process
        current_time = std::max(current_time, p.getArrivalTime());
        int completion_time = current_time + p.getBurstTime();

        std::cout << p.getName() << "| Arrived: " << p.getArrivalTime() << "  Last Execution Started: " << current_time  << "  Finished: " << completion_time << "  Turnaround: " << (completion_time - p.getArrivalTime()) << "  Burst Time: " <<
        p.getBurstTime() << std::endl;

        current_time = completion_time;
    }
}
