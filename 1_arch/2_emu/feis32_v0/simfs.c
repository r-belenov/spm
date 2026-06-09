#include <u.h>
#include <libc.h>
#include <fcall.h>
#include <thread.h>
#include <9p.h>

#include "sim.h"

void startsim(Sim* sim, char* srvname, char* mntpt, int flag)
{
	threadpostmountsrv();
}
