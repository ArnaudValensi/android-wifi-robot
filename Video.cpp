#include "Video.h"
#include <stdio.h>
#include <stdlib.h>
#include <vlc/vlc.h>
#include <QString>

Video::Video(int windid, QString flux)
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

void Video::demarrer()
{
   /* Load the VLC engine */
   inst = libvlc_new (0, NULL);
   mp = libvlc_media_player_new (inst);

   /* On ouvre le flux "flux.toAscii()". Peut être : ftp://, http://, file://, v4l://, etc... */
   m = libvlc_media_new_location (inst, flux.toAscii());

   libvlc_media_player_set_media (mp, m);

   /* On assigne le player à la QFrame ayant l'handler "windid" */
   libvlc_media_player_set_xwindow (mp, windid);

   /* No need to keep the media now */
   libvlc_media_release (m);

   /* play the media_player */
   libvlc_media_player_play (mp);
}
