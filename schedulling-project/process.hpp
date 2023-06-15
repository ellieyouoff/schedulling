#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <string>

class Process {
public:
    Process();
    Process(const std::string& name, int arrival_time, int burst_time);

    std::string getName() const;
    int getArrivalTime() const;
    int getBurstTime() const;
    int getRemainingTime() const;
    void setRemainingTime(int remaining_time);
    bool operator<(const Process& other) const;

private:
    std::string name_;
    int arrival_time_;
    int burst_time_;
    int remaining_time_;
};

#endif
