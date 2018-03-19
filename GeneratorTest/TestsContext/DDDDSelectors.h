#ifndef DDDDSELECTORS_H_
#define DDDDSELECTORS_H_

#include <Generator/BaseType.h>

namespace DDS
{
    struct S1 : Generator::SelectorBase<>{
    	static const char* name(){ return "DDS::S1";}};
    struct S2 : Generator::SelectorBase<>{
    	static const char* name(){ return "DDS::S2";}};
    struct S3 : Generator::SelectorBase<>{
    	static const char* name(){ return "DDS::S3";}};

    // Selectoren für Vererbungshierarchien
    struct Selector01 : Generator::SelectorBase<>{
    	static const char* name(){ return "DDS::Selector01";}};
    struct Selector02 : Generator::SelectorBase<Selector01>{
    	static const char* name(){ return "DDS::Selector02";}};

    struct Selector11 : Generator::SelectorBase<>{
    	static const char* name(){ return "DDS::Selector11";}};
    struct Selector12 : Generator::SelectorBase<Selector11>{
    	static const char* name(){ return "DDS::Selector12";}};
}
#endif /* DDDDSELECTORS_H_ */
