#ifndef TENSOR_PRODUCT_H
#define TENSOR_PRODUCT_H

#include "../lib/bspline.h"

class TensorProduct{
private:
	//ATTRIBUTES
	std::vector<Point> controlPointsVect;
	std::pair<int, int> size;
	KVType knotVectType;
	int order;
	
	//METHODS
	void checkParameters();
	std::pair<std::vector<std::vector<Point>>, std::vector<std::vector<Point>>> computePoint(float du, float dv);
	
public:
	//CONSTRUCTOR
	TensorProduct(std::vector<Point> controlPoints, std::pair<int, int> size, KVType knotVectType, int order);
	
	//METHODS
	void draw(float du, float dv);
	
	//GETTERS
	int getOrder(){ return order;}
	std::pair<int,int> getSize(){ return size;}
	int getNBControlPoints(){ return controlPointsVect.size();}
	std::vector<Point> getControlPointsVect(){ return controlPointsVect;}
	std::vector<Point> getGuidelinePoints(int ind);
	std::vector<Point> getGeneratrixPoints(int ind, std::vector<std::vector<Point>> guidelinesVect);
};

#endif