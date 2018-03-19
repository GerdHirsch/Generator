#include "CustomizedContexts.h"
#include "TestMockTypes.h"

using namespace Generator;

void CustomizedContexts::PrintContext(){
	typedef TestMock::LPC2146 Context4x;
	typedef TestMock::LPC2138 Context3x;

	std::cout  << std::endl << "4x" << std::endl;
	PrintBaseType<Context4x>::print(std::cout);

	std::cout << "3x" << std::endl;
	PrintBaseType<Context3x>::print(std::cout);
}



