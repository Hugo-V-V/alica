#pragma once

#include <engine/IBehaviourCreator.h>

#include <functional>
#include <unordered_map>

namespace alica
{
class BasicBehaviour;
}

namespace alica::test
{
class TestBehaviourCreator : public alica::IBehaviourCreator
{
public:
    /**
     * Requires a reference the autogenerated behaviour creator of
     * your application.
     * @param defaultBehaviourCreator Reference to your applications behaviour
     * creator
     */
    explicit TestBehaviourCreator(alica::IBehaviourCreator& defaultBehaviourCreator);
    ~TestBehaviourCreator() override = default;

    /**
     * The default interface, used by the ALICA Engine to retrieve
     * an instance of a behaviour.
     * @param behaviourID Id of the requested behaviour.
     * @return std::shared_ptr<BasicBehaviour> pointing to the requested behaviour.
     */
    std::shared_ptr<BasicBehaviour> createBehaviour(int64_t behaviourID) override;

    /**
     * Allows you specify the class that should be used to construct the BasicBehaviour
     * object for the given behaviourID.
     * Note: The passed class must inherit from BasicBehaviour and must be default-constructable.
     * @tparam T The class that should be instantiated for the given behaviourID.
     * @param behaviourID The ID of the behaviour, whose instantiation should be altered to use class T.
     */
    template <class T>
    void setBehaviourMockUp(int64_t behaviourID);

private:
    std::unordered_map<int64_t, std::function<std::shared_ptr<BasicBehaviour>()>> _behaviourCreateFunctions;
    IBehaviourCreator& _defaultBehaviourCreator;
};

template <class T>
void TestBehaviourCreator::setBehaviourMockUp(int64_t behaviourID)
{
    _behaviourCreateFunctions[behaviourID] = []() -> std::shared_ptr<BasicBehaviour> { return std::make_shared<T>(); };
}
} // namespace alica::test
