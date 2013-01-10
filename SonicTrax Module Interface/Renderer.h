#pragma once

namespace Rendering
{
	class Renderer
	{
	public:
		Renderer(void);
		virtual ~Renderer(void);

		virtual void EmitSoundValue(float val) = 0;
		virtual bool CanEmitNext() = 0;
	};
}
