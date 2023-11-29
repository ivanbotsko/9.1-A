#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 9.1/PR 9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestRandomSpecialty)
		{
			// Перевірка, що getRandomSpecialty() повертає коректні значення спеціальностей
			Specialty specialty = getRandomSpecialty();

			Assert::IsTrue(specialty == ComputerScience || specialty == Physics || specialty == Mathematics, L"Invalid specialty returned!");
		}
	};
}
