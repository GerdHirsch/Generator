/*
 * BaseTypeTest.cpp
 *
 *  Created on: 04.03.2012
 *      Author: Gerd
 */

#include <Generator/GeneratorTestHelper.h>
#include <Generator/Printers.h>
#include <iostream>

#include "BaseTypeTest.h"
#include "Custom/Types.h"
#include "Radio/Types.h"
#include "LPC214xTypes.h"
#include "TestMockTypes.h"

void BaseTypeTest::RadioAdvanced_RadioAdvanced(){
	char const* message = "Radio::BaseType<Radio::RadioAdvanced>::type";

	typedef Radio::RadioAdvanced Selector;
	typedef Selector::BaseType<Radio::RadioAdvanced>::type ResultType;
	typedef Radio::RadioSimple ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}
void BaseTypeTest::CustomSimple_CustomSimple(){
	char const* message = "Custom::BaseType<Custom::RadioSimple>::type";

	typedef Custom::RadioSimple Selector;
	typedef Selector::BaseType<Custom::RadioSimple>::type ResultType;
	typedef Radio::RadioSimple ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}
void BaseTypeTest::CustomSimple_RadioSimple(){
	char const* message = "Custom::BaseType<Radio::RadioSimple>::type";

	typedef Custom::RadioSimple Selector;
	typedef Selector::BaseType<Radio::RadioSimple>::type ResultType;
	typedef Generator::SelectorDefault ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}

void BaseTypeTest::CustomAdvanced_CustomAdvanced(){
	char const* message = "Custom::BaseType<Radio::RadioAdvanced>::type";

	typedef Custom::RadioAdvanced Selector;

	typedef Selector::BaseType<Custom::RadioAdvanced>::type ResultType;
	typedef Radio::RadioAdvanced ExpectedType;
	Generator::TestTypeId::test<ExpectedType, ResultType>(message);

	typedef Selector::BaseType<ResultType>::type ResultType2;
	//typedef Custom::BaseType<ResultType>::type ResultType2;
	typedef Custom::RadioSimple ExpectedType2;
	Generator::TestTypeId::test<ExpectedType2, ResultType2>(message);

	typedef Selector::BaseType<ResultType2>::type ResultType3;
	typedef Radio::RadioSimple ExpectedType3;
	Generator::TestTypeId::test<ExpectedType3, ResultType3>(message);

	typedef Selector::BaseType<ResultType3>::type ResultType4;
	typedef Generator::SelectorDefault ExpectedType4;
	Generator::TestTypeId::test<ExpectedType4, ResultType4>(message);
}
void BaseTypeTest::CustomAdvanced_RadioAdvanced(){
	char const* message = "Custom::BaseType<Radio::RadioAdvanced>::type";

	typedef Custom::RadioAdvanced Selector;
	typedef Selector::BaseType<Radio::RadioAdvanced>::type ResultType;
	typedef Custom::RadioSimple ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}

void BaseTypeTest::LPC2144_LPC2144(){
	char const* message = "Selector::BaseType<Test4x::LPC2144>::type ResultType";

	typedef Test4x::LPC2144 Selector;
	typedef Selector::BaseType<Test4x::LPC2144>::type ResultType;

	//Generator::PrintBaseType<Selector>::print(std::cout);
	typedef Testxx::LPC21x4 ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}
void BaseTypeTest::LPC2144_LPC21x4(){
	char const* message = "Selector::BaseType<Testxx::LPC21x4>::type ResultType";

	typedef Test4x::LPC2144 Selector;
	typedef Selector::BaseType<Testxx::LPC21x4>::type ResultType;
//	typedef Test4x::BaseType<Testxx::LPC21x4>::type ResultType;
	typedef Test4x::LPC2142 ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}
void BaseTypeTest::LPC2144_LPC2142(){
	char const* message = "Selector::BaseType<Test4x::LPC2146>::type ResultType";

	typedef Test4x::LPC2144 Selector;
	typedef Selector::BaseType<Test4x::LPC2142>::type ResultType;
	typedef Testxx::LPC21x2 ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}
void BaseTypeTest::LPC2142_LPC21x2(){
	char const* message = "Selector::BaseType<Testxx::LPC21x6>::type ResultType";

	typedef Test4x::LPC2142 Selector;
	typedef Selector::BaseType<Testxx::LPC21x2>::type ResultType;
	typedef Test4x::LPC2141 ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}



void BaseTypeTest::MockBaseTypeSelector(){
	char const* message = "Todo: TestMock::MockBaseTypeSelector<Test4x::LPC2148>";

//	typedef TestMock::BaseTypeSelector<TestMock::LPC2148> Selector;
	typedef TestMock::LPC2146 Selector;
	typedef Selector::BaseType<Test4x::LPC2146>::type ResultType;
	typedef Testxx::LPC21x6 ExpectedType;
//	typedef Test4x::LPC2148 ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}

void BaseTypeTest::MockSelectorLPC21x1(){
	char const* message = "ConfigurableBaseTypeSelector<Test4x::LPC2146, Testxx::LPC21x1, TestMock::Base>";

//	typedef TestMock::ConfigurableBaseTypeSelector<Test4x::LPC2146, Testxx::LPC21x1, TestMock::Base>
//		Selector;
	typedef TestMock::LPC2146 Selector;
	typedef Selector::BaseType<Testxx::LPC21x1>::type ResultType;
	typedef TestMock::Base ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}
void BaseTypeTest::MockSelectorLPC2141(){
	char const* message = "ConfigurableBaseTypeSelector<Test4x::LPC2146, Testxx::LPC21x1, TestMock::Base>";

//	typedef TestMock::ConfigurableBaseTypeSelector<Test4x::LPC2146, Testxx::LPC21x1, TestMock::Base> Selector;
	typedef TestMock::LPC2146 Selector;
	typedef Selector::BaseType<Test4x::LPC2141>::type ResultType;
	typedef Testxx::LPC21x1 ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}
void BaseTypeTest::MockSelectorLPC21x2(){
	char const* message = "ConfigurableBaseTypeSelector<Test4x::LPC2146, Testxx::LPC21x1, TestMock::Base>";

//	typedef TestMock::ConfigurableBaseTypeSelector<Test4x::LPC2146, Testxx::LPC21x1, TestMock::Base>
	typedef TestMock::LPC2146 Selector;
	typedef Selector::BaseType<Testxx::LPC21x2>::type ResultType;
	typedef Test4x::LPC2141 ExpectedType;

	Generator::TestTypeId::test<ExpectedType, ResultType>(message);
}

