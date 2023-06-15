#include "srt.hpp"
#include <queue>
#include <iostream>

void SRT::add_process(const std::string& name, int arrival_time, int burst_time) {
    processes_.push(Process(name, arrival_time, burst_time));
}

void SRT::run() {
    std::priority_queue<Process> ready_queue;
    std::vector<Process> completed_processes; // New vector to store completed processes

    int current_time = 0;
    while (!processes_.empty() || !ready_queue.empty()) {
        // Check for new arrivals
        while (!processes_.empty() && processes_.front().getArrivalTime() <= current_time) {
            ready_queue.push(processes_.front());
            processes_.pop();
        }

        // Get the process with the shortest remaining time
        if (ready_queue.empty()) {
            current_time = processes_.front().getArrivalTime();
        }
        else {
            Process p = ready_queue.top();
            ready_queue.pop();

            current_time++;

            // Update the remaining time of the process
            p.setRemainingTime(p.getRemainingTime() - 1);

            // Check if the process has finished executing
            if (p.getRemainingTime() > 0) {
                ready_queue.push(p);
            }
            else {
                // Push completed process into the vector
                completed_processes.push_back(p);
                
                int completion_time = current_time + p.getBurstTime();

                std::cout << p.getName() << "| Arrived: " << p.getArrivalTime() << "  Last Execution Started: " << current_time << "  Finished: " << completion_time << "  Turnaround: " << (completion_time - p.getArrivalTime()) << "  Burst Time: " <<
                p.getBurstTime() << std::endl;
            }
        }
    }
}
