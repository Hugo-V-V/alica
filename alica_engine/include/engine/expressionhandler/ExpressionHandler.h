/*
 * ExpressionHandler.h
 *
 *  Created on: Aug 26, 2014
 *      Author: Stefan Jakob
 */

#ifndef EXPRESSIONHANDLER_H_
#define EXPRESSIONHANDLER_H_

namespace alica
{
	class RunningPlan;
	class Plan;
	class Condition;
	class Transition;
	class IConditionCreator;
	class AlicaEngine;

	/**
	 * The ExpressionHandler attaches expressions and constraints to plans during start-up of the engine.
	 */
	class ExpressionHandler
	{
	public:
		ExpressionHandler(AlicaEngine* ae, IConditionCreator* cc);
		virtual ~ExpressionHandler();
		void attachAll();
//		void dummyConstraint(ConstraintDescriptor cd, RunningPlan* rp);
		bool dummyTrue(RunningPlan* rp);
		bool dummyFalse(RunningPlan* rp);

	protected:
		IConditionCreator* conditionCreator;
		AlicaEngine* ae;
//		void attachPlanConditions(Plan* p, T exprType, T consType);
//		void attachTransConditions(Transition* t, T exprType, T consType);
//		void attachConstraint(Condition* c, T t);


	};

} /* namespace alica */

#endif /* EXPRESSIONHANDLER_H_ */