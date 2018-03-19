#include "ContextTest.h"

using namespace Generator;

//---------------------------------------------------------------------
std::type_info const* SimpleContextExpected[] = {
		&typeid(LPC214x::LPC2148),
		&typeid(LPC214x::LPC2146),
		&typeid(LPC214x::LPC2144),
		&typeid(LPC214x::LPC2142),
		&typeid(LPC214x::LPC2141),
		&typeid(SelectorDefault),
		&typeid(SelectorEnd)
};
void ContextTest::SimpleContext(){
	typedef LPC214x::LPC2148 ToTest;
	TestAllBaseTypes<ToTest, SimpleContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* SSContextExpected[] = {
		&typeid(SS<int, double>),
		&typeid(SelectorDefault),
		&typeid(SelectorEnd)
};
void ContextTest::SSContext(){
	typedef SS<int, double> ToTest;
	TestAllBaseTypes<ToTest, SSContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* CSContextExpected[] = {
		&typeid(CS<HAL::PinConnectBlock, LPC214x::LPC2148>),
		&typeid(CS<HAL::PinConnectBlock, LPC214x::LPC2146>),
		&typeid(CS<HAL::PinConnectBlock, LPC214x::LPC2144>),
		&typeid(CS<HAL::PinConnectBlock, LPC214x::LPC2142>),
		&typeid(CS<HAL::PinConnectBlock, LPC214x::LPC2141>),
		&typeid(CS<HAL::PinConnectBlock, SelectorDefault>),
		&typeid(CS<HAL::PinConnectBlock, SelectorEnd>),
		&typeid(SelectorEnd)
};
void ContextTest::CSContext(){
	typedef CS<HAL::PinConnectBlock, LPC214x::LPC2148> ToTest;
	TestAllBaseTypes<ToTest, CSContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* NOCSContextExpected[] = {
		&typeid(CS<NO<HAL::GPIO, 1>, LPC214x::LPC2148>),
		&typeid(CS<NO<HAL::GPIO, 1>, LPC214x::LPC2146>),
		&typeid(CS<NO<HAL::GPIO, 1>, LPC214x::LPC2144>),
		&typeid(CS<NO<HAL::GPIO, 1>, LPC214x::LPC2142>),
		&typeid(CS<NO<HAL::GPIO, 1>, LPC214x::LPC2141>),
		&typeid(CS<NO<HAL::GPIO, 1>, SelectorDefault>),
		&typeid(CS<NO<HAL::GPIO, 1>, SelectorEnd>),
		&typeid(SelectorEnd)
};
void ContextTest::NOCSContext(){
	typedef CS<NO<HAL::GPIO, 1>, LPC214x::LPC2148> ToTest;
	TestAllBaseTypes<ToTest, NOCSContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* CustomContextLuxusExpected[] = {
		&typeid(Custom::RadioLuxus),
		&typeid(Radio::RadioLuxus),
		&typeid(Custom::RadioAdvanced),
		&typeid(Radio::RadioAdvanced),
		&typeid(Custom::RadioSimple),
		&typeid(Radio::RadioSimple),
		&typeid(SelectorDefault),
		&typeid(SelectorEnd)
};
void ContextTest::CustomContextLuxus(){
	typedef Custom::RadioLuxus ToTest;
	TestAllBaseTypes<ToTest, CustomContextLuxusExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* CustomContextAdvancedExpected[] = {
		&typeid(Custom::RadioAdvanced),
		&typeid(Radio::RadioAdvanced),
		&typeid(Custom::RadioSimple),
		&typeid(Radio::RadioSimple),
		&typeid(SelectorDefault),
		&typeid(SelectorEnd)
};
void ContextTest::CustomContextAdvanced(){
	typedef Custom::RadioAdvanced ToTest;
	TestAllBaseTypes<ToTest, CustomContextAdvancedExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* DDContextExpected[] = {
		&typeid(DD<Radio::RadioSimple, LPC214x::LPC2141>),
		&typeid(DD<Radio::RadioSimple, SelectorDefault>),
		&typeid(DD<Radio::RadioSimple, SelectorEnd>),
		&typeid(DD<SelectorDefault, LPC214x::LPC2141>),
		&typeid(DD<SelectorDefault, SelectorDefault>),
		&typeid(DD<SelectorDefault, SelectorEnd>),
		&typeid(SelectorEnd)
};
void ContextTest::DDContext(){
	typedef DD<Radio::RadioSimple, LPC214x::LPC2141> ToTest;

	TestAllBaseTypes<ToTest, DDContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* DD_CSCSContextExpected[] = {
		&typeid(DD<
				CS<App::HMI, Radio::RadioSimple>,
				CS<Boards::Board1, LPC214x::LPC2141> >),
		&typeid(DD<
				CS<App::HMI, Radio::RadioSimple>,
				CS<Boards::Board1, SelectorDefault> >),
		&typeid(DD<
				CS<App::HMI, Radio::RadioSimple>,
				CS<Boards::Board1, SelectorEnd> >),
		&typeid(DD<
				CS<App::HMI, Radio::RadioSimple>,
				SelectorEnd>),
		&typeid(DD<
				CS<App::HMI, SelectorDefault>,
				CS<Boards::Board1, LPC214x::LPC2141> >),
		&typeid(DD<
				CS<App::HMI, SelectorDefault>,
				CS<Boards::Board1, SelectorDefault> >),
		&typeid(DD<
				CS<App::HMI, SelectorDefault>,
				CS<Boards::Board1, SelectorEnd> >),

// Optimiert durch Spezialisierung für DD<CS<T1, SelectorDefault>, CS<T2, SelectorEnd> >
//		&typeid(DD<
//				CS<App::HMI, SelectorDefault>,
//				SelectorEnd>),
//		&typeid(DD<
//				CS<App::HMI, SelectorEnd>,
//				CS<Boards::Board1, LPC214x::LPC2141> >),
//		&typeid(DD<
//				CS<App::HMI, SelectorEnd>,
//				CS<Boards::Board1, SelectorDefault> >),
//		&typeid(DD<
//				CS<App::HMI, SelectorEnd>,
//				CS<Boards::Board1, SelectorEnd> >),
//		&typeid(DD<
//				CS<App::HMI, SelectorEnd>,
//				SelectorEnd>),
//		&typeid(DD<
//				SelectorEnd,
//				CS<Boards::Board1, LPC214x::LPC2141> >),

		&typeid(SelectorEnd)
};
void ContextTest::DD_CSCSContext(){
	typedef DD<
			CS<App::HMI, Radio::RadioSimple>,
			CS<Boards::Board1, LPC214x::LPC2141> > ToTest;
	TestAllBaseTypes<ToTest, DD_CSCSContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* CS_DDContextExpected[] = {
		&typeid(
		CS< App::HMI, DD< Radio::RadioSimple, LPC214x::LPC2141 > > ),
		&typeid(
		CS< App::HMI, DD< Radio::RadioSimple, SelectorDefault > > ),
		&typeid(
		CS< App::HMI, DD< Radio::RadioSimple, SelectorEnd > > ),
		&typeid(
		CS< App::HMI, DD< SelectorDefault, LPC214x::LPC2141 > > ),
		&typeid(
		CS< App::HMI, DD< SelectorDefault, SelectorDefault > > ),
		&typeid(
		CS< App::HMI, DD< SelectorDefault, SelectorEnd > > ),
		&typeid(
		CS< App::HMI, SelectorEnd > ),
		&typeid(
		SelectorEnd )
};
void ContextTest::CS_DDContext(){
	typedef CS< App::HMI, DD< Radio::RadioSimple, LPC214x::LPC2141 > > ToTest;
	TestAllBaseTypes<ToTest, CS_DDContextExpected>::test();
}//---------------------------------------------------------------------
std::type_info const* DD_DD1ContextExpected[] = {
		&typeid(DD<DD<DDS::S1, DDS::S2>, DDS::S3>),
		&typeid(DD<DD<DDS::S1, DDS::S2>, SelectorDefault>),
		&typeid(DD<DD<DDS::S1, DDS::S2>, SelectorEnd>),

		&typeid(DD<DD<DDS::S1, SelectorDefault>, DDS::S3>),
		&typeid(DD<DD<DDS::S1, SelectorDefault>, SelectorDefault>),
		&typeid(DD<DD<DDS::S1, SelectorDefault>, SelectorEnd>),

// Optimiert durch Spezialisierung für DD<DD<Selector1, SelectorDefault>, SelectorEnd>
//		&typeid(DD<DD<DDS::S1, SelectorEnd>, DDS::S3>),
//		&typeid(DD<DD<DDS::S1, SelectorEnd>, SelectorDefault>),
//		&typeid(DD<DD<DDS::S1, SelectorEnd>, SelectorEnd>),

		&typeid(DD<DD<SelectorDefault, DDS::S2>, DDS::S3>),
		&typeid(DD<DD<SelectorDefault, DDS::S2>, SelectorDefault>),
		&typeid(DD<DD<SelectorDefault, DDS::S2>, SelectorEnd>),

		&typeid(DD<DD<SelectorDefault, SelectorDefault>, DDS::S3>),
		&typeid(DD<DD<SelectorDefault, SelectorDefault>, SelectorDefault>),
		&typeid(DD<DD<SelectorDefault, SelectorDefault>, SelectorEnd>),

		&typeid(SelectorEnd)
};
void ContextTest::DD_DD1Context(){
	typedef DD<DD<DDS::S1, DDS::S2>, DDS::S3> ToTest;
	TestAllBaseTypes<ToTest, DD_DD1ContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* DD_DD2ContextExpected[] = {
		&typeid(DD<DDS::S1, DD<DDS::S2, DDS::S3> >),
		&typeid(DD<DDS::S1, DD<DDS::S2, SelectorDefault> >),
		&typeid(DD<DDS::S1, DD<DDS::S2, SelectorEnd> >),

		&typeid(DD<DDS::S1, DD<SelectorDefault, DDS::S3> >),
		&typeid(DD<DDS::S1, DD<SelectorDefault, SelectorDefault> >),
		&typeid(DD<DDS::S1, DD<SelectorDefault, SelectorEnd> >),

		&typeid(DD<DDS::S1, SelectorEnd>),

		&typeid(DD<SelectorDefault, DD<DDS::S2, DDS::S3> >),
		&typeid(DD<SelectorDefault, DD<DDS::S2, SelectorDefault> >),
		&typeid(DD<SelectorDefault, DD<DDS::S2, SelectorEnd> >),

		&typeid(DD<SelectorDefault, DD<SelectorDefault, DDS::S3> >),
		&typeid(DD<SelectorDefault, DD<SelectorDefault, SelectorDefault> >),
		&typeid(DD<SelectorDefault, DD<SelectorDefault, SelectorEnd> >),

// Optimiert durch Spezialisierung für (DD<SelectorDefault, DD<SelectorDefault, SelectorEnd> >
		//&typeid(DD<SelectorDefault, SelectorEnd>),

		&typeid(SelectorEnd)
};
void ContextTest::DD_DD2Context(){
	typedef DD<DDS::S1, DD<DDS::S2, DDS::S3> > ToTest;
	TestAllBaseTypes<ToTest, DD_DD2ContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* DD_DD_DD1ContextExpected[] = {
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, DDS::S1 >, DDS::S2 >, DDS::S3 > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, DDS::S1 >, DDS::S2 >, SelectorDefault > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, DDS::S1 >, DDS::S2 >, SelectorEnd > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, DDS::S1 >, SelectorDefault >, DDS::S3 > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, DDS::S1 >, SelectorDefault >, SelectorDefault > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, DDS::S1 >, SelectorDefault >, SelectorEnd > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, SelectorDefault >, DDS::S2 >, DDS::S3 > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, SelectorDefault >, DDS::S2 >, SelectorDefault > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, SelectorDefault >, DDS::S2 >, SelectorEnd > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, SelectorDefault >, SelectorDefault >, DDS::S3 > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, SelectorDefault >, SelectorDefault >, SelectorDefault > ),
		&typeid(
		DD< DD< DD< LPC214x::LPC2141, SelectorDefault >, SelectorDefault >, SelectorEnd > ),
		&typeid(
		DD< DD< DD< SelectorDefault, DDS::S1 >, DDS::S2 >, DDS::S3 > ),
		&typeid(
		DD< DD< DD< SelectorDefault, DDS::S1 >, DDS::S2 >, SelectorDefault > ),
		&typeid(
		DD< DD< DD< SelectorDefault, DDS::S1 >, DDS::S2 >, SelectorEnd > ),
		&typeid(
		DD< DD< DD< SelectorDefault, DDS::S1 >, SelectorDefault >, DDS::S3 > ),
		&typeid(
		DD< DD< DD< SelectorDefault, DDS::S1 >, SelectorDefault >, SelectorDefault > ),
		&typeid(
		DD< DD< DD< SelectorDefault, DDS::S1 >, SelectorDefault >, SelectorEnd > ),
		&typeid(
		DD< DD< DD< SelectorDefault, SelectorDefault >, DDS::S2 >, DDS::S3 > ),
		&typeid(
		DD< DD< DD< SelectorDefault, SelectorDefault >, DDS::S2 >, SelectorDefault > ),
		&typeid(
		DD< DD< DD< SelectorDefault, SelectorDefault >, DDS::S2 >, SelectorEnd > ),
		&typeid(
		DD< DD< DD< SelectorDefault, SelectorDefault >, SelectorDefault >, DDS::S3 > ),
		&typeid(
		DD< DD< DD< SelectorDefault, SelectorDefault >, SelectorDefault >, SelectorDefault > ),
		&typeid(
		DD< DD< DD< SelectorDefault, SelectorDefault >, SelectorDefault >, SelectorEnd > ),
		&typeid(
		DD< SelectorEnd, DDS::S3 > ),
		&typeid(
		SelectorEnd )
};
void ContextTest::DD_DD_DD1Context(){
	typedef DD< DD< DD< LPC214x::LPC2141, DDS::S1 >, DDS::S2 >, DDS::S3 > ToTest;
	TestAllBaseTypes<ToTest, DD_DD_DD1ContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* DD_DD_DD2ContextExpected[] = {
		&typeid(
		DD< LPC214x::LPC2141, DD< DDS::S1, DD< DDS::S2, DDS::S3 > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< DDS::S1, DD< DDS::S2, SelectorDefault > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< DDS::S1, DD< DDS::S2, SelectorEnd > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< DDS::S1, DD< SelectorDefault, DDS::S3 > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< DDS::S1, DD< SelectorDefault, SelectorDefault > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< DDS::S1, DD< SelectorDefault, SelectorEnd > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< DDS::S1, SelectorEnd > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< SelectorDefault, DD< DDS::S2, DDS::S3 > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< SelectorDefault, DD< DDS::S2, SelectorDefault > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< SelectorDefault, DD< DDS::S2, SelectorEnd > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< SelectorDefault, DD< SelectorDefault, DDS::S3 > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< SelectorDefault, DD< SelectorDefault, SelectorDefault > > > ),
		&typeid(
		DD< LPC214x::LPC2141, DD< SelectorDefault, DD< SelectorDefault, SelectorEnd > > > ),

		// Optimiert durch Spezialisierung für (DD<SelectorDefault, DD<SelectorDefault, SelectorEnd> >
		//&typeid(DD< LPC214x::LPC2141, DD< SelectorDefault, SelectorEnd > > ),

		&typeid(
		DD< LPC214x::LPC2141, SelectorEnd > ),
		&typeid(
		DD< SelectorDefault, DD< DDS::S1, DD< DDS::S2, DDS::S3 > > > ),
		&typeid(
		DD< SelectorDefault, DD< DDS::S1, DD< DDS::S2, SelectorDefault > > > ),
		&typeid(
		DD< SelectorDefault, DD< DDS::S1, DD< DDS::S2, SelectorEnd > > > ),
		&typeid(
		DD< SelectorDefault, DD< DDS::S1, DD< SelectorDefault, DDS::S3 > > > ),
		&typeid(
		DD< SelectorDefault, DD< DDS::S1, DD< SelectorDefault, SelectorDefault > > > ),
		&typeid(
		DD< SelectorDefault, DD< DDS::S1, DD< SelectorDefault, SelectorEnd > > > ),
		&typeid(
		DD< SelectorDefault, DD< DDS::S1, SelectorEnd > > ),
		&typeid(
		DD< SelectorDefault, DD< SelectorDefault, DD< DDS::S2, DDS::S3 > > > ),
		&typeid(
		DD< SelectorDefault, DD< SelectorDefault, DD< DDS::S2, SelectorDefault > > > ),
		&typeid(
		DD< SelectorDefault, DD< SelectorDefault, DD< DDS::S2, SelectorEnd > > > ),
		&typeid(
		DD< SelectorDefault, DD< SelectorDefault, DD< SelectorDefault, DDS::S3 > > > ),
		&typeid(
		DD< SelectorDefault, DD< SelectorDefault, DD< SelectorDefault, SelectorDefault > > > ),
		&typeid(
		DD< SelectorDefault, DD< SelectorDefault, DD< SelectorDefault, SelectorEnd > > > ),

		// Optimiert durch Spezialisierung für (DD<SelectorDefault, DD<SelectorDefault, SelectorEnd> >
		//&typeid( DD< SelectorDefault, DD< SelectorDefault, SelectorEnd > > ),

		&typeid(DD< SelectorDefault, SelectorEnd > ),

		&typeid(
		SelectorEnd )
};
void ContextTest::DD_DD_DD2Context(){
	typedef DD< LPC214x::LPC2141, DD< DDS::S1, DD< DDS::S2, DDS::S3 > > > ToTest;
	TestAllBaseTypes<ToTest, DD_DD_DD2ContextExpected>::test();
}
//---------------------------------------------------------------------
std::type_info const* DD_DDDD_Expected[] = {
		&typeid(
		DD< DD< Radio::RadioSimple, DDS::S1 >, DD< DDS::S2, DDS::S3 > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, DDS::S1 >, DD< DDS::S2, SelectorDefault > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, DDS::S1 >, DD< DDS::S2, SelectorEnd > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, DDS::S1 >, DD< SelectorDefault, DDS::S3 > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, DDS::S1 >, DD< SelectorDefault, SelectorDefault > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, DDS::S1 >, DD< SelectorDefault, SelectorEnd > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, DDS::S1 >, SelectorEnd > ),
		&typeid(
		DD< DD< Radio::RadioSimple, SelectorDefault >, DD< DDS::S2, DDS::S3 > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, SelectorDefault >, DD< DDS::S2, SelectorDefault > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, SelectorDefault >, DD< DDS::S2, SelectorEnd > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, SelectorDefault >, DD< SelectorDefault, DDS::S3 > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, SelectorDefault >, DD< SelectorDefault, SelectorDefault > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, SelectorDefault >, DD< SelectorDefault, SelectorEnd > > ),
		&typeid(
		DD< DD< Radio::RadioSimple, SelectorDefault >, SelectorEnd > ),
		&typeid(
		DD< DD< SelectorDefault, DDS::S1 >, DD< DDS::S2, DDS::S3 > > ),
		&typeid(
		DD< DD< SelectorDefault, DDS::S1 >, DD< DDS::S2, SelectorDefault > > ),
		&typeid(
		DD< DD< SelectorDefault, DDS::S1 >, DD< DDS::S2, SelectorEnd > > ),
		&typeid(
		DD< DD< SelectorDefault, DDS::S1 >, DD< SelectorDefault, DDS::S3 > > ),
		&typeid(
		DD< DD< SelectorDefault, DDS::S1 >, DD< SelectorDefault, SelectorDefault > > ),
		&typeid(
		DD< DD< SelectorDefault, DDS::S1 >, DD< SelectorDefault, SelectorEnd > > ),
		&typeid(
		DD< DD< SelectorDefault, DDS::S1 >, SelectorEnd > ),
		&typeid(
		DD< DD< SelectorDefault, SelectorDefault >, DD< DDS::S2, DDS::S3 > > ),
		&typeid(
		DD< DD< SelectorDefault, SelectorDefault >, DD< DDS::S2, SelectorDefault > > ),
		&typeid(
		DD< DD< SelectorDefault, SelectorDefault >, DD< DDS::S2, SelectorEnd > > ),
		&typeid(
		DD< DD< SelectorDefault, SelectorDefault >, DD< SelectorDefault, DDS::S3 > > ),
		&typeid(
		DD< DD< SelectorDefault, SelectorDefault >, DD< SelectorDefault, SelectorDefault > > ),
		&typeid(
		DD< DD< SelectorDefault, SelectorDefault >, DD< SelectorDefault, SelectorEnd > > ),
		&typeid(
		DD< DD< SelectorDefault, SelectorDefault >, SelectorEnd > ),
		&typeid(
		SelectorEnd )};
void ContextTest::DD_DDDD_Context(){
	typedef DD< DD< Radio::RadioSimple, DDS::S1 >, DD< DDS::S2, DDS::S3 > >  ToTest;
	TestAllBaseTypes<ToTest, DD_DDDD_Expected>::test();
}
void ContextTest::CS_getSelector(){
	typedef CS<HAL::PinConnectBlock, DDS::Selector02>  ToTest;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getSelector",
			typeid(DDS::Selector02).name(), typeid(ToTest::getSelector<>::type).name() );
	CPPUNIT_ASSERT_MESSAGE("getSelector",
			typeid(DDS::Selector02) == typeid(ToTest::getSelector<>::type) );

	// Fehlermeldung
	typedef DD<DDS::Selector02, DDS::Selector12>  Another;
//	typedef ToTest::getSelector<Another>::type demo;

}
void ContextTest::DD_getSelector(){
	typedef DD<DDS::Selector02, DDS::Selector12>  ToTest;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getSelector<1>",
			typeid(DDS::Selector02).name(), typeid(ToTest::getSelector<1>::type).name() );
	CPPUNIT_ASSERT_MESSAGE("getSelector<1>",
			typeid(DDS::Selector02) == typeid(ToTest::getSelector<1>::type) );
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getSelector<2>",
			typeid(DDS::Selector12).name(), typeid(ToTest::getSelector<2>::type).name() );
	CPPUNIT_ASSERT_MESSAGE("getSelector<2>",
			typeid(DDS::Selector12) == typeid(ToTest::getSelector<2>::type) );

	// Fehlermeldung
	typedef CS<HAL::PinConnectBlock, DDS::Selector02>  Another;
//	typedef ToTest::getSelector1<Another>::type demo;
}

//---------------------------------------------------------------------
void ContextTest::PrintContext(){
	//SimpleContext
	//typedef LPC214x::LPC2148 Context;
	//CSContext
	//typedef CS<HAL::PinConnectBlock, LPC214x::LPC2148> Context;
	//CustomContext
	//typedef Custom::RadioLuxus Context;
	//DDContext
	//typedef DD<Radio::RadioSimple, LPC214x::LPC2141> Context;
	//DD_CSCSContext
	//typedef DD<CS<App::HMI, Radio::RadioSimple>, CS<Boards::Board1, LPC214x::LPC2141> > Context;
	//CS_DDContext
	//typedef CS<App::HMI, DD<Radio::RadioSimple, LPC214x::LPC2141> > Context;
	//DD_DD1Context
	//typedef DD<DD<DDS::S1, DDS::S2>, DDS::S3 > Context;
	//DD_DD2Context
	//typedef DD<DDS::S1, DD<DDS::S2, DDS::S3> > Context;
	//DD_DD_DD1Context
	//typedef DD< DD< DD< LPC214x::LPC2141, DDS::S1 >, DDS::S2 >, DDS::S3 > Context;
	//DD_DD_DD2Context
	//typedef DD< LPC214x::LPC2141, DD< DDS::S1, DD< DDS::S2, DDS::S3 > > > Context;
	//DD_DDDD_Context
	//typedef DD< DD< Radio::RadioSimple, DDS::S1 >, DD< DDS::S2, DDS::S3 > > Context;
	//Vererbungshierarchien
	typedef DD<DDS::Selector02, DDS::Selector12> Context;

	PrintBaseType<Context>::print(std::cout);
}
