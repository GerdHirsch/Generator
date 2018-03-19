#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "OutputTest.h"

using namespace std;

using namespace Generator;
//---------------------------------------------------------------------
void OutputTest::GenerateLPC4xContextComponentsTable(){
//	std::ostream &os = std::cout;
	std::ofstream os("LPC2148ContextDoc.xml");
	if(!os){
		std::cerr << "Cannot open LPC2148Doc.xml" << std::endl;
		CPPUNIT_ASSERT_MESSAGE("Cannot open LPC2148Doc.xml", false);
		return;
	}
    typedef
        Loki::TL::
        MakeTypelist<
            HAL::AD,
            HAL::GPIO,
            NO<HAL::GPIO, 0>,
            NO<HAL::GPIO, 1>,
            HAL::PinConnectBlock
                    >
    ::Result Rows;

    typedef LPC214x::LPC2148 Context;

    XML::XMLContexts<Context, Rows>::print(os);
}
//---------------------------------------------------------------------
void OutputTest::GenerateLPC4xComponentsContextTable(){
//	std::ostream &os = std::cout;
	std::ofstream os("LPC2148ComponentsDoc.xml");
	if(!os){
		std::cerr << "Cannot open LPC2148Doc.xml" << std::endl;
		CPPUNIT_ASSERT_MESSAGE("Cannot open LPC2148Doc.xml", false);
		return;
	}
    typedef
        Loki::TL::
        MakeTypelist<
            HAL::PinConnectBlock,
            NO<HAL::GPIO, 0>,
            NO<HAL::GPIO, 1>,
            HAL::AD
                    >
    ::Result Rows;

    typedef LPC214x::LPC2148 Context;

    XML::XMLContexts<Rows, Context>::print(os);
}
////---------------------------------------------------------------------
//void OutputTest::GenerateContexts(){
//	//std::ostream &os = std::cout;
//	std::ofstream os("XMLDemoOutput.xml");
//	if(!os){
//		std::cerr << "Cannot open XMLDemoOutput.xml" << std::endl;
//		CPPUNIT_ASSERT_MESSAGE("Cannot open XMLDemoOutput.xml", false);
//		return;
//	}
//
//	typedef
//        Loki::TL::
//        MakeTypelist<
//            App::HMI,
//            Radio::Receiver,
//            Radio::Amplifier,
//            Radio::Verkehrsfunk
//                    >
//    ::Result Components;
//
//    typedef Radio::RadioLuxus Context;
//    typedef CS<Boards::Board1, LPC214x::LPC2148> Platform;
//
//    os << std::endl;
//    XML::XMLContexts<Context, Components, Platform>::print(os);
//    os << std::endl;
//}
////---------------------------------------------------------------------
//void OutputTest::DemoPrintCell(){
//	std::ostream& os = std::cout;
//	typedef CS<HAL::PinConnectBlock, LPC214x::LPC2148> CSContext;
//	os << std::endl;
//	XML::XMLCell<CSContext, 1>::print(os);
//
//	typedef DD<
//			CS<Radio::Receiver, Radio::RadioLuxus>,
//			CS<HAL::PinConnectBlock, LPC214x::LPC2148>
//	>DDContext;
//
//	os << std::endl;
//	XML::XMLCell<DDContext, 1>::print(os);
//}
////---------------------------------------------------------------------
//void OutputTest::DemoPrintColumnsFromContext(){
//	std::ostream& os = std::cout;
//	typedef Radio::RadioLuxus Columns;
//	os << std::endl;
//	XML::XMLColumns<Columns>::print(os);
//}
////---------------------------------------------------------------------
//void OutputTest::DemoPrintColumnsFromTypeList(){
//	std::ostream& os = std::cout;
//    typedef
//        Loki::TL::
//        MakeTypelist<
//            App::HMI,
//            Radio::Receiver,
//            Radio::Amplifier,
//            Radio::Verkehrsfunk
//                    >
//    ::Result Columns;
//	os << std::endl;
//	XML::XMLColumns<Columns>::print(os);
//}
////---------------------------------------------------------------------
//void OutputTest::DemoPrintContextFromTypelist(){
//	std::stringstream s;
//
//	std::ostream& os = s;
//    typedef
//        Loki::TL::
//        MakeTypelist<
//        	App::HMI,
//            Radio::Receiver,
//            Radio::Amplifier,
//            Radio::Verkehrsfunk
//                    >
//    ::Result Rows;
//	typedef Radio::RadioLuxus Context;
//
//	os << std::endl;
//	XML::XMLContext<Context, Rows>::print(os);
//	std::cout << std::endl << "erzeugter XML String:" << std::endl;
//	std::cout << s.str() << std::endl;
//}
////---------------------------------------------------------------------
//void OutputTest::DemoPrintContextFromContext(){
//	std::ostream& os = std::cout;
//	typedef Radio::RadioLuxus Context;
//    typedef CS<Boards::Board1, LPC214x::LPC2148> Rows;
//	os << std::endl;
//	XML::XMLContext<Context, Rows>::print(os);
//}
////---------------------------------------------------------------------
//void OutputTest::DemoPrintCSContextFromCSContext(){
//	std::ostream& os = std::cout;
//	typedef CS<App::HMI, Radio::RadioLuxus> Context;
//
//    typedef CS<Boards::Board1, LPC214x::LPC2148> Rows;
//	os << std::endl;
//	XML::XMLContext<Context, Rows>::print(os);
//}
////---------------------------------------------------------------------
//void OutputTest::GenerateRadioTable(){
//	std::ostream &os = std::cout;
//    typedef
//        Loki::TL::
//        MakeTypelist<
//            App::HMI,
//            Radio::Receiver,
//            Radio::Amplifier,
//            Radio::Verkehrsfunk
//                    >
//    ::Result Rows;
//
//    typedef Radio::RadioAdvanced Context;
//
//    XML::XMLContext<Context, Rows>::print(os);
//    os << std::endl;
//}


