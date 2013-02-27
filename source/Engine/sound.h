#include "variable.h"

// GENERAL...
bool initSoundStuff ();
void killSoundStuff ();

// MOD MUSIC...
bool playMOD (int filenum, int channel, int position);
void stopMOD (int channel);
void setMusicVolume (int channel, int volume);
void setDefaultMusicVolume (int volume);

// SAMPLES...
bool startSound (int filenum, bool loopy = false);
void huntKillSound (int filenum);
void setSoundVolume (int filenum, int volume);
void setDefaultSoundVolume (int volume);
bool stillPlayingSound (int filenum);
bool getActiveSounds (stackHandler * sH);
int findSoundChannel (int filenum);

// SOUND Queues...
void addSoundQ(int filenum, int ch);
void replaceSoundQ(int filenum, int ch);
void stopSoundQ(int ch);
void pauseSoundQ(int ch);
void resumeSoundQ(int ch);
void setSoundQLoop(int loopHow, int ch);
void setSoundQVolume (int volume, int ch);
bool getSoundQInfo (stackHandler * sH, int ch);
bool skipSoundQ (int ch);


void loadSounds (FILE * fp);
void saveSounds (FILE * fp);

unsigned int getSoundSource(int index);

