#pragma once

#include "engine/scheduler/Job.h"
#include <vector>
#include <condition_variable>
#include <mutex>
#include <thread>

namespace alica
{
namespace scheduler
{
    class Scheduler
    {
    public:
        Scheduler(int numberOfThreads);
        ~Scheduler();
        void add(std::shared_ptr<Job> job);
    private:
        std::vector<std::shared_ptr<Job>> queue;
        std::condition_variable condition;
        std::vector<std::thread*> _workers;
        std::mutex mtx;
        bool running = true;

        void workerFunction();
    };
}
}