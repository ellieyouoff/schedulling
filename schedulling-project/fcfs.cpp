#include "fcfs.hpp"

void FCFS::add_process(const std::string& name, int arrival_time, int burst_time) {
    Process p(name, arrival_time, burst_time);
    // Find the position to insert the new process in the processes vector
    auto it = std::lower_bound(processes_.begin(), processes_.end(), p,
        [](const Process& lhs, const Process& rhs) {
            return lhs.getArrivalTime() < rhs.getArrivalTime();
        });
    processes_.insert(it, p);
}



void FCFS::run() {
    int current_time = 0;
    while (!processes_.empty()) {
        Process p = processes_.front();
        processes_.erase(processes_.begin());

        // Set the current time to the maximum of the current time and the arrival time of the process
        current_time = std::max(current_time, p.getArrivalTime());
        
        // Calculate the completion time of the process
        int completion_time = current_time + p.getBurstTime();

        std::cout << p.getName() << "| Arrived: " << p.getArrivalTime() << "  Last Execution Started: " << current_time << "  Finished: " << completion_time << "  Turnaround: " << (completion_time - p.getArrivalTime()) << "  Burst Time: " <<
        p.getBurstTime() << std::endl;

        // Update the current time to the completion time of the process
        current_time = completion_time;
    }
}
