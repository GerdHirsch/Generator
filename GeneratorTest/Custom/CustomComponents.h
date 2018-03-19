#ifndef __CUSTOM_COMPONENTS_H__
#define __CUSTOM_COMPONENTS_H__

#include <Generator/BaseType.h>

#include <Radio/Types.h>

namespace Custom{

    template<class Selector, class Origin, class ConfigRep>
    struct RadioSimpleAggregate
    : Radio::RadioSimpleAggregate<Selector, Origin, ConfigRep>
    {
        typedef Radio::RadioSimpleAggregate<Selector, Origin, ConfigRep> base_type;

    };

} // namespace Custom


namespace Generator
{
    template<class Origin, class ConfigRep>
    struct Component<
    Custom::RadioSimple,
        Origin,
        ConfigRep
                    >
    {
        typedef Custom::RadioSimpleAggregate<
        		Custom::RadioSimple,
        		Origin,
        		ConfigRep
        > type;
    };

// HMI Component
    template<class Origin, class ConfigRepository>
    struct Component<
        CS<App::HMI, Custom::RadioSimple>,
        Origin,
        ConfigRepository
                    >
    {
        typedef TestImpl<
            CS<App::HMI, Custom::RadioSimple>,
            Origin, ConfigRepository
        > type;
    };
// Receiver Component
    template<class Origin, class ConfigRepository>
    struct Component<
        CS<Radio::Receiver, Custom::RadioAdvanced>,
        Origin,
        ConfigRepository
                    >
    {
        typedef TestImpl<
            CS<Radio::Receiver, Custom::RadioAdvanced>,
            Origin, ConfigRepository
        > type;
    };
// Verkehrsfunk Component
    template<class Origin, class ConfigRepository>
    struct Component<
        CS<Radio::Verkehrsfunk, Custom::RadioLuxus>,
        Origin,
        ConfigRepository
                    >
    {
        typedef TestImpl<
            CS<Radio::Verkehrsfunk, Custom::RadioLuxus>,
            Origin, ConfigRepository
        > type;
    };

}
#endif // __CUSTOM_COMPONENTS_H__
