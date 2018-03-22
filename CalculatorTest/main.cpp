#include "../Calculator/Calculator.h"
#include "cppunit/TestFixture.h"
#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestRunner.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TextOutputter.h"
#include "cppunit/XmlOutputter.h"
#include "cppunit/BriefTestProgressListener.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

#include "cppunit/TextTestRunner.h"

class CalculatorTestFixture : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(CalculatorTestFixture);
	CPPUNIT_TEST(testAdd);
	CPPUNIT_TEST(testSub);
	CPPUNIT_TEST_SUITE_END();

public:
	virtual void setUp() override
	{
		m_calculator = new Calculator();
	}

	virtual void tearDown() override
	{
		delete m_calculator; m_calculator = nullptr;
	}

public:
	void testAdd()
	{
		CPPUNIT_ASSERT(3 == m_calculator->add(1, 2));
	}

	void testSub()
	{
		CPPUNIT_ASSERT(1 == m_calculator->sub(2, 1));
	}

private:
	Calculator *m_calculator;
};

CPPUNIT_TEST_SUITE_REGISTRATION(CalculatorTestFixture);

int main()
{
	CppUnit::TestRunner runner;
	runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());

	CppUnit::TestResult result;

	CppUnit::BriefTestProgressListener progressListener;
	result.addListener(&progressListener);

	CppUnit::TestResultCollector resultCollector;
	result.addListener(&resultCollector);

	runner.run(result);

	// ��ӡ������̨
	CppUnit::TextOutputter textOutputter(&resultCollector, std::cout);
	textOutputter.write();

	// ��ӡ�� xml �ļ����Ա� xUnit �������
	std::ofstream fout("TEST-Calculator.xml");
	if (fout)
	{
		CppUnit::XmlOutputter xmlOutputter(&resultCollector, fout);
		xmlOutputter.write();
		fout.close();
	}

	// ���� 0 ��ʾ�ɹ�
	return resultCollector.wasSuccessful() ? 0 : 1;
}