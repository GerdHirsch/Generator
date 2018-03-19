/*
 * GetSelectorTest.cpp
 *
 *  Created on: 12.12.2013
 *      Author: Gerd
 */

#include <TestsContext/GetSelectorTest.h>
using namespace Generator;

void GetSelectorTest::DDContext(){
	typedef Radio::RadioSimple expected1;
	typedef LPC214x::LPC2141 expected2;

	typedef DD<expected1, expected2> ToTest;

	typedef ToTest::getSelector<1>::type result1;
	typedef ToTest::getSelector<2>::type result2;

	Generator::TestTypeId::test<expected1, result1>("DD::getSelector<1>");
	Generator::TestTypeId::test<expected2, result2>("DD::getSelector<2>");
}

void GetSelectorTest::CSContext(){
	typedef LPC214x::LPC2141 expected;

	typedef CS<HAL::GPIO, expected> ToTest;

	typedef ToTest::getSelector<>::type result;

	Generator::TestTypeId::test<expected, result>("CS::getSelector<>");
}
