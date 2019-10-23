#include "../lib/tensorproduct.h"

TensorProduct::TensorProduct(std::vector<Point> controlPoints, std::pair<int, int> size, KVType knotVectType, int order){
	this->order = order;
	this->size = size;
	this->controlPointsVect = controlPoints;
	this->knotVectType = knotVectType;
	checkParameters();
}

std::pair<std::vector<std::vector<Point>>, std::vector<std::vector<Point>>> TensorProduct::computePoint(float du, float dv){
	std::vector<std::vector<Point>> guidelinesVect(this->size.first);
	
	for (int i = 0; i < this->size.first; ++i){
		BSpline guideSpline = BSpline(getGuidelinePoints(i), this->knotVectType, this->order);
		for (float u = guideSpline.getDegree(); u < guideSpline.getNBControlPoints(); u+=du)
			guidelinesVect[i].push_back(guideSpline.computePoint(u));
	}
	std::vector<std::vector<Point>> generatrixVect(guidelinesVect[0].size());
	for (int i = 0; i < guidelinesVect[0].size(); ++i){
		BSpline generatrixSpline = BSpline(getGeneratrixPoints(i, guidelinesVect), this->knotVectType, this->order);
		for (float v = generatrixSpline.getDegree(); v < generatrixSpline.getNBControlPoints(); v+=dv)
			generatrixVect[i].push_back(generatrixSpline.computePoint(v));
	}
	
	return std::pair<std::vector<std::vector<Point>>, std::vector<std::vector<Point>>> {guidelinesVect, generatrixVect};
}

std::vector<Point> TensorProduct::getGuidelinePoints(int ind){
	std::vector<Point> controlPointGuideline;
	for (int i = 0; i < this->size.second; ++i)
		controlPointGuideline.push_back(this->controlPointsVect[ind*this->size.second+i]);
	return controlPointGuideline;
}

std::vector<Point> TensorProduct::getGeneratrixPoints(int ind, std::vector<std::vector<Point>> guidelinesVect){
	std::vector<Point> controlPointsGeneratrix;
	for (int i = 0; i < this->size.first; ++i)
		controlPointsGeneratrix.push_back(guidelinesVect[i][ind]);
	return controlPointsGeneratrix;
}

void TensorProduct::checkParameters(){
	assert(getNBControlPoints() == size.first*size.second);
}

void TensorProduct::draw(float du, float dv){
	std::pair<std::vector<std::vector<Point>>, std::vector<std::vector<Point>>> calculatedPoints = computePoint(du, dv);
	std::stringstream ss;
	ss << "python src/drawsurface.py ";
	for (int i = 0; i < getNBControlPoints(); ++i)
		ss << "[" << this->controlPointsVect[i].x << "," << 
		this->controlPointsVect[i].y << "," <<
		this->controlPointsVect[i].z << "]" << "/";
	ss << "+";
	for (int i = 0; i < this->size.first; ++i)
		for (int j = 0; j < calculatedPoints.first[0].size(); ++j)
		ss << "[" << calculatedPoints.first[i][j].x << "," << 
		calculatedPoints.first[i][j].y << "," <<
		calculatedPoints.first[i][j].z << "]" << "/";
	ss << "+";
	for (int i = 0; i < calculatedPoints.first[0].size(); ++i)
		for (int j = 0; j < calculatedPoints.second[i].size(); ++j)
			ss << "[" << calculatedPoints.second[i][j].x << "," << 
			calculatedPoints.second[i][j].y << "," <<
			calculatedPoints.second[i][j].z << "]" << "/";
	ss << "+"<<size.first << "/" << size.second;
	std::string str = ss.str();
	const char *command = str.c_str();
	system(command);
}