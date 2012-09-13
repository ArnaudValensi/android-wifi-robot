#ifndef VIDEO_H
#define VIDEO_H

#include <QString>
#include <vlc/vlc.h>


class Video
{
public:
    Video(int, QString);
    ~Video();
    void demarrer();

private:
    int windid;
    QString flux;
    libvlc_instance_t * inst;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;


};

#endif // VIDEO_H
