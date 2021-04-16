#pragma once

#include "engine/scheduler/Job.h"
#include "engine/scheduler/JobQueue.h"
#include <vector>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <atomic>
#include <yaml-cpp/yaml.h>

namespace alica
{
    class AlicaEngine;

namespace scheduler
{
    class Scheduler
    {
    public:
        Scheduler(const alica::AlicaEngine* ae, const YAML::Node& config);
        ~Scheduler();
        void schedule(std::shared_ptr<Job>&& job, bool notify = true);
        void terminate();
        int getNextJobID();
        std::vector<std::weak_ptr<Job>> getPrerequisites(int id);
    private:
        const alica::AlicaEngine* _ae;
        JobQueue _jobQueue;
        JobQueue _repeatedJobQueue;
        std::mutex _workerMtx;
        std::condition_variable _workerCV;
        std::vector<std::thread> _workers;
        std::atomic<bool> _running;
        std::atomic<int> _jobID;

        void workerFunction();
    };
}
}
