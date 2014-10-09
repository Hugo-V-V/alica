/*
 * TestConstraintCreator.h
 *
 *  Created on: Oct 8, 2014
 *      Author: Stefan Jakob
 */

#ifndef ALICA_ALICA_TEST_SRC_TESTCONSTRAINTCREATOR_H_
#define ALICA_ALICA_TEST_SRC_TESTCONSTRAINTCREATOR_H_

#include <engine/IConstraintCreator.h>

namespace alica
{

	class TestConstraintCreator : public IConstraintCreator
	{
	public:
		TestConstraintCreator();
		virtual ~TestConstraintCreator();
		shared_ptr<BasicConstraint> createConstraint(long constraintConfId);
	};

} /* namespace alica */

#endif /* ALICA_ALICA_TEST_SRC_TESTCONSTRAINTCREATOR_H_ */