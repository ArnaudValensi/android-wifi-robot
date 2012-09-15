#include <vlc/vlc.h>
#include <QString>
#include <iostream>
#include "Video.h"

Video::Video(WId windid, std::string flux)
{
  this->windid = windid;
  this->flux = flux;
}

Video::~Video()
{
  /* Stop playing */
  libvlc_media_player_stop (mp);

  /* Free the media_player */
  libvlc_media_player_release (mp);

  libvlc_release (inst);
}

void Video::start()
{
  std::cout << "flux:" << flux << std::endl;

  /* Load the VLC engine */
  inst = libvlc_new(0, NULL);
  mp = libvlc_media_player_new(inst);

  /* On ouvre le flux "flux.toAscii()". Peut Ãªtre : ftp://, http://, file://, v4l://, etc... */
  m = libvlc_media_new_location (inst, flux.c_str());

  libvlc_media_player_set_media(mp, m);

  /* On assigne le player Ã  la QFrame ayant l'handler "windid" */
  libvlc_media_player_set_xwindow(mp, reinterpret_cast<unsigned int>(windid));

  /* No need to keep the media now */
  libvlc_media_release(m);

  /* play the media_player */
  libvlc_media_player_play(mp);
}
