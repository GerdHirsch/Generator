#ifndef __RADIO_TYPES_H__
#define __RADIO_TYPES_H__

#include <Generator/BaseType.h>

namespace Radio
{
//	template<class CurrentContext>
//	struct BaseType : Generator::BaseType<CurrentContext>{};

	using Generator::BaseType;

    struct RadioSimple : Generator::SelectorBase<>{
       	static const char* name(){ return "Radio::RadioSimple";}};
    struct RadioAdvanced : Generator::SelectorBase<RadioSimple>{
    	static const char* name(){ return "Radio::RadioAdvanced";}};
    struct RadioLuxus : Generator::SelectorBase<RadioAdvanced>{
    	static const char* name(){ return "Radio::RadioLuxus";}};

    struct Receiver;
    struct Amplifier{
    	static const char* name(){ return "Radio::Amplifier";}};
    struct Verkehrsfunk{
    	static const char* name(){ return "Radio::Verkehrsfunk";}};

} //namespace Radio

namespace Generator{
template<> struct name<Radio::Receiver>{
	template<class OStream>
	static void print(OStream& os){
		os << "Radio::Receiver";
	}
};
} //namespace Generator
#endif //__RADIO_TYPES_H__
