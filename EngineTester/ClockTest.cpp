#include <gtest\gtest.h>
#include <Timing\Clock.h>
#include <QtTest\QtTest>
#include <iostream>
using Timing::Clock;
using std::cout;

TEST(Clock, Initialize)
{
	Clock clock;
	EXPECT_TRUE(clock.initialize());
	EXPECT_TRUE(clock.shutdown());
}

TEST(Clock, FrameTimeMeasuring)
{
#ifdef CLOCK_TEST
	Clock clock;
	EXPECT_TRUE(clock.initialize());

	const int NUM_TEST = 3 + rand() % 10;
	const float THRESHOLD = 0.01f;
	for (int i = 0; i < NUM_TEST; i++)
	{
		cout << ".";
		int thisTestTimeMilliseconds = rand() % 10000;
		float thisTestTimeSeconds = thisTestTimeMilliseconds / 1000.0f;
		clock.newFrame();
		QTest::qSleep(thisTestTimeMilliseconds);
		clock.newFrame();
		float elapsedSeconds = clock.timeElapsedLastFrame();
		EXPECT_NEAR(elapsedSeconds, thisTestTimeSeconds, THRESHOLD);
	}
	clock.newFrame();
	clock.timeElapsedLastFrame();
	EXPECT_TRUE(clock.shutdown());
#endif
}