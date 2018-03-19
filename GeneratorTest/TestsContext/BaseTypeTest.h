/*
 * BaseTypeTest.h
 *
 *  Created on: 04.03.2012
 *      Author: Gerd
 */

#ifndef BASETYPETEST_H_
#define BASETYPETEST_H_
#include "../GeneratorTestApp.h"

/*
 * diese Tests überprüfen den Zugriff auf using Generator::BaseType
 */
class BaseTypeTest : public CPPUNIT_NS::TestFixture {

	CPPUNIT_TEST_SUITE(BaseTypeTest);

		CPPUNIT_TEST(RadioAdvanced_RadioAdvanced);
		CPPUNIT_TEST(CustomSimple_CustomSimple);
		CPPUNIT_TEST(CustomSimple_RadioSimple);
		CPPUNIT_TEST(CustomAdvanced_CustomAdvanced);
		CPPUNIT_TEST(CustomAdvanced_RadioAdvanced);
		CPPUNIT_TEST(MockBaseTypeSelector);
		CPPUNIT_TEST(MockSelectorLPC21x1);
		CPPUNIT_TEST(MockSelectorLPC2141);
		CPPUNIT_TEST(MockSelectorLPC21x2);
		CPPUNIT_TEST(LPC2144_LPC2144);
		CPPUNIT_TEST(LPC2144_LPC21x4);
		CPPUNIT_TEST(LPC2144_LPC2142);
		CPPUNIT_TEST(LPC2142_LPC21x2);

	CPPUNIT_TEST_SUITE_END();
protected:
	void RadioAdvanced_RadioAdvanced();
	void CustomSimple_CustomSimple();
	void CustomSimple_RadioSimple();
	void CustomAdvanced_CustomAdvanced();
	void CustomAdvanced_RadioAdvanced();
	void MockBaseTypeSelector();
	void MockSelectorLPC21x1();
	void MockSelectorLPC2141();
	void MockSelectorLPC21x2();
	void LPC2144_LPC2144();
	void LPC2144_LPC21x4();
	void LPC2144_LPC2142();
	void LPC2142_LPC21x2();
};

#endif /* BASETYPETEST_H_ */
