/*
 * DDComponentTest.cpp
 *
 *  Created on: 17.12.2013
 *      Author: Gerd
 */

#include "DDComponentTest.h"
#include "DDTestComponents.h"

using namespace Generator;

//==================================================================
void DDComponentTest::printContext(){
	//typedef DD<DDS::S1, DDS::Selector12> Origin;
	//Vererbungshierarchien
	typedef DD<DDS::Selector02, DDS::Selector12> Context;

	PrintBaseType<Context>::print(std::cout);

}//==================================================================
void DDComponentTest::S1_Selector01(){
	typedef DD<DDS::S1, DDS::Selector01> Origin;
	typedef DD<Generator::SelectorDefault, Generator::SelectorDefault> Selector;

	typedef Create<Origin>::type Result;
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
}
void DDComponentTest::S2_Selector12(){
	typedef DD<DDS::Selector01, DDS::S2> Origin;
	typedef DD<DDS::Selector01, Generator::SelectorDefault> Selector;

	typedef Create<Origin>::type Result;
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
}
void DDComponentTest::Selector02_S2(){
	typedef DD<DDS::S1, DDS::Selector12> Origin;
	typedef DD<Generator::SelectorDefault, DDS::Selector11> Selector;

	typedef Create<Origin>::type Result;
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
}

