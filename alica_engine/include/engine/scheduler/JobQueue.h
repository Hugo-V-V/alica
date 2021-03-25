#pragma once

#include "engine/scheduler/Job.h"
#include <memory>
#include <mutex>

namespace alica {
namespace scheduler {
    class JobQueue
    {
    public:
        void insert(std::shared_ptr<Job>&& job);
        std::shared_ptr<Job> popNext();
        void clear();
        std::shared_ptr<Job> getAvailableJob(alica::AlicaTime time);

    private:
        std::vector<std::shared_ptr<Job>> _queue;
        std::mutex _mtx;
        bool allPrerequisitesFinished(std::shared_ptr<Job> job);
    };
}
}

