#include "SchedulingTestSequenceSubPlan11614964379654.h"
/*PROTECTED REGION ID(eph1614964379654) ENABLED START*/
// Add additional options here
#include "TestWorldModel.h"
#include "engine/RunningPlan.h"
/*PROTECTED REGION END*/

namespace alica
{
// Plan:SchedulingTestSequenceSubPlan11614964379654
SchedulingTestSequenceSubPlan11614964379654::SchedulingTestSequenceSubPlan11614964379654()
        : DomainPlan()
{
    /*PROTECTED REGION ID(con1614964379654) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
SchedulingTestSequenceSubPlan11614964379654::~SchedulingTestSequenceSubPlan11614964379654()
{
    /*PROTECTED REGION ID(dcon1614964379654) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
/**
 * Task: SchedulerTestSubPlanEntrypoint  -> EntryPoint-ID: 1614964853637
 */
std::shared_ptr<UtilityFunction> UtilityFunction1614964379654::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1614964379654) ENABLED START*/
    std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;
    /*PROTECTED REGION END*/
}

/*PROTECTED REGION ID(methods1614964379654) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/
} // namespace alica