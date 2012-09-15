#include <vlc/vlc.h>
#include <QString>
#include <iostream>
#include "Video.h"

Video::Video(WId windid, std::string flux) {
	this->windid = windid;
	this->flux = flux;
}

Video::~Video() {
	/* Stop playing */
	libvlc_media_player_stop(mp);

	/* Free the media_player */
	libvlc_media_player_release(mp);

	libvlc_release(inst);
}

void Video::start() {
	std::cout << "flux:" << flux << std::endl;

	/* Load the VLC engine */
	inst = libvlc_new(0, NULL);
	mp = libvlc_media_player_new(inst);

	/* On ouvre le flux "flux.toAscii()". Peut être : ftp://, http://, file://, v4l://, etc... */
	m = libvlc_media_new_location(inst, flux.c_str());

	libvlc_media_player_set_media(mp, m);

#if defined(Q_OS_WIN)
	libvlc_media_player_set_hwnd(mp, windid);
#elif defined(Q_OS_MAC)
	libvlc_media_player_set_drawable(mp, windid);
#else //Linux
	libvlc_media_player_set_xwindow(mp, windid);
#endif

	/* No need to keep the media now */
	libvlc_media_release(m);

	/* play the media_player */
	libvlc_media_player_play(mp);
}
