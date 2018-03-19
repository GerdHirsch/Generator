
#include "../GeneratorTestApp.h"

#ifndef REPLACEBASETYPETESTS_H_
#define REPLACEBASETYPETESTS_H_
/*
 * Experiment:
 * ReplaceBaseType, ein Template das als Ergebnis
 * //Generator
 * template<class Context, class CurrentSelector, class toBeReplaced, class replacement>
 * struct replaceBaseType
 * liefert
 * 		wenn Context::BaseType<CurrentSelector>::type == toBeReplaced
 * 			replacement
 * 				ansonsten
 * 			Context::BaseType<CurrentSelector>::type
 *
 */
class ReplaceBaseTypeTest  : public CPPUNIT_NS::TestFixture  {
	CPPUNIT_TEST_SUITE(ReplaceBaseTypeTest);

		CPPUNIT_TEST(ReplaceBaseTypeforRadioSimple);

	CPPUNIT_TEST_SUITE_END();
protected:

	void ReplaceBaseTypeforRadioSimple();
};

#endif /* REPLACEBASETYPETESTS_H_ */
