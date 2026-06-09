typedef struct Sim {
	void (*writemem)(Sim* sim, void* buf, size_t size, uvlong addr);
	void (*readmem)(Sim* sim, void* buf, size_t size, uvlong addr);
	int (*getnregs)(Sim* sim);
	uvlong (*readreg)(Sim* sim, int n);
	void (*writereg)(Sim* sim, int n, uvlong data);
	char* (*regname)(Sim* sim, int n);
	int (*getnaux)(Sim* sim);
	uvlong (*readauxraw)(Sim* sim, int n);
	char* (*readaux)(Sim* sim, int n);
	char* (*auxname)(Sim* sim, int n);
	void (*writeauxraw)(Sim* sim, int n, uvlong data);
	void (*writeaux)(Sim* sim, int n, char* fmtdata);
	void step(Sim* sim);
	void (*free)(Sim* sim);
} Sim;

typedef struct Mem Mem;

Mem* createmem(void);
void writemem(Mem* mem, const void* buf, size_t size, uvlong addr);
void readmem(Mem* mem, void* buf, size_t size, uvlong addr);
void freemem(Mem* mem);
