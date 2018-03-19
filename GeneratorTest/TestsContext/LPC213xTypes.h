/*
 * LPC213xTypes.h
 *
 *  Created on: 02.12.2013
 *      Author: Gerd
 */

#ifndef LPC213XTYPES_H_
#define LPC213XTYPES_H_

#include "LPC21xxTypes.h"

namespace Test3x {
// Test3x = customized Produktlinie
template<class CurrentContext>
struct BaseType{
	typedef typename CurrentContext::base_type type;
};

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
} // end namespace Test3x


#endif /* LPC213XTYPES_H_ */
