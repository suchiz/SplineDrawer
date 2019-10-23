#include "../lib/bspline.h"
#include "../lib/functionmain.h"
#include "../lib/tensorproduct.h"

int main (int argc, char *argv[]){
	TensorProduct surface = TensorProduct(getInputTensorPoints(), std::pair<int, int> {4,4}, KVType::UNIFORM, 3);
	surface.draw(0.1, 0.1);
	return 0;
}
