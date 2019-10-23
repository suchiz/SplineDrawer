#ifndef BSPLINE_H
#define BSPLINE_H

#include <vector>
#include <iostream>
#include <assert.h>
#include <sstream>
#include "point.h"

enum class KVType {UNIFORM, OPEN_UNIFORM, NON_UNIFORM};

class BSpline{
private:
	//ATTRIBUTES
	std::vector<Point> controlPointsVect;
	std::vector<float> knotVect;
	KVType knotVectType;
	int order = 0;
	
	//METHODS
	void checkParameters();
	int getIndexInterestPoint(float u);
	void computeKnotVect(KVType knotVectType, int order);
	
public:
	//CONSTRUCTOR
	BSpline(std::vector<Point> controlPointsVect, KVType knotVectType, int order);
	
	//METHODS
	void draw(float du);
	std::vector<Point>  computePoint(float du);
	
	//DEBUG
	void printKnotVect();
	void printControlPointsVect();
	
	//GETTERS
	int getOrder(){ return order;}
	int getDegree(){ return order-1;}
	int getNBControlPoints(){ return controlPointsVect.size();}
	std::vector<Point> getControlPointsVect(){ return controlPointsVect;}
	std::vector<float> getKnotVect(){ return knotVect;}
};
#endif