
#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\shake\Documents\Visual Studio 2015\Projects\Project1\Project1\worker.cpp"
#include "C:\Users\shake\Documents\Visual Studio 2015\Projects\Project1\Project1\source.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{	

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//Assert::AreEqual(1, 1);
			worker w("dfdf",1213213, 2,"123");
			Assert::AreEqual(w.get_level(), 2);
		}

		TEST_METHOD(TestMethod2)
		{
			//Assert::AreEqual(1, 1);
			worker w("dfdf", 1213213, 2, "123");
			Assert::AreNotEqual(w.get_level(), 3);
		}

		TEST_METHOD(TestMethod3)
		{
			worker w("dfdf", 1213213, 0, "123");
			Assert::AreNotEqual(w.get_level(), 7);
		}
		TEST_METHOD(TestMethod4)
		{
			Assert::AreEqual(0, 0);
		}
		TEST_METHOD(TestMethod5)
		{
			Assert::AreEqual(0, 0);
		}

	};
}