/*
 * DDComponentTest.h
 *
 *  Created on: 17.12.2013
 *      Author: Gerd
 */

#ifndef DDCOMPONENTTEST_H_
#define DDCOMPONENTTEST_H_
#include "../GeneratorTestApp.h"



class DDComponentTest : public CPPUNIT_NS::TestFixture  {
	CPPUNIT_TEST_SUITE(DDComponentTest);

//	CPPUNIT_T<>EST(printContext);
	CPPUNIT_TEST(S1_Selector01);
	CPPUNIT_TEST(S2_Selector12);
	CPPUNIT_TEST(Selector02_S2);

	CPPUNIT_TEST_SUITE_END();
protected:
	// test DD<SelectorDefault, SelectorDefault>
	void S1_Selector01();
	// test DD<S1, SelectorDefault>
	void S2_Selector12();
	// test DD<SelectorDefault, S1>
	void Selector02_S2();

	void printContext();
};

#endif /* DDCOMPONENTTEST_H_ */
