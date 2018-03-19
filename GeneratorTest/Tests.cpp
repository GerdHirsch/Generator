/*
 * Tests.cpp
 *
 *  Created on: 23.12.2011
 *      Author: Gerd
 */
#include <TestsDoubleDispatch/DDComponentTest.h>
#include <TestsComponent/ComponentTest.h>
#include <TestsContext/ContextTest.h>
#include <TestsContext/CustomizedContexts.h>
#include <TestsContext/GetSelectorTest.h>
#include <TestsContext/BaseTypeTest.h>
#include <TestsOutput/OutputTest.h>
#include <TestsReplaceBaseType/ReplaceBaseTypeTest.h>
//==================================================================
// Tests
CPPUNIT_TEST_SUITE_REGISTRATION (ReplaceBaseTypeTest);
CPPUNIT_TEST_SUITE_REGISTRATION (DDComponentTest);
CPPUNIT_TEST_SUITE_REGISTRATION (ComponentTest);
CPPUNIT_TEST_SUITE_REGISTRATION (ContextTest);
CPPUNIT_TEST_SUITE_REGISTRATION (CustomizedContexts);
CPPUNIT_TEST_SUITE_REGISTRATION (BaseTypeTest);
CPPUNIT_TEST_SUITE_REGISTRATION (OutputTest);
CPPUNIT_TEST_SUITE_REGISTRATION (GetSelectorTest);
//==================================================================



