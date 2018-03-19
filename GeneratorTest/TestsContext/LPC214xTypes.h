/*
 * LPC214xTypes.h
 *
 *  Created on: 02.12.2013
 *      Author: Gerd
 */

#ifndef LPC214XTYPES_H_
#define LPC214XTYPES_H_

#include <Generator/BaseType.h>
#include "LPC21xxTypes.h"
namespace Generator{


}//end namespace Generator

namespace Test4x {
// Test4x = customized Produktlinie

template<class CurrentContext>
struct BaseType : Testxx::BaseType<CurrentContext>{};

// Selectors
struct LPC2141 : Generator::SelectorBase<Testxx::LPC21x1>{
	static char const* name(){return "Test4x::LPC2141"; }};
struct LPC2142 : Generator::SelectorBase<Testxx::LPC21x2, BaseType>{
	static char const* name(){return "Test4x::LPC2142"; }};
struct LPC2144 : Generator::SelectorBase<Testxx::LPC21x4, BaseType>{
	static char const* name(){return "Test4x::LPC2144"; }};
struct LPC2146 : Generator::SelectorBase<Testxx::LPC21x6, BaseType>{
	static char const* name(){return "Test4x::LPC2146"; }};
struct LPC2148 : Generator::SelectorBase<Testxx::LPC21x8, BaseType>{
	static char const* name(){return "Test4x::LPC2148"; }};

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
} // end namespace Test4x



#endif /* LPC214XTYPES_H_ */
