#include "ComponentTest.h"

using namespace Generator;


//==================================================================
void ComponentTest::DemoPrintComponent(){
	typedef LPC214x::LPC2148 Origin;

	//============================================
	PrintComponent<Origin>::print(std::cout);
	//============================================
}
//==================================================================
void ComponentTest::ComponentConfigurationError(){
	typedef CS<NO<HAL::AD, 1>, LPC214x::LPC2141> Origin;
	typedef Origin Selector;

	typedef Create<Origin>::type Result;
	//CT<Origin> Result;

	typedef TestImpl<Selector, Origin> Expected;
	//Fehlermeldung erzeugen
	//============================================
	//TestComponent<Expected, Result>::test();
	//============================================
}
//==================================================================
void ComponentTest::InvalidContext(){
	struct MyType{};
	//============================================
	//typedef Create<MyType>::type Error;
	//============================================
}

//==================================================================
void ComponentTest::PinConnectBlock_LPC2141_41(){
	typedef CS<HAL::PinConnectBlock, LPC214x::LPC2141> Origin;
	typedef Origin Selector;

	typedef Create<Origin>::type Result;
//	CT<Origin> var; // erzeugt ein Objekt der Komponente
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, CT<Origin>>::test();
	TestComponent<Expected, Result>::test();
	//============================================
}
//==================================================================
void ComponentTest::PinConnectBlock_LPC2142_41(){
	typedef CS<HAL::PinConnectBlock, LPC214x::LPC2142> Origin;
	typedef CS<HAL::PinConnectBlock, LPC214x::LPC2141> Selector;

	typedef Create<Origin>::type Result;
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
}
//==================================================================
void ComponentTest::PinConnectBlock_LPC2148_44(){
	typedef CS<HAL::PinConnectBlock, LPC214x::LPC2148> Origin;
	typedef CS<HAL::PinConnectBlock, LPC214x::LPC2144> Selector;

	typedef Create<Origin>::type Result;
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
}

//==================================================================
void ComponentTest::AggregateLPC2141_41(){
	//Aggregate
	typedef LPC214x::LPC2141 Origin;
	typedef Origin Selector;

	typedef Create<Origin>::type Result;
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
	//Components
	typedef CS<HAL::PinConnectBlock, LPC214x::LPC2141> PCB_Origin;
	typedef TestImpl<PCB_Origin, PCB_Origin> ExpectedPCB;
	//============================================
	TestComponent<ExpectedPCB, Result::PinConnectBlock>::test();
	//============================================
	typedef CS<NO<HAL::GPIO, 0>, Origin> GPIO_0;
	typedef TestImpl<GPIO_0, GPIO_0> ExpectedGPIO;
	//============================================
	TestComponent<ExpectedGPIO, Result::GPIO_0>::test();
	//============================================
}
//==================================================================
void ComponentTest::AggregateLPC2142_41(){
	//Aggregate
	typedef LPC214x::LPC2142 Origin;
	typedef LPC214x::LPC2141 Selector;

	typedef Create<Origin>::type Result;
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
	//Components
	typedef CS<HAL::PinConnectBlock, Selector> PCB_Selector;
	typedef CS<HAL::PinConnectBlock, Origin> PCB_Origin;
	typedef TestImpl<PCB_Selector, PCB_Origin> ExpectedPCB;
	//============================================
	TestComponent<ExpectedPCB, Result::PinConnectBlock>::test();
	//============================================
	typedef CS<NO<HAL::GPIO, 0>, Selector> GPIO_0_Selector;
	typedef CS<NO<HAL::GPIO, 0>, Origin> GPIO_0_Origin;
	typedef TestImpl<GPIO_0_Selector, GPIO_0_Origin> ExpectedGPIO_0;
	//============================================
	TestComponent<ExpectedGPIO_0, Result::GPIO_0>::test();
	//============================================
}
//==================================================================
void ComponentTest::AggregateLPC2148_44(){
	//Aggregate
	typedef LPC214x::LPC2148 Origin;
	typedef LPC214x::LPC2144 Selector;

	typedef Create<Origin>::type Result;
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
	//Components
	typedef CS<HAL::PinConnectBlock, Selector> PCB_Selector;
	typedef CS<HAL::PinConnectBlock, Origin> PCB_Origin;
	typedef TestImpl<PCB_Selector, PCB_Origin> ExpectedPCB;
	//============================================
	TestComponent<ExpectedPCB, Result::PinConnectBlock>::test();
	//============================================
	typedef CS<NO<HAL::GPIO, 0>, LPC214x::LPC2141> GPIO_0_Selector;
	typedef CS<NO<HAL::GPIO, 0>, Origin> GPIO_0_Origin;
	typedef TestImpl<GPIO_0_Selector, GPIO_0_Origin> ExpectedGPIO_0;
	//============================================
	TestComponent<ExpectedGPIO_0, Result::GPIO_0>::test();
	//============================================
	typedef CS<NO<HAL::GPIO, 1>, Selector> GPIO_1_Selector;
	typedef CS<NO<HAL::GPIO, 1>, Origin> GPIO_1_Origin;
	typedef TestImpl<GPIO_1_Selector, GPIO_1_Origin> ExpectedGPIO_1;
	//============================================
	TestComponent<ExpectedGPIO_1, Result::GPIO_1>::test();
	//============================================
}
//==================================================================
void ComponentTest::Radio_Advanced_Simple_HMIAdapter_Board1_LPC2148_41(){
	typedef DD<
				CS<App::HMI, Radio::RadioAdvanced>,
				CS<Boards::Board1, LPC214x::LPC2148>
			>Origin;
	typedef DD<
				CS<App::HMI, Radio::RadioSimple>,
				CS<Boards::Board1, LPC214x::LPC2141>
			>Selector;

	typedef Create<Origin>::type Result;
	typedef TestImpl<Selector, Origin> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
}
//==================================================================
void ComponentTest::Radio_Advanced_Simple_Receiver_ConfigRep_Board1_LPC2148_41(){
	typedef HAL::PlatformConfigurationRepository<Boards::Board1, LPC214x::LPC2148>
		ConfigRep;

	typedef CS<Radio::Receiver, Radio::RadioAdvanced> Origin;
	typedef CS<Radio::Receiver, Radio::RadioSimple> Selector;

	typedef Create<Origin, ConfigRep>::type Result;
	typedef Radio::RadioReceiver<Selector, Origin, ConfigRep>
		Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
	typedef DD<
				Origin,
				CS<Boards::Board1, LPC214x::LPC2141>
			>ReceiverAdapterSelector;
	typedef DD<
				Origin,
				CS<Boards::Board1, LPC214x::LPC2148>
			>ReceiverAdapterOrigin;
	typedef TestImpl<ReceiverAdapterSelector, ReceiverAdapterOrigin>
		RAExpected;
	//============================================
	TestComponent<RAExpected, Result::ReceiverAdapter>::test();
	//============================================
}
//==================================================================
void ComponentTest::Radio_Luxus_Simple_ConfigRep_Board1_LPC2148_41(){
	typedef HAL::PlatformConfigurationRepository<Boards::Board1, LPC214x::LPC2148>
		ConfigRep;

	typedef Radio::RadioLuxus Origin;
	typedef Radio::RadioAdvanced Selector;

	typedef Radio::RadioAdvancedAggregate<Selector, Origin, ConfigRep>
		Expected;
	typedef Create<Origin, ConfigRep>
		::type Result;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
	// Receiver specialization for RadioSimple
	typedef CS<Radio::Receiver, Radio::RadioSimple>
		ReceiverSelector;
	typedef CS<Radio::Receiver, Origin>
		ReceiverOrigin;
	typedef Radio::RadioReceiver<ReceiverSelector, ReceiverOrigin, ConfigRep>
		ReceiverExpected;
	//============================================
	TestComponent<ReceiverExpected, Result::Receiver>::test();
	//============================================
	// Receiver Adapter specialization for RadioAdvanced
	typedef DD<
				CS<Radio::Receiver, Radio::RadioAdvanced>,
				CS<Boards::Board1, LPC214x::LPC2141>
			>ReceiverAdapterSelector;
	typedef DD<
				CS<Radio::Receiver, Origin>,
				CS<Boards::Board1, LPC214x::LPC2148>
			>ReceiverAdapterOrigin;

	typedef TestImpl<ReceiverAdapterSelector, ReceiverAdapterOrigin>
		RAExpected;
	//============================================
	TestComponent<RAExpected, Result::Receiver::ReceiverAdapter>::test();
	//============================================
	//HMI und HMI Adapter specialization for RadioSimple
	typedef CS<App::HMI, Radio::RadioSimple> HMISelector;
	typedef CS<App::HMI, Origin> HMIOrigin;
	typedef Radio::RadioHMI< HMISelector, HMIOrigin, ConfigRep> HMIExpected;
	//============================================
	TestComponent<HMIExpected, Result::HMI>::test();
	//============================================
	typedef DD<
				HMISelector,
				CS<Boards::Board1, LPC214x::LPC2141>
			>HMIAdapterSelector;
	typedef DD<
				CS<App::HMI, Origin>,
				CS<Boards::Board1, LPC214x::LPC2148>
			>HMIAdapterOrigin;

	typedef TestImpl<HMIAdapterSelector, HMIAdapterOrigin> HMIAExpected;
	//============================================
	TestComponent<HMIAExpected, Result::HMI::HMIAdapter>::test();
	//============================================
}
