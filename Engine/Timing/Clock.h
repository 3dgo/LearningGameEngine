#pragma once
#include <windows.h>

namespace Timing
{
	class __declspec(dllexport) Clock
	{
		LARGE_INTEGER timeFrequency;
		LARGE_INTEGER timeLastFrame;
		LARGE_INTEGER deltaLastFrame;
		float deltaTime;

	public:

		bool initialize();
		bool shutdown();
		void newFrame();
		float timeElapsedLastFrame() const;
	};
}