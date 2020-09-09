#include "CounterClass.h"
#include "SimpleSwitches.h"
#include <engine/AlicaEngine.h>
#include <engine/PlanBase.h>

#include <gtest/gtest.h>
#include <iostream>
#include <test_alica.h>
#include <thread>

namespace alica
{
namespace
{

class BackForthTest : public AlicaTestFixture
{
protected:
    const char* getRoleSetName() const override { return "Roleset"; }
    const char* getMasterPlanName() const override { return "BackForth"; }
};

/**
 * Tests if Behaviour with Constraints are called
 */
TEST_F(BackForthTest, testing)
{
    ASSERT_NO_SIGNAL
    CounterClass::called = 0;
    SimpleSwitches::reset();

    ASSERT_EQ(CounterClass::called, 0);
    tc->startEngine();
    tc->stepEngine();

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    int curCount = CounterClass::called;
    ASSERT_GT(curCount, 0);
    ASSERT_EQ(tc->getRootNode()->getActiveState()->getId(), 1529456584983);

    SimpleSwitches::set(0, true);
    tc->stepEngine();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    ASSERT_GT(CounterClass::called, curCount);
    curCount = CounterClass::called;
    ASSERT_EQ(tc->getRootNode()->getActiveState()->getId(), 1529456591410);

    SimpleSwitches::set(1, true);
    for (int i = 0; i < 10; ++i) {
        tc->stepEngine();
        ASSERT_GT(CounterClass::called, curCount);
        curCount = CounterClass::called;
    }
}
}
}