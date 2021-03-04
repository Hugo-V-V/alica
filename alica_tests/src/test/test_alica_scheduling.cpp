#include "test_alica.h"
#include "CounterClass.h"

#include <alica/test/Util.h>
#include <gtest/gtest.h>

namespace alica
{
namespace
{

class AlicaSchedulingPlan : public AlicaTestFixture
{
protected:
    const char* getRoleSetName() const override { return "Roleset"; }
    const char* getMasterPlanName() const override { return "SchedulingTestMasterPlan"; }
    bool stepEngine() const override { return true; }
};

TEST_F(AlicaSchedulingPlan, scheduling)
{
    ae->start();
    ASSERT_EQ(0, CounterClass::called);
    ac->stepEngine();
    // init of scheduling plan 1, 2 and 3 called
    ASSERT_EQ(3, CounterClass::called);
    ac->stepEngine();
    // onTermination of scheduling plan 2 and 3 called
    ASSERT_EQ(5, CounterClass::called);
    ac->stepEngine();
    // onTermination of scheduling plan 1 called
    ASSERT_EQ(6, CounterClass::called);
}

} //namespace
} //namespace alica




