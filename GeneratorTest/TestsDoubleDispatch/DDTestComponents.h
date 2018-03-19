/*
 * DDTestComponents.h
 *
 *  Created on: 17.12.2013
 *      Author: Gerd
 */

#ifndef DDTESTCOMPONENTS_H_
#define DDTESTCOMPONENTS_H_
#include "../Generator/GeneratorTestHelper.h"
#include "../TestsContext/DDDDSelectors.h"

namespace Generator{
   template<class Origin, class ConfigRepository>
    struct Component<
    		DD<SelectorDefault, SelectorDefault>,
    		Origin, ConfigRepository
    				>
    {
        typedef TestImpl<
        	DD<SelectorDefault, SelectorDefault>,
            Origin, ConfigRepository
            > type;
    };

   template<class Origin, class ConfigRepository>
    struct Component<
    		DD<DDS::Selector01, Generator::SelectorDefault>,
    		Origin, ConfigRepository
    				>
    {
        typedef TestImpl<
        	DD<DDS::Selector01, Generator::SelectorDefault>,
            Origin, ConfigRepository
            > type;
    };

   template<class Origin, class ConfigRepository>
    struct Component<
    		DD<Generator::SelectorDefault, DDS::Selector11>,
    		Origin, ConfigRepository
    				>
    {
        typedef TestImpl<
        		DD<Generator::SelectorDefault, DDS::Selector11>,
            Origin, ConfigRepository
            > type;
    };
} // namespace Generator


#endif /* DDTESTCOMPONENTS_H_ */
