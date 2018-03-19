#ifndef __OUTPUT_TEST_H_
#define __OUTPUT_TEST_H_

#include "../GeneratorTestApp.h"
#include <Generator/Tools.h>
#include <Generator/XMLPrinters.h>
#include <Generator/XMLOutput.h>

#include <LPC214x/Types.h>
#include <LPC214x/Components.h>

#include "Selectors.h"
#include "Components.h"


/*
 * diese Tests erzeugen den XML output für alle verfügbaren Components
 * für einen gegebenen Context
 */
class OutputTest : public CPPUNIT_NS::TestFixture  {

	CPPUNIT_TEST_SUITE(OutputTest);
	CPPUNIT_TEST(GenerateLPC4xContextComponentsTable);
	CPPUNIT_TEST(GenerateLPC4xComponentsContextTable);
//	CPPUNIT_TEST(DemoPrintColumnsFromContext);
//	CPPUNIT_TEST(DemoPrintColumnsFromTypeList);
//	CPPUNIT_TEST(DemoPrintCell);
//	CPPUNIT_TEST(DemoPrintContextFromTypelist);
//	CPPUNIT_TEST(DemoPrintContextFromContext);
//	CPPUNIT_TEST(DemoPrintCSContextFromCSContext);
//	CPPUNIT_TEST(GenerateRadioTable);
//	CPPUNIT_TEST(GenerateContexts);
	CPPUNIT_TEST_SUITE_END();

protected:
	void GenerateLPC4xContextComponentsTable();
	void GenerateLPC4xComponentsContextTable();
//	void DemoPrintCell();
//	void DemoPrintColumnsFromContext();
//	void DemoPrintColumnsFromTypeList();
//	void DemoPrintContextFromTypelist();
//	void DemoPrintContextFromContext();
//	void DemoPrintCSContextFromCSContext();
//	void DemoPrintComponent();
//	void GenerateRadioTable();
//	void GenerateContexts();
};

#endif /* __OUTPUT_TEST_H_ */
