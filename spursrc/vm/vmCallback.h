/* Automatically generated by
	CCodeGeneratorGlobalStructure VMMaker.oscog-eem.612 uuid: 54335642-7834-48fb-936d-b567fb9857b3
 */

#define VM_CALLBACK_INC 1

typedef struct _VMCallbackContext {
	void *thunkp;
	long *stackp;
	long *intregargsp;
	double *floatregargsp;
	void *savedCStackPointer;
	void *savedCFramePointer;
	union {
							long valword;
							struct { int low, high; } valleint64;
							struct { int high, low; } valbeint64;
							double valflt64;
							struct { void *addr; long size; } valstruct;
						}	rvs;
	jmp_buf	trampoline;
	jmp_buf	savedReenterInterpreter;
 } VMCallbackContext;

/* The callback return type codes */
#define retword 1
#define retword64 2
#define retdouble 3
#define retstruct 4


