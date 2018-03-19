#ifndef __CONTEXT_TEST_H_
#define __CONTEXT_TEST_H_

#include "../GeneratorTestApp.h"

#include "DDDDSelectors.h"
/*
 * diese Tests überprüfen alle BaseTypes eines gegebenen Contexts
 * durch Vergleich des BaseTypes mit einem Typ aus einer Liste
 */
class ContextTest : public CPPUNIT_NS::TestFixture  {

	CPPUNIT_TEST_SUITE(ContextTest);
		// 1 Selector
		CPPUNIT_TEST(SimpleContext);
		CPPUNIT_TEST(SSContext);
		CPPUNIT_TEST(NOCSContext);
		CPPUNIT_TEST(CSContext);
		CPPUNIT_TEST(CustomContextLuxus);
		CPPUNIT_TEST(CustomContextAdvanced);
		// 2 Selectoren
		CPPUNIT_TEST(DDContext);
		CPPUNIT_TEST(DD_CSCSContext);
		CPPUNIT_TEST(CS_DDContext);
		// 3 Selectoren
		CPPUNIT_TEST(DD_DD1Context);
		CPPUNIT_TEST(DD_DD2Context);
		//4 Selectoren
		CPPUNIT_TEST(DD_DD_DD1Context);
		CPPUNIT_TEST(DD_DD_DD2Context);
		CPPUNIT_TEST(DD_DDDD_Context);
		// Zugriffsoperationen auf Selectoren
		CPPUNIT_TEST(CS_getSelector);
		CPPUNIT_TEST(DD_getSelector);

		//CPPUNIT_TEST(PrintContext);
	CPPUNIT_TEST_SUITE_END();

protected:
	// 1 Selector
	void SimpleContext();
	void SSContext();
	void NOCSContext();
	void CSContext();
	void CustomContextLuxus();
	void CustomContextAdvanced();
	// 2 Selectoren
	void DDContext();
	void DD_CSCSContext();
	void CS_DDContext();
	// 3 Selectoren
	void DD_DD1Context();
	void DD_DD2Context();
	// 4 Selectoren
	void DD_DD_DD1Context();
	void DD_DD_DD2Context();
	void DD_DDDD_Context();
	// Zugriffsoperationen auf Selectoren
	void CS_getSelector();
	void DD_getSelector();

	void PrintContext();
};

#endif /* __CONTEXT_TEST_H_ */
