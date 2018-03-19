#ifndef __LPC214x_TYPES_H__
#define __LPC214x_TYPES_H__
namespace LPC214x
{
    struct LPC2141 : Generator::SelectorBase<>{
        static const char* name(){ return "LPC214x::LPC2141"; }
    };
    struct LPC2142 : Generator::SelectorBase<LPC2141>{
        static const char* name(){ return "LPC214x::LPC2142"; }
    };
    struct LPC2144 : Generator::SelectorBase<LPC2142>{
        static const char* name(){ return "LPC214x::LPC2144"; }
    };
    struct LPC2146 : Generator::SelectorBase<LPC2144>{
        static const char* name(){ return "LPC214x::LPC2146"; }
    };
    struct LPC2148 : Generator::SelectorBase<LPC2146>{
        static const char* name(){ return "LPC214x::LPC2148"; }
    };
}

#endif /* __LPC214x_TYPES_H__ */
