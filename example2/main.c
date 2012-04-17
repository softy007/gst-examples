//
// Anton Belka <antonbelka@gmail.com>
//
// RIFF-WAVE
// http://ccrma.stanford.edu/courses/422/projects/WaveFormat/
// http://www.sonicspot.com/guide/wavefiles.html
//

#include <stdio.h>

typedef struct {
	// Wave File Header - RIFF Type Chunk
	char chunkId[4]; // Chunk ID - 4 byte "RIFF" (0x52494646)
	unsigned long chunkSize; // Chunk Data Size - 4 byte
	char format[4]; // RIFF Type - 4 byte "WAVE" (0x57415645)
	// Format Chunk - "fmt"	
	char subchunk1Id[4]; // Chunk Id - 4 byte "fmt " (0x666D7420)
	unsigned long subchunk1Size; // Chunk Data Size - 4 byte
	unsigned short audioFormat; // Compression code
	unsigned short numChannels; // Number of channels
	unsigned long sampleRate; // Sample rate
	unsigned long byteRate; // Average bytes per second
	unsigned short blockAlign; // Block align
	unsigned short bitsRate; // Significant bits per sample
	// Data Chunk - "data"
	char subchunk2Id[4]; // Chunk Id - 4 byte "data" (0x64617461)
	unsigned long subchunk2DataSize; // Chunk Data Size - 4 byte
} WaveHeader;

int main(int argc, char **argv)
{
	FILE * fname;
	WaveHeader wave;
	if (argc < 2) {
		printf("Enter file name .wav\n");
		return 1;
	}
	fname = fopen(argv[1], "rb");
	if (fname == 0) { 
		printf("Can't open file - %s\n",argv[1]);
		return 1; 
	}
	fread(&wave, sizeof(WaveHeader), 1, fname);
	fclose(fname);
	
	printf("%.4s-%.4s\n", wave.chunkId, wave.format);
	printf("Channels: %hi\n", wave.numChannels);
	printf("Sample Rate: %li Hz\n", wave.sampleRate);

	return 0;
}
