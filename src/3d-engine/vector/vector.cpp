#include "vector.hpp"
#include <math.h>
#include <iostream>

vec3::vec3(int x, int y, int z){
    this->x = x; this->y = y; this->z = z;	
}
vec3::vec3(){};
vec3u::vec3u(unsigned int x, unsigned int y, unsigned int z){
    this->x = x; this->y = y; this->z = z;	
}
vec3u::vec3u(){};
vec3f::vec3f(float x, float y, float z){
    this->x = x; this->y = y; this->z = z;
}
vec3f::vec3f(){};
vec3d::vec3d(double x, double y, double z){
    this->x = x; this->y = y; this->z = z;	
}
vec3d::vec3d(){};

vec2::vec2(int x, int y){
    this->x = x; this->y = y;
}
vec2::vec2(){};
vec2u::vec2u(unsigned int x, unsigned int y){
    this->x = x; this->y = y;
}
vec2u::vec2u(){};
vec2f::vec2f(float x, float y){
    this->x = x; this->y = y;
}
vec2f::vec2f(){};
vec2d::vec2d(double x, double y){
    this->x = x; this->y = y;
}
vec2d::vec2d(){};


trform3::trform3(){}
trform3d::trform3d(){}
trform2::trform2(){}
trform2d::trform2d(){}


float rad_to_deg(float rad){
	return (180/M_PI)*rad;
}
float deg_to_rad(float deg){
	return (M_PI/180)*deg;
}

float norm_deg(float angle){
    float an;
    while(angle >= 360){
        angle -= 360;
    }
    if(angle < 0)
        an = 360+angle;
    else
        an = angle;
    return an;
}


vec3f calc_dot_global(trform3& trform, vec3f& pos){
    vec3f vec(0,0,0);
    if(pos.x == 0 && pos.y == 0 && pos.z == 0){
        vec*=trform.scl;
        vec+=trform.pos;
        return vec;
    }else{
        vec2f coef(0,0);
        vec2d vecdot(pos.x, pos.y);
        if(vecdot.x >= 0)
            coef.x = 1;
        else{
            vecdot.x*=-1;
            coef.x = -1;
        }
        if(vecdot.y >= 0)
            coef.y = 1;
        else{
            vecdot.y*=-1;
            coef.y = -1;
        }
        double lengh = sqrt(pow(vecdot.x, 2)+pow(vecdot.y, 2));
        double deg;
        if(lengh != 0){
            deg = rad_to_deg(asin(vecdot.y/lengh));
            vec.x = cos(deg_to_rad(deg+trform.rot.z))*lengh*coef.x;
            vec.y = sin(deg_to_rad(deg+trform.rot.z))*lengh*coef.y; 

            //printf("%f\n",cos(deg_to_rad(deg+trform.rot.z)));
            //printf("%f\n",sin(deg_to_rad(deg+trform.rot.z)));
        }

        vecdot = vec2d(vec.x, pos.z);
        if(vecdot.x >= 0)
            coef.x = 1;
        else{
            vecdot.x*=-1;
            coef.x = -1;
        }
        if(vecdot.y >= 0)
            coef.y = 1;
        else{
            vecdot.y*=-1;
            coef.y = -1;
        }
        lengh = sqrt(pow(vecdot.x, 2)+pow(vecdot.y, 2));
        if(lengh != 0){
            deg = rad_to_deg(asin(vecdot.y/lengh));
            vec.x = cos(deg_to_rad(deg+trform.rot.y))*lengh*coef.x;
            vec.z = sin(deg_to_rad(deg+trform.rot.y))*lengh*coef.y; 

            //printf("%f\n",cos(deg_to_rad(deg+trform.rot.y)));
            //printf("%f\n",sin(deg_to_rad(deg+trform.rot.y)));
        }

        vecdot = vec2d(vec.y, vec.z);
        if(vecdot.x >= 0)
            coef.x = 1;
        else{
            vecdot.x*=-1;
            coef.x = -1;
        }
        if(vecdot.y >= 0)
            coef.y = 1;
        else{
            vecdot.y*=-1;
            coef.y = -1;
        }
        lengh = sqrt(pow(vecdot.x, 2)+pow(vecdot.y, 2));
        if(lengh != 0){
            deg = rad_to_deg(asin(vecdot.y/lengh));
            vec.y = cos(deg_to_rad(deg+trform.rot.x))*lengh*coef.x;
            vec.z = sin(deg_to_rad(deg+trform.rot.x))*lengh*coef.y;   

            //printf("%f\n",cos(deg_to_rad(deg+trform.rot.x)));
            //printf("%f\n",sin(deg_to_rad(deg+trform.rot.x)));

        }
        vec*=trform.scl;
        vec+=trform.pos;
    }
    return vec;
}
vec3f calc_dot_local(trform3 local, vec3f pos){
    vec3f vec(0,0,0);
    if(pos.x != 0 && pos.y != 0 && pos.z != 0){	
        vec2f vecdot(pos.x, pos.y);
        double lenght = sqrt(pow(vecdot.x, 2)+pow(vecdot.y, 2));
        double deg = rad_to_deg(asin(vecdot.y/lenght));

        vec.x = cos(deg_to_rad(deg-(local.rot.x)))*lenght-local.pos.x;
        vec.y = sin(deg_to_rad(deg-(local.rot.y)))*lenght-local.pos.y;

        vec2f vecdot2(pos.y, pos.z);
        double lenght2 = sqrt(pow(vecdot2.x, 2)+pow(vecdot2.y, 2));
        vec.z = sqrt(pow(lenght2, 2)+pow(vec.y, 2))+local.pos.z;
    }else{
        vec=vec+local.pos;
    }
    return vec;
}


