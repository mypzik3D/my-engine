#include <memory>
#include <vector>
#include <math.h>
#include "anim.hpp"

std::vector<std::unique_ptr<animation>> animations;

float* delta_time;
void set_delta_time(float* dt){
    delta_time = dt;
}
//-debug----
int get_count_anim(){
	return animations.size();
}
//----------

void animation::calc_transform(){
	float a = *transform_number;
	old_pos = a;
	leight = to - a;
	delay=1/time;
}

void clean_anim(){
	for(int i = 0; i < animations.size(); i++){
		if(!animations.at(i).get()->work){
			animations.erase(animations.begin()+i);
		}
	}
}

float clamp(float x, float lowerlimit = 0.0f, float upperlimit = 1.0f) {
  if (x < lowerlimit) return lowerlimit;
  if (x > upperlimit) return upperlimit;
  return x;
}
float smoothstep (float edge0, float edge1, float x) {
   // Scale, and clamp x to 0..1 range
   x = clamp((x - edge0) / (edge1 - edge0));

   return x * x * (3.0f - 2.0f * x);
}

float straight(float a){
	return a;
}

void update_animations(){
	for(const auto & i : animations){
		if(i.get()->progress>=1){
			i.get()->work = false;
			continue;
		}
		else{
			i.get()->progress+=i.get()->delay;
			if(i.get()->delay >= 1)
				i.get()->delay = 1;

			if(i.get()->grap == graph::smoothly)
				*i.get()->transform_number=i.get()->leight*smoothstep(0,1,i.get()->progress)+i.get()->old_pos;	
			else if(i.get()->grap == graph::straight)
				*i.get()->transform_number=i.get()->leight*straight(i.get()->progress)+i.get()->old_pos;	
		}
	}
	clean_anim();
}

void add_animation(float* transform,float to, float time, graph grap, tanim type){
	auto anim = std::make_unique<animation>();
	anim->grap = grap;
	anim->type = type;
	anim->time = time;
	anim->to = to;
	anim->transform_number = transform;
	anim->calc_transform();
	animations.push_back(std::move(anim));
}

