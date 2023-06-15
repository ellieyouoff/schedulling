#include <iostream>
#include <vector>
#include <algorithm>
#include "process.hpp"
#include "fcfs.hpp"
#include "sjf.hpp"
#include "rr.hpp"
#include "srt.hpp"

int main() {
    std::vector<Process> processes;

    int max_processes, max_burst_time;
    std::cout << "Enter the maximum number of processes: ";
    std::cin >> max_processes;
    std::cout << "Enter the maximum burst time for each process: ";
    std::cin >> max_burst_time;

    int i = 1;
    while (i <= max_processes) {
        std::string name;
        int arrival_time, burst_time;
        std::cout << "Enter the details for process " << i << std::endl;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Arrival time: ";
        std::cin >> arrival_time;
        std::cout << "Burst time: ";
        std::cin >> burst_time;

        // Validate the input
        if (arrival_time < 0 || burst_time < 1 || burst_time > max_burst_time) {
            std::cout << "Invalid input. Please try again." << std::endl;
            continue;
        }

        processes.push_back(Process(name, arrival_time, burst_time));
        i++;

        char choice;
        if (i <= max_processes){
            std::cout << "Do you want to add more processes? (y/n): ";
        } else {
            break;
        }
        
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    // First Come First Serve (FCFS) Scheduling
    FCFS fcfs;
    for (const Process& p : processes) {
        fcfs.add_process(p.getName(), p.getArrivalTime(), p.getBurstTime());
    }
    std::cout << "First Come First Serve (FCFS) Scheduling:" << std::endl;
    fcfs.run();
    std::cout << std::endl;

    // Shortest Job First (SJF) Scheduling
    SJF sjf;
    for (const Process& p : processes) {
        sjf.add_process(p.getName(), p.getArrivalTime(), p.getBurstTime());
    }
    std::cout << "Shortest Job First (SJF) Scheduling:" << std::endl;
    sjf.run();
    std::cout << std::endl;

    // Round Robin (RR) Scheduling
    RR rr(3); // Time quantum is set to 2
    for (const Process& p : processes) {
        rr.add_process(p.getName(), p.getArrivalTime(), p.getBurstTime());
    }
    std::cout << "Round Robin (RR) Scheduling:" << std::endl;
    rr.run();
    std::cout << std::endl;

    // Shortest Remaining Time (SRT) Scheduling
    SRT srt;
    for (const Process& p : processes) {
        srt.add_process(p.getName(), p.getArrivalTime(), p.getBurstTime());
    }
    std::cout << "Shortest Remaining Time (SRT) Scheduling:" << std::endl;
    srt.run();
    std::cout << std::endl;

    return 0;
}
