#ifndef SELECTORS_H_
#define SELECTORS_H_

#include <Generator/BaseType.h>

namespace S
{
    struct S1 : Generator::SelectorBase<>{
    	static const char* name(){ return "S::S1";}};
    struct S2 : Generator::SelectorBase<>{
    	static const char* name(){ return "S::S2";}};
    struct S3 : Generator::SelectorBase<>{
    	static const char* name(){ return "S::S3";}};

    // Selectoren für Vererbungshierarchien
    struct Selector01 : Generator::SelectorBase<>{
    	static const char* name(){ return "S::Selector01";}};
    struct Selector02 : Generator::SelectorBase<Selector01>{
    	static const char* name(){ return "S::Selector02";}};

    struct Selector11 : Generator::SelectorBase<>{
    	static const char* name(){ return "S::Selector11";}};
    struct Selector12 : Generator::SelectorBase<Selector11>{
    	static const char* name(){ return "S::Selector12";}};
}


// Customized Contexte
// Testxx = Produktlinie
namespace Testxx {

template <class CurrentContext>
struct BaseType : Generator::BaseType<CurrentContext>{};

// the general Base, defining all general behaviour
struct Base : Generator::SelectorBase<>{
	static char const* name(){return "Testxx::Base"; }
};
struct LPC21x1 : Generator::SelectorBase<Base>{
	static char const* name(){return "Testxx::LPC21x1"; }
};
struct LPC21x2 : Generator::SelectorBase<LPC21x1>{
	static char const* name(){return "Testxx::LPC21x2"; }
};
struct LPC21x4 : Generator::SelectorBase<LPC21x2>{
	static char const* name(){return "Testxx::LPC21x4"; }
};
struct LPC21x6 : Generator::SelectorBase<LPC21x4>{
	static char const* name(){return "Testxx::LPC21x6"; }
};
struct LPC21x8 : Generator::SelectorBase<LPC21x6>{
	static char const* name(){return "Testxx::LPC21x8"; }
};

}

// Test4x = customized Produktlinie von Testxx
namespace Test4x {

//Primary Template, MetaFunction Forwarding to BaseProduct
template<class CurrentContext>
struct BaseType : Testxx::BaseType<CurrentContext>{};

struct LPC2141 : Generator::SelectorBase<Testxx::LPC21x1>{
	static char const* name(){return "Test4x::LPC2141"; }
};
struct LPC2142 : Generator::SelectorBase<Testxx::LPC21x2, BaseType>{
	static char const* name(){return "Test4x::LPC2142"; }
};
struct LPC2144 : Generator::SelectorBase<Testxx::LPC21x4, BaseType>{
	static char const* name(){return "Test4x::LPC2144"; }
};
struct LPC2146 : Generator::SelectorBase<Testxx::LPC21x6, BaseType>{
	static char const* name(){return "Test4x::LPC2146"; }
};
struct LPC2148 : Generator::SelectorBase<Testxx::LPC21x8, BaseType>{
	static char const* name(){return "Test4x::LPC2148"; }
};

template<>
struct BaseType<Testxx::LPC21x2>{
	typedef LPC2141 type;
};
template<>
struct BaseType<Testxx::LPC21x4>{
	typedef LPC2142 type;
};
template<>
struct BaseType<Testxx::LPC21x6>{
	typedef LPC2144 type;
};
template<>
struct BaseType<Testxx::LPC21x8>{
	typedef LPC2146 type;
};
}

// Test3x = customized Produktlinie
namespace Test3x {

//Primary Template, MetaFunction Forwarding to BaseProduct
template<class CurrentContext>
struct BaseType : Testxx::BaseType<CurrentContext>{};

struct LPC2131 : Generator::SelectorBase<Testxx::LPC21x1>{
	static char const* name(){return "Test3x::LPC2131"; }
};
struct LPC2132 : Generator::SelectorBase<Testxx::LPC21x2, BaseType>{
	static char const* name(){return "Test3x::LPC2132"; }
};
struct LPC2134 : Generator::SelectorBase<Testxx::LPC21x4, BaseType>{
	static char const* name(){return "Test3x::LPC2134"; }
};
struct LPC2136 : Generator::SelectorBase<Testxx::LPC21x6, BaseType>{
	static char const* name(){return "Test3x::LPC2136"; }
};
struct LPC2138 : Generator::SelectorBase<Testxx::LPC21x8, BaseType>{
	static char const* name(){return "Test3x::LPC2138"; }
};

template<>
struct BaseType<Testxx::LPC21x2>{
	typedef LPC2131 type;
};
template<>
struct BaseType<Testxx::LPC21x4>{
	typedef LPC2132 type;
};
template<>
struct BaseType<Testxx::LPC21x6>{
	typedef LPC2134 type;
};
template<>
struct BaseType<Testxx::LPC21x8>{
	typedef LPC2136 type;
};
}

// TestMock = Cusomization der Customized Produktlinie
namespace TestMock {

struct Traits{
	static char const* name(){ return "Mock::Traits";}
};
struct Register{
	static char const* name(){ return "Mock::Register";}
};

struct Base;

template<class CurrentContext>
struct BaseType4x : Test4x::BaseType<CurrentContext>{};

template<class CurrentContext>
struct BaseType3x : Test3x::BaseType<CurrentContext>{};

//Spezialisierungen
template<>
struct BaseType4x<Testxx::LPC21x1>{
	typedef Base type;
};

template<>
struct BaseType3x<Testxx::LPC21x1>{
	typedef Base type;
};

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
struct LPC2146 : Generator::SelectorBase<Test4x::LPC2146, BaseType4x>{
	static char const* name(){ return "Mock::LPC2146";}
};
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
}

#endif /* SELECTORS_H_ */
