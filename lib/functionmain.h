#ifndef FUNCTOION_MAIN_H
#define FUNCTOION_MAIN_H

#include <fstream>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sstream>
#include <algorithm>
#include "point.h"

std::string exec(const char* cmd);
std::vector<Point> getInputSplinePoints();
std::vector<Point> getInputTensorPoints();
std::vector<Point> getDemoBsplineInputPoints();
std::vector< Point > getDemoTensorProductInputPoints();

#endif