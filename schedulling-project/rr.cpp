#include "rr.hpp"

RR::RR(int quantum) : quantum_(quantum) {}

void RR::add_process(const std::string& name, int arrival_time, int burst_time) {
    processes_.push_back(Process(name, arrival_time, burst_time));
}


void RR::process_ready_queue(int& current_time, std::vector<Process>& ready_queue) {
    Process p("PT", 0, 0);

    // If there are processes in the ready queue
    if (!ready_queue.empty()) {
        // Get the process that has been waiting the longest
        int longest_waiting_index = 0;
        for (int i = 1; i < ready_queue.size(); i++) {
            if (ready_queue[i].getRemainingTime() < ready_queue[longest_waiting_index].getRemainingTime()) {
                longest_waiting_index = i;
            }
        }
        // Set the current process to be the one with the longest waiting time
        p = ready_queue[longest_waiting_index];
        // Remove the current process from the ready queue
        ready_queue.erase(ready_queue.begin() + longest_waiting_index);
    } else {
        // If there are no ready processes, just wait until the next one arrives
        current_time++;
        return;
    }

    // Calculate waiting time for the process
    int waiting_time = current_time - p.getArrivalTime();

    // Run the process for the quantum time or until it completes, whichever comes first
    p.setRemainingTime(p.getRemainingTime() - quantum_);
    int remaining_time = p.getRemainingTime();
    if (remaining_time <= 0) {
        int completion_time = current_time + p.getRemainingTime() + quantum_;
        // If the process has completed, print its completion time
        std::cout << p.getName() << "| Arrived: " << p.getArrivalTime() << " Last execution Started: " << current_time << " Finished: " << completion_time << " Turnaround: " << (completion_time - p.getArrivalTime()) << " Waiting Time: " << waiting_time << " Burst Time: " << p.getBurstTime() << std::endl;
    } else {
        // If the process has not completed, add it back to the ready queue
        ready_queue.push_back(p);
        // Move to the next quantum
        current_time += quantum_;
    }
}

void RR::run() {
    // If the quantum value is not valid, set it to 2
    if (quantum_ < 1 || quantum_ > 4) {
        std::cout << "Invalid quantum value. Setting quantum to 2." << std::endl;
        quantum_ = 2;
    }

    int current_time = 0;
    int next_process_index = 0;
    std::vector<Process> ready_queue;

    // Loop until there are no more processes to add to the ready queue and the ready queue is empty
    while (next_process_index < processes_.size() || !ready_queue.empty()) {
        // Add any arriving processes to the ready queue
        while (next_process_index < processes_.size() && processes_[next_process_index].getArrivalTime() <= current_time) {
            ready_queue.push_back(processes_[next_process_index]);
            next_process_index++;
        }

        // Process the ready queue
        process_ready_queue(current_time, ready_queue);
    }
}
