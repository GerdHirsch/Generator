#ifndef __LPC21XX_TYPES_H__
#define __LPC21XX_TYPES_H__

#include <Generator/BaseType.h>

namespace Testxx {
// Customized Contexte
// Testxx = Produktlinie

using Generator::BaseType;

// the general Base, defining all general behaviour
struct Base : Generator::SelectorBase<>{
	static char const* name(){return "Testxx::Base"; }};
struct LPC21x1 : Generator::SelectorBase<Base>{
	static char const* name(){return "Testxx::LPC21x1"; }};
struct LPC21x2 : Generator::SelectorBase<LPC21x1>{
	static char const* name(){return "Testxx::LPC21x2"; }};
struct LPC21x4 : Generator::SelectorBase<LPC21x2>{
	static char const* name(){return "Testxx::LPC21x4"; }};
struct LPC21x6 : Generator::SelectorBase<LPC21x4>{
	static char const* name(){return "Testxx::LPC21x6"; }};
struct LPC21x8 : Generator::SelectorBase<LPC21x6>{
	static char const* name(){return "Testxx::LPC21x8"; }};

} // end namespace Testxx
#endif /* __LPC21XX_TYPES_H__ */
