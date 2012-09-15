#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <QWidget>
#include <vlc/vlc.h>


class Video
{
public:
  Video(WId winid, std::string flux);
  ~Video();
  void start();

private:
  WId windid;
  std::string flux;
  libvlc_instance_t * inst;
  libvlc_media_player_t *mp;
  libvlc_media_t *m;


};

#endif // VIDEO_H
