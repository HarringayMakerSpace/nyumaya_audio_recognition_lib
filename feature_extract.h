#ifndef FEATURE_EXTRACT_H
#define FEATURE_EXTRACT_H

#include "./kissfft/tools/kiss_fftr.h"
#include <stdint.h>

class FeatureExtractor{

	public:
		FeatureExtractor();
		~FeatureExtractor();

		int signal_to_mel(const int16_t * const pcm, size_t len,float*result);
		void spectrum(const float*const pcm,float*real,float*imag);
		void fft_test();
		size_t get_melcount();
	private:

		void create_mel_filter();
		void create_hanning_window();

		kiss_fftr_cfg cfg;
		static const size_t melcount = 40;
		const size_t sample_rate = 16000;
		const size_t nfft = 512;
		const size_t datalen = 512;
		const float window_len = 0.03;
		const float shift = 0.01*16000;
		const int lowerf = 20;
		const int upperf = 8000;
		float hann[512];
		float mel_filters[512/2+1][melcount];


};

#endif
