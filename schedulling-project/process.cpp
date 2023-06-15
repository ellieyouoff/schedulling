#include "Process.hpp"

Process::Process() : name_(""), arrival_time_(0), burst_time_(0), remaining_time_(0) {}

Process::Process(const std::string& name, int arrival_time, int burst_time)
    : name_(name), arrival_time_(arrival_time), burst_time_(burst_time), remaining_time_(burst_time) {}

std::string Process::getName() const {
    return name_;
}

int Process::getArrivalTime() const {
    return arrival_time_;
}

int Process::getBurstTime() const {
    return burst_time_;
}

int Process::getRemainingTime() const {
    return remaining_time_;
}

void Process::setRemainingTime(int remaining_time) {
    remaining_time_ = remaining_time;
}

bool Process::operator<(const Process& other) const {
    return remaining_time_ < other.remaining_time_;
}
