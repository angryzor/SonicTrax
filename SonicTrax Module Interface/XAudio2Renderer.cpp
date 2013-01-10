#include "StdAfx.h"
#include "XAudio2Renderer.h"


namespace Rendering
{
	XAudio2Renderer::XAudio2Renderer(void) : xa(NULL), our_cb(*this), readBuf_(0), writeBuf_(0), samplesFed_(0)
	{
		CoInitializeEx(NULL,COINIT_MULTITHREADED);

		InitializeCriticalSection(&cs);

		if(FAILED(XAudio2Create(&xa)))
			return;

		if(FAILED(xa->CreateMasteringVoice(&xamv,1,11025)))
		{
			xa->Release();
			return;
		}



		WAVEFORMATEX e;
		memset(&e,0,sizeof(WAVEFORMATEX));
		e.wFormatTag = WAVE_FORMAT_IEEE_FLOAT;
		e.nChannels = 1;
		e.nSamplesPerSec = 11025;
		e.wBitsPerSample = 32;
		e.nBlockAlign = e.nChannels * (e.wBitsPerSample / 8);
		e.nAvgBytesPerSec = e.nSamplesPerSec * e.nBlockAlign;
		e.cbSize = 0;

		if(FAILED(xa->CreateSourceVoice(&xasv,&e,0,2.0f,&our_cb)))
		{
			xamv->DestroyVoice();
			xa->Release();
			return;
		}

		xasv->Start();
	}


	XAudio2Renderer::~XAudio2Renderer(void)
	{
		DeleteCriticalSection(&cs);
	}


	void XAudio2Renderer::EmitSoundValue(float val)
	{
		EnterCriticalSection(&cs);

		bufs_[writeBuf_][samplesFed_] = val;
		samplesFed_ = (samplesFed_ + 1) % bufLen_;

		if(samplesFed_ == 0)
		{
			XAUDIO2_BUFFER b;
			memset(&b,0,sizeof(XAUDIO2_BUFFER));
			b.AudioBytes = bufLen_ * 4;
			b.pAudioData = (BYTE*)bufs_[writeBuf_];

			xasv->SubmitSourceBuffer(&b);
			writeBuf_ = (writeBuf_ + 1) % numBufs_;
		}

		LeaveCriticalSection(&cs);
	}


	bool XAudio2Renderer::CanEmitNext()
	{
		return writeBuf_ != readBuf_;
	}
}
