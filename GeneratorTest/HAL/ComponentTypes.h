#ifndef __HAL_COMPONENT_TYPES_H__
#define __HAL_COMPONENT_TYPES_H__

#include <Generator/BaseType.h>

namespace HAL
{
    template<   class Board, class Prozessor, 
                class ConfigRep = Generator::EmptyRepository >
    struct PlatformConfigurationRepository : ConfigRep {
        typedef PlatformConfigurationRepository<Board, Prozessor, ConfigRep> Platform;
        typedef Board board_type;
        typedef Prozessor prozessor_type;

        static const char* name(){ return "HAL::PlatformConfigurationRepository";}
   };

    struct PinConnectBlock;
    struct GPIO
    {
    	static const char* name(){ return "HAL::GPIO";}
    };
    struct AD
    {
    	static const char* name(){ return "HAL::AD";}
    };
    struct ADC
    {
    	static const char* name(){ return "HAL::ADC";}
    };
}
namespace Generator{
template<> struct name<HAL::PinConnectBlock>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::PinConnectBlock";
	}
};
}
#endif //__HAL_COMPONENT_TYPES_H__
