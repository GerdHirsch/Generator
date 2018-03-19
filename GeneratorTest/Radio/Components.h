#ifndef __RADIO_COMPONENTS_H__
#define __RADIO_COMPONENTS_H__

#include <Generator/BaseType.h>
#include <Generator/GeneratorTestHelper.h>

#include <LPC214x/Types.h>
#include <Radio/Types.h>
#include <Application/Types.h>

namespace Radio
{
//---------------------------------------------------------------------
// Aggregate Implementations    
    template<class Selector, class RadioType, class ConfigRep>
    struct RadioSimpleAggregate : Generator::TestImpl<Selector, RadioType, ConfigRep>
    {
        typedef Generator::TestImpl<Selector, RadioType, ConfigRep> base_type;
        
        typedef typename Generator::Create<
            Generator::CS<App::HMI, RadioType>, 
            ConfigRep
            >
        ::type HMI;

        typedef typename Generator::Create<
            Generator::CS<Radio::Receiver, RadioType>, 
            ConfigRep
            >
        ::type Receiver;

        typedef typename Generator::Create<
            Generator::CS<Radio::Amplifier, RadioType>, 
            ConfigRep
            >
        ::type Amplifier;

//        static void print(){
//            std::cout << "RadioSimpleAggregate:";
//            base_type::print();
//            std::cout << "----------------------" << std::endl;
//            std::cout << "HMI:";
//            HMI::print();
//            std::cout << "----------------------" << std::endl;
//            std::cout << "Reveiver:";
//            Receiver::print();
//            std::cout << "----------------------" << std::endl;
//            std::cout << "Amplifier:";
//            Amplifier::print();
//
//        }
    };
    template<class Selector, class RadioType, class ConfigRep>
    struct RadioAdvancedAggregate : RadioSimpleAggregate<Selector, RadioType, ConfigRep>
    {
        typedef RadioSimpleAggregate<Selector, RadioType, ConfigRep> base_type;
        
        typedef typename Generator::Create<
            Generator::CS<Radio::Verkehrsfunk, RadioType>, 
            ConfigRep
            >
        ::type Verkehrsfunk;

//        static void print(){
//            std::cout << "RadioAdvancedAggregate:";
//            base_type::print();
//            std::cout << "----------------------" << std::endl;
//            std::cout << "Verkehrsfunk:";
//            Verkehrsfunk::print();
//        }
    };
//---------------------------------------------------------------------
// ComponentImplementations
    template<class Selector, class RadioType, class ConfigRep>
    struct RadioHMI : Generator::TestImpl<Selector, RadioType, ConfigRep>
    {
        typedef Generator::TestImpl<Selector, RadioType, ConfigRep> base_type;

        typedef typename ConfigRep::Platform::board_type board_type;
        typedef typename ConfigRep::Platform::prozessor_type prozessor_type;

        typedef typename Generator::Create<
            Generator::DD<
                RadioType, 
                Generator::CS<board_type, prozessor_type> >,
                ConfigRep
                >
        ::type HMIAdapter;
        
//        static void print(){
//            std::cout << "RadioHMI:";
//            base_type::print();
//            std::cout << "----------------------" << std::endl;
//            std::cout << "HMIAdapter:";
//            HMIAdapter::print();
//
//        }
    };
    template<class Selector, class Origin, class ConfigRep>
    struct RadioReceiver : Generator::TestImpl<Selector, Origin, ConfigRep>
    {
        typedef Generator::TestImpl<Selector, Origin, ConfigRep> base_type;

        typedef typename ConfigRep::Platform::board_type board_type;
        typedef typename ConfigRep::Platform::prozessor_type prozessor_type;

        typedef typename Generator::Create<
            Generator::DD<
                Origin, 
                Generator::CS<board_type, prozessor_type> >,
                ConfigRep
                >
        ::type ReceiverAdapter;
        
//        static void print(){
//            std::cout << "RadioReceiver:";
//            base_type::print();
//            std::cout << "----------------------" << std::endl;
//            std::cout << "ReceiverAdapter:";
//            ReceiverAdapter::print();
//        }
    };
}

namespace Generator
{
//=====================================================================    
// Simple Aggregate
    template<class Origin, class ConfigRep>
    struct Component<
        Radio::RadioSimple, 
        Origin,
        ConfigRep
                    >
    {
        typedef Radio::RadioSimpleAggregate< 
            Radio::RadioSimple, 
            Origin,
            ConfigRep
            > type;
    };
// Advanced Aggregate
    template<class Origin, class ConfigRep>
    struct Component<
        Radio::RadioAdvanced, 
        Origin,
        ConfigRep
                    >
    {
        typedef Radio::RadioAdvancedAggregate< 
            Radio::RadioAdvanced, 
            Origin,
            ConfigRep
            > type;
    };
    // Radio Adapter
        template<class Origin, class ConfigRepository>
        struct Component<
            DD<
                Radio::RadioSimple,
                CS<Boards::Board1, LPC214x::LPC2141> >,
            Origin,
            ConfigRepository
                        >
        {
            typedef TestImpl<
                DD<
                    Radio::RadioSimple,
                    CS<Boards::Board1, LPC214x::LPC2141> >,
                Origin, ConfigRepository
                > type;
        };
        template<class Origin, class ConfigRepository>
        struct Component<
            DD<
                Radio::RadioLuxus,
                CS<Boards::Board1, LPC214x::LPC2144> >,
            Origin,
            ConfigRepository
                        >
        {
            typedef TestImpl<
                DD<
                    Radio::RadioLuxus,
                    CS<Boards::Board1, LPC214x::LPC2144> >,
                Origin, ConfigRepository
                > type;
        };

// HMI Component
    template<class Origin, class ConfigRepository>
    struct Component<
        CS<App::HMI, Radio::RadioSimple>,
        Origin,
        ConfigRepository
                    >
    {
//        typedef TestImpl<
//            CS<App::HMI, Radio::RadioSimple>,
//            Origin, ConfigRepository
//            > type;
        typedef Radio::RadioHMI<
            CS<App::HMI, Radio::RadioSimple>, 
            Origin,
            ConfigRepository
            > type;
    };
  
// HMI Adapter
    template<class Origin, class ConfigRepository>
    struct Component<
        DD<
            CS<App::HMI, Radio::RadioSimple>, 
            CS<Boards::Board1, LPC214x::LPC2141> >,
        Origin,
        ConfigRepository
                    >
    {
        typedef TestImpl<
            DD<
                CS<App::HMI, Radio::RadioSimple>, 
                CS<Boards::Board1, LPC214x::LPC2141> >, 
            Origin, ConfigRepository
            > type;
    };

    // Receiver Component
        template<class Origin, class ConfigRepository>
        struct Component<
            CS<Radio::Receiver, Radio::RadioSimple>,
            Origin, ConfigRepository
                        >
        {
            typedef Radio::RadioReceiver<
                CS<Radio::Receiver, Radio::RadioSimple>,
                Origin, ConfigRepository
                > type;
        };
        // Receiver Component Demo für Bernd
//            template<class Origin, class ConfigRepository>
//            struct Component<
//                CS<Radio::Receiver, Radio::RadioLuxus>,
//                Origin, ConfigRepository
//                            >
//            {
//                typedef Radio::RadioReceiver<
//                    CS<Radio::Receiver, Radio::RadioLuxus>,
//                    Origin, ConfigRepository
//                    > type;
//            };

    // Receiver Adapter
        template<class Origin, class ConfigRepository>
        struct Component<
            DD<
                CS<Radio::Receiver, Radio::RadioSimple>,
                CS<Boards::Board1, LPC214x::LPC2141> >,
            Origin, ConfigRepository
                        >
        {
            typedef TestImpl<
                DD<
                CS<Radio::Receiver, Radio::RadioSimple>,
                CS<Boards::Board1, LPC214x::LPC2141> >,
                Origin, ConfigRepository
                > type;
        };
        template<class Origin, class ConfigRepository>
        struct Component<
            DD<
                CS<Radio::Receiver, Radio::RadioAdvanced>,
                CS<Boards::Board1, LPC214x::LPC2141> >,
            Origin, ConfigRepository
                        >
        {
            typedef TestImpl<
                DD<
                CS<Radio::Receiver, Radio::RadioAdvanced>,
                CS<Boards::Board1, LPC214x::LPC2141> >,
                Origin, ConfigRepository
                > type;
        };

// Verkehrsfunk
   template<class Origin, class ConfigRepository>
    struct Component<
        CS<Radio::Verkehrsfunk, Radio::RadioAdvanced>,
        Origin, ConfigRepository
                    >
    {
        typedef TestImpl<
            CS<Radio::Verkehrsfunk, Radio::RadioAdvanced>, 
            Origin, ConfigRepository
            > type;
    };
// Amplifier
   template<class Origin, class ConfigRepository>
    struct Component<
        CS<Radio::Amplifier, Radio::RadioSimple>,
        Origin, ConfigRepository
                    >
    {
        typedef TestImpl<
            CS<Radio::Amplifier, Radio::RadioSimple>, 
            Origin, ConfigRepository
            > type;
    };
   template<class Origin, class ConfigRepository>
    struct Component<
        CS<Radio::Amplifier, Radio::RadioLuxus>,
        Origin, ConfigRepository
                    >
    {
        typedef TestImpl<
            CS<Radio::Amplifier, Radio::RadioLuxus>, 
            Origin, ConfigRepository
            > type;
    };

} // namespace Generator
#endif // __RADIO_COMPONENTS_H__
