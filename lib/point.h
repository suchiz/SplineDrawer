#ifndef POINT_H
#define POINT_H

struct point_s{
	//ATTRIBUTES
	float x, y, z;
	
	//CONSTRUCTOR
	point_s(float x, float y, float z): x(x), y(y), z(z){}
	
	//OPERATORS
	point_s &operator=(const point_s &p) { this->x=p.x; this->y=p.y; this->z=p.z; return *this;}
	bool operator==(const point_s &p) const { return this->x==p.x && this->y==p.y && this->z==p.z;}
	point_s operator*(const point_s &p) const { return point_s(this->x*p.x, this->y*p.y, this->z*p.z);}
	point_s operator*(const float f) const { return point_s(this->x*f, this->y*f, this->z*f);}
	point_s operator+(const point_s &p) const { return point_s(this->x+p.x, this->y+p.y, this->z+p.z);}
	point_s operator-(const point_s &p) const { return point_s(this->x-p.x, this->y-p.y, this->z-p.z);}
	point_s operator/(const point_s &p) const {
		if (p.x != 0 && p.y != 0 && p.z != 0)
			return point_s(this->x+p.x, this->y+p.y, this->z+p.z); 
	}
};
typedef point_s Point;

#endif