#ifndef CUSTOMIZEDCONTEXTS_H_
#define CUSTOMIZEDCONTEXTS_H_

#include "../GeneratorTestApp.h"

#include "DDDDSelectors.h"

class CustomizedContexts : public CPPUNIT_NS::TestFixture  {

	CPPUNIT_TEST_SUITE(CustomizedContexts);

//	CPPUNIT_TEST(PrintContext);

	CPPUNIT_TEST_SUITE_END();

protected:
	void PrintContext();
};

#endif /* CUSTOMIZEDCONTEXTS_H_ */
