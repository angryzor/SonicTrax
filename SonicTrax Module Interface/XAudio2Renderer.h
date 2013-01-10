#pragma once
#include "renderer.h"
#include <XAudio2.h>

namespace Rendering
{
	class XAudio2Renderer :
		public Renderer
	{
	public:
		XAudio2Renderer(void);
		virtual ~XAudio2Renderer(void);

		virtual void EmitSoundValue(float val);
		virtual bool CanEmitNext();

	private:
		class SonicTraxCallback : public IXAudio2VoiceCallback
		{
		public:
			SonicTraxCallback(XAudio2Renderer& rndr) : rndr_(rndr) {}
			~SonicTraxCallback() {}
			void __stdcall OnVoiceProcessingPassStart (UINT32 BytesRequired){}
			void __stdcall OnVoiceProcessingPassEnd (){}
			void __stdcall OnStreamEnd (){}
			void __stdcall OnBufferStart (void* pBufferContext){}
			void __stdcall OnBufferEnd (void* pBufferContext)
			{
				EnterCriticalSection(&rndr_.cs);
				rndr_.readBuf_ = (rndr_.readBuf_ + 1) % rndr_.numBufs_;
				LeaveCriticalSection(&rndr_.cs);
			}
			void __stdcall OnLoopEnd (void* pBufferContext){}
			void __stdcall OnVoiceError (void* pBufferContext, HRESULT Error){}
		private:
			XAudio2Renderer& rndr_;
		};

		static const unsigned short numBufs_ = 4;
		static const unsigned int bufLen_ = 1024;

		float bufs_[numBufs_][bufLen_];

		unsigned short readBuf_;
		unsigned short writeBuf_;
		unsigned int samplesFed_;

		IXAudio2* xa;
		IXAudio2MasteringVoice* xamv;
		IXAudio2SourceVoice* xasv;
		SonicTraxCallback our_cb;
		CRITICAL_SECTION cs;
	};
}
