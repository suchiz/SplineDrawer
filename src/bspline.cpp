#include "../lib/bspline.h"

BSpline::BSpline(std::vector<Point> controlPointsVect, KVType knotVectType, int order){
	this->controlPointsVect = controlPointsVect;
	this->knotVectType = knotVectType;
	this->order = order;
	checkParameters();
	computeKnotVect(knotVectType, order);
}

void BSpline::checkParameters(){
	assert(getNBControlPoints()>=order);
	assert(order > 1);
}

Point BSpline::computePoint(float u){
	int offset = getIndexInterestPoint(u);
	std::vector<Point> interestPointsVect;
	
	for (int i = 0; i < this->order; ++i) 
		interestPointsVect.push_back(controlPointsVect[i+offset]);
	
	int k = this->order;
	for (int j = 0; j < this->order-1; ++j){
		for (int i = 0; i < k-1; ++i){
			float denom = knotVect[offset+k+i] - knotVect[offset+1+i];
			interestPointsVect[i] = interestPointsVect[i] * ((knotVect[offset+k+i] - u) / denom) + 
							interestPointsVect[i+1] * ((u - knotVect[offset+1+i]) / denom);
		}
		--k;
		++offset;
	}
 	return interestPointsVect[0];
}

void BSpline::draw(float du){
	std::vector<Point> curvePoints;
	if (this->knotVectType == KVType::UNIFORM)
		for (float u = this->order-1; u < getNBControlPoints(); u+=du)
			curvePoints.push_back(computePoint(u));
	else if (this->knotVectType == KVType::OPEN_UNIFORM)
		for (float u = this->order-1-this->getDegree(); u < getNBControlPoints()-this->getDegree(); u+=du)
			curvePoints.push_back(computePoint(u));
		
	std::stringstream ss;
	ss << "python src/drawcurve.py ";
	for (int i = 0; i < this->controlPointsVect.size(); ++i)
		ss << "[" << this->controlPointsVect[i].x << "," << 
		this->controlPointsVect[i].y << "," <<
		this->controlPointsVect[i].z << "]" << "-";
	ss << "+";
	for (int i = 0; i < curvePoints.size(); ++i)
		ss << "[" << curvePoints[i].x << "," << 
				 curvePoints[i].y << "," <<
				 curvePoints[i].z << "]" << "-";
	std::string str = ss.str();
	const char *command = str.c_str();
	system(command);
}

void BSpline::printControlPointsVect(){
	for (int i = 0; i < this->controlPointsVect.size(); ++i)
		std::cout << "[" << this->controlPointsVect[i].x << "," << 
				this->controlPointsVect[i].y << "," <<
				this->controlPointsVect[i].z << "]" << std::endl;
}

void BSpline::printKnotVect(){
	for (int i = 0; i < this->knotVect.size(); ++i)
		std::cout << this->knotVect[i];
	std::cout<<std::endl;
}


int BSpline::getIndexInterestPoint(float u){
	int offset = 0;
	for (int i = this->order; knotVect[i] < u; ++i)
		++offset;
	return offset;
}

void BSpline::computeKnotVect(KVType knotVectType, int order){
	if (knotVectType == KVType::UNIFORM){
		for (int i = 0; i < getNBControlPoints()+order; ++i)
			this->knotVect.push_back(i);
	} else if (knotVectType == KVType::OPEN_UNIFORM){
		int val = 1;
		for (int i = 0; i < getNBControlPoints()+order; ++i)
			if (i < order){
				this->knotVect.push_back(0);
			} else if (i < getNBControlPoints()) {
				this->knotVect.push_back(val);
				++val;
			} else {
				this->knotVect.push_back(val);
			}

	} else {
		std::cout << "Not available yet" << std::endl;
	}
}


