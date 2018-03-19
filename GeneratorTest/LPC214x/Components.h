#ifndef __LPC214X_COMPONENTS_H__
#define __LPC214X_COMPONENTS_H__

#include <Generator/BaseType.h>
#include <Generator/GeneratorTestHelper.h>

#include <HAL/ComponentTypes.h>
#include <LPC214x/Types.h>

namespace LPC214x{
	//-----------------------------------------------------------------
	template<class Selector, class Prozessor, class ConfigRep>
	struct LPC2141HAL : Generator::TestImpl<Selector, Prozessor, ConfigRep>{

		//using namespace Generator;

		typedef typename Generator::Create<Generator::CS<HAL::PinConnectBlock, Prozessor>, ConfigRep >
			::type PinConnectBlock;
		typedef typename Generator::Create<Generator::CS<Generator::NO<HAL::GPIO, 0>, Prozessor>, ConfigRep>
			::type GPIO_0;
	};
	//-----------------------------------------------------------------
	template<class Selector, class Prozessor, class ConfigRep>
	struct LPC2144HAL : LPC2141HAL<Selector, Prozessor, ConfigRep>{

		//using namespace Generator;

		typedef typename Generator::Create<Generator::CS<Generator::NO<HAL::GPIO, 1>, Prozessor>, ConfigRep>
			::type GPIO_1;
	};
} //namespace LPC214x

namespace Generator
{
	//PinConnectBlock, LPC2141
	template<class Origin, class ConfigRepository>
	struct Component<
		CS<HAL::PinConnectBlock, LPC214x::LPC2141>,
		Origin,
		ConfigRepository
					>
	{
		typedef TestImpl< CS<HAL::PinConnectBlock, LPC214x::LPC2141>,
							Origin, ConfigRepository> type;
	};
	//PinConnectBlock, LPC2144
	template<class Origin, class ConfigRepository>
	struct Component<
		CS<HAL::PinConnectBlock, LPC214x::LPC2144>,
		Origin,
		ConfigRepository
					>
	{
		typedef TestImpl< CS<HAL::PinConnectBlock, LPC214x::LPC2144>,
							Origin, ConfigRepository> type;
	};
	//GPIO_0, LPC2141
	template<class Origin, class ConfigRepository>
	struct Component<
		CS<NO<HAL::GPIO, 0>, LPC214x::LPC2141>,
		Origin,
		ConfigRepository
					>
	{
		typedef TestImpl< CS<NO<HAL::GPIO, 0>, LPC214x::LPC2141>,
							Origin, ConfigRepository> type;
	};
	//GPIO_1, LPC2144
	template<class Origin, class ConfigRepository>
	struct Component<
		CS<NO<HAL::GPIO, 1>, LPC214x::LPC2144>,
		Origin,
		ConfigRepository
					>
	{
		typedef TestImpl< CS<NO<HAL::GPIO, 1>, LPC214x::LPC2144>,
							Origin, ConfigRepository> type;
	};
	//ADC_1, LPC2144
	template<class Origin, class ConfigRepository>
	struct Component<
		CS<NO<HAL::ADC, 1>, LPC214x::LPC2144>,
		Origin,
		ConfigRepository
					>
	{
		typedef TestImpl< CS<NO<HAL::ADC, 1>, LPC214x::LPC2144>,
							Origin, ConfigRepository> type;
	};

	//Aggregate, LPC2141
    template<class Origin, class ConfigRepository>
    struct Component<
    	LPC214x::LPC2141,
        Origin,
        ConfigRepository
                    >
    {
        typedef LPC214x::LPC2141HAL< LPC214x::LPC2141, Origin, ConfigRepository>
        	type;
    };
	//Aggregate, LPC2144
    template<class Origin, class ConfigRepository>
    struct Component<
    	LPC214x::LPC2144,
        Origin,
        ConfigRepository
                    >
    {
        typedef LPC214x::LPC2144HAL< LPC214x::LPC2144, Origin, ConfigRepository>
        	type;
    };
} // namespace Generator

#endif //__LPC214X_COMPONENTS_H__
