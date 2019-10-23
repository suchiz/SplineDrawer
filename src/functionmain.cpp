#include "../lib/functionmain.h"

std::vector< Point > getInputSplinePoints(){
	std::vector<Point> pointsVect;
	std::istringstream infile(exec("python src/inputpoints.py"));
	std::string line;
	
	while (std::getline(infile, line)){
		line = line.substr(1,line.length()-2);
		line.erase(std::remove(line.begin(), line.end(), ','), line.end());
		std::istringstream iss(line);
		float x, y;
		if(!(iss >> x >> y)) break;
		pointsVect.push_back(Point(x, y, 0));
	}
	return pointsVect;
}

std::vector< Point > getInputTensorPoints(){
	std::vector<Point> pointsVect;
	std::istringstream infile(exec("python src/inputtensor.py"));
	std::string line;
	
	while (std::getline(infile, line)){
		line = line.substr(1,line.length()-2);
		line.erase(std::remove(line.begin(), line.end(), ','), line.end());
		std::istringstream iss(line);
		float x, y, z;
		if(!(iss >> x >> y >> z)) break;
		pointsVect.push_back(Point(x, y, z));
	}
	return pointsVect;
}

std::__cxx11::string exec(const char* cmd){
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if (!pipe) throw std::runtime_error("popen() failed!");
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
		result += buffer.data();
	return result;
}

std::vector< Point > getDemoBsplinetInputPoints(){
	Point p1 = {0, 0, 0};
	Point p2 = {1, 1, 0};
	Point p3 = {2, 0, 0};
	Point p4 = {3, 4, 0};
	Point p5 = {5, 2, 0};
	Point p6 = {6, 3, 0};
	std::vector<Point> pointsVect = {p1, p2, p3, p4, p5, p6};
	return pointsVect;
}

std::vector< Point > getDemoTensorProductInputPoints(){
	Point p1 = {0, 0, 0};
	Point p2 = {1, 1, 0};
	Point p3 = {2, 0, 0};
	Point p4 = {0, 0, 1};
	Point p5 = {1, 1, 1};
	Point p6 = {2, 0, 1};
	Point p7 = {0, 0, 2};
	Point p8 = {1, 1, 2};
	Point p9 = {2, 0, 2};
	std::vector<Point> pointsVect = {p1, p2, p3, p4, p5, p6, p7, p8, p9};
	return pointsVect;
}
