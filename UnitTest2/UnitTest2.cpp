#include "pch.h"
#include "CppUnitTest.h"

#include "../CalcCurse/StringHandle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(DifferentErrorsTest1)

		{

			try {

				StringHandle("");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest2)

		{

			try {

				StringHandle(" ");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest3)

		{

			try {

				StringHandle("02");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest4)

		{

			try {

				StringHandle(".02");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest5)

		{

			try {

				StringHandle("a");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest6)

		{

			try {

				StringHandle("h");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest7)

		{

			try {

				StringHandle("sin");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest8)

		{

			try {

				StringHandle("pin");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest9)

		{

			try {

				StringHandle("pi3");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest10)

		{

			try {

				StringHandle("(");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest11)

		{

			try {

				StringHandle(")");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest12)

		{

			try {

				StringHandle("()");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest13)

		{

			try {

				StringHandle("()()()");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest14)

		{

			try {

				StringHandle("((((()))))");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");
			}

		}

		TEST_METHOD(DifferentErrorsTest15)

		{

			try {

				StringHandle("((2+3)");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest16)

		{

			try {

				StringHandle("(2+3))");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest17)

		{

			try {

				StringHandle("sinsinsin(4)");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentErrorsTest18)

		{

			try {

				StringHandle("1.1.1");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Invalid input");

			}

		}

		TEST_METHOD(DifferentCorrectTest1)

		{

			StringHandle("sqrt(sinh(e))");

		}

		TEST_METHOD(DifferentCorrectTest2)

		{

			StringHandle("e*pi");

		}

		TEST_METHOD(DifferentCorrectTest3)

		{

			try {

				StringHandle("2/((2+3)*2+-10)");

			}

			catch (invalid_argument e) {

				Assert::AreEqual(e.what(), "Computation error");

			}

		}

		TEST_METHOD(DifferentCorrectTest4)

		{

			StringHandle("-64");

		}

		TEST_METHOD(DifferentCorrectTest5)

		{

			StringHandle("sqrt(sinh(e))");

		}

		TEST_METHOD(DifferentCorrectTest6)

		{

			StringHandle("101.0101");

		}

		TEST_METHOD(DifferentCorrectTest7)

		{

			StringHandle("1");

		}

		TEST_METHOD(DifferentCorrectTest8)

		{

			StringHandle("((2-3)/(2+-3))");

		}

		TEST_METHOD(DifferentCorrectTest9)

		{

			StringHandle("-9^-1");

		}
	};
}
