
#include "../GeneratorTestApp.h"

#ifndef COMPONENTTESTS_H_
#define COMPONENTTESTS_H_
/*
 * diese Tests erzeugen für einen bestimmten Context eine Component
 * und vergleichen den erzeugten Typ mit dem erwarteten Typ
 * Als Typ wird für einfache Components der generische Typ
 * TestImpl<Selector, Origin> verwendet, für Aggregate wird
 * ein spezifischer Typ verwendet
 */
class ComponentTest  : public CPPUNIT_NS::TestFixture  {
	CPPUNIT_TEST_SUITE(ComponentTest);

	CPPUNIT_TEST(PinConnectBlock_LPC2141_41);
	CPPUNIT_TEST(PinConnectBlock_LPC2142_41);
	CPPUNIT_TEST(PinConnectBlock_LPC2148_44);

	CPPUNIT_TEST(AggregateLPC2141_41);
	CPPUNIT_TEST(AggregateLPC2142_41);
	CPPUNIT_TEST(AggregateLPC2148_44);

	CPPUNIT_TEST(Radio_Advanced_Simple_HMIAdapter_Board1_LPC2148_41);
	CPPUNIT_TEST(Radio_Advanced_Simple_Receiver_ConfigRep_Board1_LPC2148_41);
	CPPUNIT_TEST(Radio_Luxus_Simple_ConfigRep_Board1_LPC2148_41);

	//erzeugt einen Compile Error
	//Component_NotSupportedFor<Generator::CS<Generator::NO<HAL::AD, 1u>, LPC214x::LPC2141> >
//	CPPUNIT_TEST(ComponentConfigurationError);
	// erzeugt Fehlermeldung
//	CPPUNIT_TEST(InvalidContext);

//	CPPUNIT_TEST(DemoPrintComponent);
	CPPUNIT_TEST_SUITE_END();
protected:

	void PinConnectBlock_LPC2141_41();
	void PinConnectBlock_LPC2142_41();
	void PinConnectBlock_LPC2148_44();

	void AggregateLPC2141_41();
	void AggregateLPC2142_41();
	void AggregateLPC2148_44();

	void Radio_Advanced_Simple_HMIAdapter_Board1_LPC2148_41();
	void Radio_Advanced_Simple_Receiver_ConfigRep_Board1_LPC2148_41();
	void Radio_Luxus_Simple_ConfigRep_Board1_LPC2148_41();

	void ComponentConfigurationError();
	// InvalidContext erzeugt fehlermeldung
	void InvalidContext();

	void DemoPrintComponent();

};

#endif /* COMPONENTTESTS_H_ */
