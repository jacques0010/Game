#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Platformer\Engine\Math\Vec2f.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine::Math;
namespace PlatformerTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Vec2f vector( 1, 1 );
			Assert::AreEqual(vector.x, 1.0f);
			Assert::AreEqual(vector.y, 1.0f);
		}

	};
k