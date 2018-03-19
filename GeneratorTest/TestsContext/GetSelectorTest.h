/*
 * GetSelectorTest.h
 *
 *  Created on: 12.12.2013
 *      Author: Gerd
 */

#ifndef GETSELECTORTEST_H_
#define GETSELECTORTEST_H_

#include "../GeneratorTestApp.h"

class GetSelectorTest : public CPPUNIT_NS::TestFixture{
	CPPUNIT_TEST_SUITE(GetSelectorTest);
		// 1 Selector
		CPPUNIT_TEST(CSContext);
		CPPUNIT_TEST(DDContext);

	CPPUNIT_TEST_SUITE_END();
protected:
	void CSContext();
	void DDContext();
};

#endif /* GETSELECTORTEST_H_ */
