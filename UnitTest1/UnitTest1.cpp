#include "pch.h"
#include "CppUnitTest.h"
#include "../12_4/12_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL;
			insert(first, 5);
			Assert::AreEqual(first->info, 5);

		}
	};
}
