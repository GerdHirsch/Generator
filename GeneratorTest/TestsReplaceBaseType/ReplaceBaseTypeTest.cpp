#include <Generator/GeneratorTestHelper.h>
#include <Generator/Printers.h>
#include <Generator/IfThenElse.h>

#include <iostream>
//#include <type_traits>

#include "ReplaceBaseTypeTest.h"
#include "Custom/Types.h"
#include "Radio/Types.h"

using namespace Generator;

namespace Mock{
// Selector wird vor RadioSimple eingefügt
struct Base : Generator::SelectorBase<Radio::RadioSimple>{};

struct Context :
	Generator::replaceBaseType<Radio::RadioLuxus, Radio::RadioSimple, Mock::Base>
{};
//delegate
template<class CurrentSelector>
struct BaseType : Context:: template BaseType<CurrentSelector>{};

} // end namespace Mock
//==================================================================
void ReplaceBaseTypeTest::ReplaceBaseTypeforRadioSimple(){

	struct Context : replaceBaseType<Radio::RadioLuxus, Radio::RadioSimple, Mock::Base>
	{};

	typedef Context::BaseType<Radio::RadioLuxus>::type ResultType;
	typedef Radio::RadioAdvanced ExpectedType;
	Generator::TestTypeId::test<ExpectedType, ResultType>("Luxus -> Advanced");

	typedef Context::BaseType<ExpectedType>::type ResultType2;
	typedef Mock::Base ExpectedType2;
	Generator::TestTypeId::test<ExpectedType2, ResultType2>("Advanced -> Base");

}
//==================================================================
