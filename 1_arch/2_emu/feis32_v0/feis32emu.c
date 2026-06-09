#include <u.h>
#include <libc.h>

#include "simfs.h"
#include "feis32.h"

char* sname = nil;
char* mntpt = "/dev";

void
usage(void)
{
	fprint(2, "usage: %s [ -s sname ] [ -m mntpt ]\n", argv0);
	exits("usage");
}

void
threadmain(int argc, char** argv)
{
	Sim* feis32sim;

	ARGBEGIN{
	case 's':
		sname = EARGF(usage());
		break;
	case 'm':
		mntpt = EARGF(usage());
		break;
	default:
		usage();
	}ARGEND


	feis32sim = createfeis32sim();
	startsim(feis32sim, sname, mntpt, MREPL);
	threadexits(0);
}
