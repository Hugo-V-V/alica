#include "Plans/BehaviourTriggerPlan1428492704177.h"
using namespace alica;
/*PROTECTED REGION ID(eph1428492704177) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:BehaviourTriggerPlan

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1428492704179

     */
    shared_ptr<UtilityFunction> UtilityFunction1428492704177::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1428492704177) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

//State: TestState1 in Plan: BehaviourTriggerPlan

}
