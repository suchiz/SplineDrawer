#include "../lib/bspline.h"
#include "../lib/functionmain.h"
#include "../lib/tensorproduct.h"


int main (int argc, char *argv[]){
	BSpline curve = BSpline(getInputSplinePoints(), KVType::OPEN_UNIFORM, 3);
	curve.draw(0.1);
	return 0;
}
