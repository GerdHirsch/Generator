/*
 * TestMockTypes.h
 *
 *  Created on: 03.12.2013
 *      Author: Gerd
 */

#ifndef TESTMOCKTYPES_H_
#define TESTMOCKTYPES_H_

#include <Generator/BaseType.h>
#include "LPC214xTypes.h"
#include "LPC213xTypes.h"

namespace TestMock {
// TestMock = Cusomization der Customized Produktlinie



// ein Template das Templates generiert!
// Die Membertemplates werden mit den TemplateArgumenten spezialisiert!
// funktioniert so als BaseTypeSelector für Contexte,
// die verkettet werden, nicht wegen  rekursion
// weiterer parameter wird benötigt
template<typename Context, typename ToSubstituteContext, typename Base>
struct ConfigurableBaseTypeSelector{

	template<typename Next, typename Current>
	struct MyBaseType{
		typedef typename Next::template BaseType<Current>::type type;
	};
	template<typename Next>
	struct MyBaseType<Next, ToSubstituteContext>{
		typedef Base type;
	};
	template<typename CurrentContext>
	struct BaseType{
		typedef typename MyBaseType<Context, CurrentContext>::type type;
	};
};

struct Base;
//Problem: die Selectoren sind fest mit diesem Tempate verknüpft
template<class CurrentContext>
struct BaseType4x
{
	typedef typename Test4x::BaseType<CurrentContext>::type type;
};
template<class CurrentContext>
struct BaseType3x{
	typedef typename Test3x::BaseType<CurrentContext>::type type;
};
template<>
struct BaseType4x<Testxx::LPC21x1>{
	typedef Base type;
};

template<>
struct BaseType3x<Testxx::LPC21x1>{
	typedef Base type;
};

typedef ConfigurableBaseTypeSelector<Test4x::LPC2146, Testxx::LPC21x1, TestMock::Base>
	BaseTypeTemplate;
struct Base : Generator::SelectorBase<Testxx::Base>{
	static char const* name(){ return "Mock::Base";}
};
struct LPC2141 : Generator::SelectorBase<Test4x::LPC2141, BaseType4x>{
	static char const* name(){ return "Mock::LPC2141";}
};
struct LPC2142 : Generator::SelectorBase<Test4x::LPC2142, BaseType4x>{
	static char const* name(){ return "Mock::LPC2142";}
};
struct LPC2144 : Generator::SelectorBase<Test4x::LPC2144, BaseType4x>{
	static char const* name(){ return "Mock::LPC2144";}
};
struct LPC2146 : Generator::SelectorBaseNeu<Test4x::LPC2146, BaseTypeTemplate>{
	static char const* name(){ return "Mock::LPC2146";}
};
//struct LPC2146 : Generator::SelectorBase<Test4x::LPC2146, BaseType4x>{
//	static char const* name(){ return "Mock::LPC2146";}
//};
struct LPC2148 : Generator::SelectorBase<Test4x::LPC2148, BaseType4x>{
	static char const* name(){ return "Mock::LPC2148";}
};

struct LPC2131 : Generator::SelectorBase<Test3x::LPC2131, BaseType3x>{
	static char const* name(){ return "Mock::LPC2131";}
};
struct LPC2132 : Generator::SelectorBase<Test3x::LPC2132, BaseType3x>{
	static char const* name(){ return "Mock::LPC2132";}
};
struct LPC2134 : Generator::SelectorBase<Test3x::LPC2134, BaseType3x>{
	static char const* name(){ return "Mock::LPC2134";}
};
struct LPC2136 : Generator::SelectorBase<Test3x::LPC2136, BaseType3x>{
	static char const* name(){ return "Mock::LPC2136";}
};
struct LPC2138 : Generator::SelectorBase<Test3x::LPC2138, BaseType3x>{
	static char const* name(){ return "Mock::LPC2138";}
};


struct Traits{
	static char const* name(){ return "Mock::Traits";}
};
struct Register{
	static char const* name(){ return "Mock::Register";}
};

} // end namespace TestMock



#endif /* TESTMOCKTYPES_H_ */
