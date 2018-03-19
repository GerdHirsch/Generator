#ifndef __CUSTOM_TYPES_H_
#define __CUSTOM_TYPES_H_

#include <Generator/BaseType.h>
#include <Radio/Types.h>

namespace Custom{

    //forward Deklarations
    struct RadioSimple;
    struct RadioAdvanced;
    struct RadioLuxus;


    template<class CurrentContext>
    struct BaseType : Radio::BaseType<CurrentContext>{};

    template<>
    struct BaseType<Radio::RadioAdvanced>{
        typedef RadioSimple type;
    };
    template<>
    struct BaseType<Radio::RadioLuxus>{
        typedef RadioAdvanced type;
    };
    //Selectors
    struct RadioSimple : Generator::SelectorBase<Radio::RadioSimple>{
    	static const char* name(){ return "Custom::RadioSimple";}
    };
    struct RadioAdvanced : Generator::SelectorBase<Radio::RadioAdvanced, BaseType>{
        static const char* name(){ return "Custom::RadioAdvanced";}
    };

    struct RadioLuxus : Generator::SelectorBase<Radio::RadioLuxus, BaseType>{
        static const char* name(){ return "Custom::RadioLuxus";}
    };
//    struct RadioLuxus : Generator::CustomSelectorBase<BaseType, Radio::RadioLuxus>{
//        static const char* name(){ return "Custom::RadioLuxus";}
//    };
} // namespace Custom

#endif /* __CUSTOM_TYPES_H_ */
