#include "../lib/bspline.h"
#include "../lib/functionmain.h"
#include "../lib/tensorproduct.h"

int main (int argc, char *argv[]){
	TensorProduct surface = TensorProduct(getInputTensorPoints(), std::pair<int, int> {3,3}, KVType::OPEN_UNIFORM, 3);
	surface.draw(0.2, 0.2);
	return 0;
}
