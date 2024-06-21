class vec3{
    public:
        int x,y,z;
        vec3();
        vec3(int x, int y, int z);
    //math
	vec3 operator-(const vec3& vec){
	    return vec3(x-vec.x,y-vec.y,z-vec.z);
	}
	vec3 operator+(const vec3& vec){
	    return vec3(x+vec.x,y+vec.y,z+vec.z);
	}
	vec3 operator*(const vec3& vec){
	    return vec3(x*vec.x,y*vec.y,z*vec.z);
        }
        vec3 operator/(const vec3& vec){
            return vec3(x/vec.x,y/vec.y,z/vec.z);
        }
	vec3 operator-(const int& d){
	    return vec3(x-d,y-d,z-d);
	}
	vec3 operator+(const int& d){
	    return vec3(x+d,y+d,z+d);
	}
	vec3 operator*(const int& d){
	    return vec3(x*d,y*d,z*d);
	}
	vec3 operator/(const int& d){
	    return vec3(x/d,y/d,z/d);
	}
	vec3& operator-=(const vec3& vec){
            x-=vec.x; y-=vec.y; z-=vec.z;
            return *this;
	}
	vec3& operator+=(const vec3& vec){
            x+=vec.x; y+=vec.y; z+=vec.z;
            return *this;
	}
	vec3& operator*=(const vec3& vec){
            x*=vec.x; y*=vec.y; z*=vec.z;
            return *this;
        }
        vec3& operator/=(const vec3& vec){
            x/=vec.x; y/=vec.y; z/=vec.z;
            return *this;
        }
	vec3& operator-=(const int& d){
	    x-=d;y-=d;z-=d;
            return *this;
	}
	vec3& operator+=(const int& d){
	    x+=d;y+=d;z+=d;
            return *this;
	}
	vec3& operator*=(const int& d){
	    x*=d;y*=d;z*=d;
            return *this;
	}
	vec3& operator/=(const int& d){
	    x/=d;y/=d;z/=d;
            return *this;
        }
        bool operator==(const vec3& vec){
            return vec.x==x && vec.y==y && vec.z==z;
        }
        bool operator!=(const vec3& vec){
            return vec.x!=x && vec.y!=y && vec.z!=z;
        }
};
class vec3u{
    public:
	unsigned int x,y,z;
        vec3u();
	vec3u(unsigned int x, unsigned int y, unsigned int z);
    //math
	vec3u operator-(const vec3u& vec){
	    return vec3u(x-vec.x,y-vec.y,z-vec.z);
	}
	vec3u operator+(const vec3u& vec){
	    return vec3u(x+vec.x,y+vec.y,z+vec.z);
	}
	vec3u operator*(const vec3u& vec){
	    return vec3u(x*vec.x,y*vec.y,z*vec.z);
        }
        vec3u operator/(const vec3u& vec){
            return vec3u(x/vec.x,y/vec.y,z/vec.z);
        }
	vec3u operator-(const unsigned int& d){
	    return vec3u(x-d,y-d,z-d);
	}
	vec3u operator+(const unsigned int& d){
	    return vec3u(x+d,y+d,z+d);
	}
	vec3u operator*(const unsigned int& d){
	    return vec3u(x*d,y*d,z*d);
	}
	vec3u operator/(const unsigned int& d){
	    return vec3u(x/d,y/d,z/d);
	}
	vec3u& operator-=(const vec3u& vec){
            x-=vec.x; y-=vec.y; z-=vec.z;
            return *this;
	}
	vec3u& operator+=(const vec3u& vec){
            x+=vec.x; y+=vec.y; z+=vec.z;
            return *this;
	}
	vec3u& operator*=(const vec3u& vec){
            x*=vec.x; y*=vec.y; z*=vec.z;
            return *this;
        }
        vec3u& operator/=(const vec3u& vec){
            x/=vec.x; y/=vec.y; z/=vec.z;
            return *this;
        }
	vec3u& operator-=(const unsigned int& d){
	    x-=d;y-=d;z-=d;
            return *this;
	}
	vec3u& operator+=(const int& d){
	    x+=d;y+=d;z+=d;
            return *this;
	}
	vec3u& operator*=(const unsigned int& d){
	    x*=d;y*=d;z*=d;
            return *this;
	}
	vec3u& operator/=(const unsigned int& d){
	    x/=d;y/=d;z/=d;
            return *this;
        }
        bool operator==(const vec3& vec){
            return vec.x==x && vec.y==y && vec.z==z;
        }
        bool operator!=(const vec3& vec){
            return vec.x!=x && vec.y!=y && vec.z!=z;
        }
};
class vec3f{
    public:
	float x,y,z;
        vec3f();
	vec3f(float x, float y, float z);
    //math
	vec3f operator-(const vec3f& vec){
	    return vec3f(x-vec.x,y-vec.y,z-vec.z);
	}
	vec3f operator+(const vec3f& vec){
	    return vec3f(x+vec.x,y+vec.y,z+vec.z);
	}
	vec3f operator*(const vec3f& vec){
	    return vec3f(x*vec.x,y*vec.y,z*vec.z);
        }
        vec3f operator/(const vec3f& vec){
            return vec3f(x/vec.x,y/vec.y,z/vec.z);
        }
	vec3f operator-(const float& d){
	    return vec3f(x-d,y-d,z-d);
	}
	vec3f operator+(const float& d){
	    return vec3f(x+d,y+d,z+d);
	}
	vec3f operator*(const float& d){
	    return vec3f(x*d,y*d,z*d);
	}
	vec3f operator/(const int& d){
	    return vec3f(x/d,y/d,z/d);
	}
	vec3f& operator-=(const vec3f& vec){
            x-=vec.x; y-=vec.y; z-=vec.z;
            return *this;
	}
	vec3f& operator+=(const vec3f& vec){
            x+=vec.x; y+=vec.y; z+=vec.z;
            return *this;
	}
	vec3f& operator*=(const vec3f& vec){
            x*=vec.x; y*=vec.y; z*=vec.z;
            return *this;
        }
        vec3f& operator/=(const vec3f& vec){
            x/=vec.x; y/=vec.y; z/=vec.z;
            return *this;
        }
	vec3f& operator-=(const float& d){
	    x-=d;y-=d;z-=d;
            return *this;
	}
	vec3f& operator+=(const float& d){
	    x+=d;y+=d;z+=d;
            return *this;
	}
	vec3f& operator*=(const float& d){
	    x*=d;y*=d;z*=d;
            return *this;
	}
	vec3f& operator/=(const float& d){
	    x/=d;y/=d;z/=d;
            return *this;
        }
        bool operator==(const vec3f& vec){
            return vec.x==x && vec.y==y && vec.z==z;
        }
        bool operator!=(const vec3f& vec){
            return vec.x!=x && vec.y!=y && vec.z!=z;
        }
};
class vec3d{
    public:
	double x,y,z;
        vec3d();
	vec3d(double x, double y, double z);
    //math
	vec3d operator-(const vec3d& vec){
	    return vec3d(x-vec.x,y-vec.y,z-vec.z);
	}
	vec3d operator+(const vec3d& vec){
	    return vec3d(x+vec.x,y+vec.y,z+vec.z);
	}
	vec3d operator*(const vec3d& vec){
	    return vec3d(x*vec.x,y*vec.y,z*vec.z);
        }
        vec3d operator/(const vec3d& vec){
            return vec3d(x/vec.x,y/vec.y,z/vec.z);
        }
	vec3d operator-(const double& d){
	    return vec3d(x-d,y-d,z-d);
	}
	vec3d operator+(const double& d){
	    return vec3d(x+d,y+d,z+d);
	}
	vec3d operator*(const double& d){
	    return vec3d(x*d,y*d,z*d);
	}
	vec3d operator/(const int& d){
	    return vec3d(x/d,y/d,z/d);
	}
	vec3d& operator-=(const vec3d& vec){
            x-=vec.x; y-=vec.y; z-=vec.z;
            return *this;
	}
	vec3d& operator+=(const vec3d& vec){
            x+=vec.x; y+=vec.y; z+=vec.z;
            return *this;
	}
	vec3d& operator*=(const vec3d& vec){
            x*=vec.x; y*=vec.y; z*=vec.z;
            return *this;
        }
        vec3d& operator/=(const vec3d& vec){
            x/=vec.x; y/=vec.y; z/=vec.z;
            return *this;
        }
	vec3d& operator-=(const double& d){
	    x-=d;y-=d;z-=d;
            return *this;
	}
	vec3d& operator+=(const double& d){
	    x+=d;y+=d;z+=d;
            return *this;
	}
	vec3d& operator*=(const double& d){
	    x*=d;y*=d;z*=d;
            return *this;
	}
	vec3d& operator/=(const double& d){
	    x/=d;y/=d;z/=d;
            return *this;
        }
        bool operator==(const vec3d& vec){
            return vec.x==x && vec.y==y && vec.z==z;
        }
        bool operator!=(const vec3d& vec){
            return vec.x!=x && vec.y!=y && vec.z!=z;
        }
};

class vec2{
    public:
    	int x,y;
        vec2();
	vec2(int x, int y);
    //math
	vec2 operator-(const vec2& vec){
	    return vec2(x-vec.x,y-vec.y);
	}
	vec2 operator+(const vec2& vec){
	    return vec2(x+vec.x,y+vec.y);
	}
	vec2 operator*(const vec2& vec){
	    return vec2(x*vec.x,y*vec.y);
        }
        vec2 operator/(const vec2& vec){
            return vec2(x/vec.x,y/vec.y);
        }
	vec2 operator-(const int& d){
	    return vec2(x-d,y-d);
	}
	vec2 operator+(const int& d){
	    return vec2(x+d,y+d);
	}
	vec2 operator*(const int& d){
	    return vec2(x*d,y*d);
	}
	vec2 operator/(const int& d){
	    return vec2(x/d,y/d);
	}
	vec2& operator-=(const vec2& vec){
            x-=vec.x; y-=vec.y;
            return *this;
	}
	vec2& operator+=(const vec2& vec){
            x+=vec.x; y+=vec.y;
            return *this;
	}
	vec2& operator*=(const vec2& vec){
            x*=vec.x; y*=vec.y;
            return *this;
        }
        vec2& operator/=(const vec2& vec){
            x/=vec.x; y/=vec.y;
            return *this;
        }
	vec2& operator-=(const int& d){
	    x-=d;y-=d;
            return *this;
	}
	vec2& operator+=(const int& d){
	    x+=d;y+=d;
            return *this;
	}
	vec2& operator*=(const int& d){
	    x*=d;y*=d;
            return *this;
	}
	vec2& operator/=(const int& d){
	    x/=d;y/=d;
            return *this;
        }
        bool operator==(const vec2& vec){
            return vec.x==x && vec.y==y;
        }
        bool operator!=(const vec2& vec){
            return vec.x!=x && vec.y!=y;
        }
};
class vec2u{
    public:
    	unsigned int x,y;
        vec2u();
	vec2u(unsigned int x, unsigned int y);
    //math
	vec2u operator-(const vec2u& vec){
	    return vec2u(x-vec.x,y-vec.y);
	}
	vec2u operator+(const vec2u& vec){
	    return vec2u(x+vec.x,y+vec.y);
	}
	vec2u operator*(const vec2u& vec){
	    return vec2u(x*vec.x,y*vec.y);
        }
        vec2u operator/(const vec2u& vec){
            return vec2u(x/vec.x,y/vec.y);
        }
	vec2u operator-(const unsigned int& d){
	    return vec2u(x-d,y-d);
	}
	vec2u operator+(const unsigned int& d){
	    return vec2u(x+d,y+d);
	}
	vec2u operator*(const unsigned int& d){
	    return vec2u(x*d,y*d);
	}
	vec2u operator/(const unsigned int& d){
	    return vec2u(x/d,y/d);
	}
	vec2u& operator-=(const vec2u& vec){
            x-=vec.x; y-=vec.y;
            return *this;
	}
	vec2u& operator+=(const vec2u& vec){
            x+=vec.x; y+=vec.y;
            return *this;
	}
	vec2u& operator*=(const vec2u& vec){
            x*=vec.x; y*=vec.y;
            return *this;
        }
        vec2u& operator/=(const vec2u& vec){
            x/=vec.x; y/=vec.y;
            return *this;
        }
	vec2u& operator-=(const unsigned int& d){
	    x-=d;y-=d;
            return *this;
	}
	vec2u& operator+=(const unsigned int& d){
	    x+=d;y+=d;
            return *this;
	}
	vec2u& operator*=(const unsigned int& d){
	    x*=d;y*=d;
            return *this;
	}
	vec2u& operator/=(const unsigned int& d){
	    x/=d;y/=d;
            return *this;
        }
        bool operator==(const vec2u& vec){
            return vec.x==x && vec.y==y;
        }
        bool operator!=(const vec2u& vec){
            return vec.x!=x && vec.y!=y;
        }
};
class vec2f{
    public:
	float x,y;
        vec2f();
	vec2f(float x, float y);
    //math
	vec2f operator-(const vec2f& vec){
	    return vec2f(x-vec.x,y-vec.y);
	}
	vec2f operator+(const vec2f& vec){
	    return vec2f(x+vec.x,y+vec.y);
	}
	vec2f operator*(const vec2f& vec){
	    return vec2f(x*vec.x,y*vec.y);
        }
        vec2f operator/(const vec2f& vec){
            return vec2f(x/vec.x,y/vec.y);
        }
	vec2f operator-(const float& d){
	    return vec2f(x-d,y-d);
	}
	vec2f operator+(const float& d){
	    return vec2f(x+d,y+d);
	}
	vec2f operator*(const float& d){
	    return vec2f(x*d,y*d);
	}
	vec2f operator/(const float& d){
	    return vec2f(x/d,y/d);
	}
	vec2f& operator-=(const vec2f& vec){
            x-=vec.x; y-=vec.y;
            return *this;
	}
	vec2f& operator+=(const vec2f& vec){
            x+=vec.x; y+=vec.y;
            return *this;
	}
	vec2f& operator*=(const vec2f& vec){
            x*=vec.x; y*=vec.y;
            return *this;
        }
        vec2f& operator/=(const vec2f& vec){
            x/=vec.x; y/=vec.y;
            return *this;
        }
	vec2f& operator-=(const int& d){
	    x-=d;y-=d;
            return *this;
	}
	vec2f& operator+=(const float& d){
	    x+=d;y+=d;
            return *this;
	}
	vec2f& operator*=(const float& d){
	    x*=d;y*=d;
            return *this;
	}
	vec2f& operator/=(const float& d){
	    x/=d;y/=d;
            return *this;
        }
        bool operator==(const vec2f& vec){
            return vec.x==x && vec.y==y;
        }
        bool operator!=(const vec2f& vec){
            return vec.x!=x && vec.y!=y;
        }
};
class vec2d{
    public:
	double x,y;
        vec2d();
	vec2d(double x, double y);
    //math
	vec2d operator-(const vec2d& vec){
	    return vec2d(x-vec.x,y-vec.y);
	}
	vec2d operator+(const vec2d& vec){
	    return vec2d(x+vec.x,y+vec.y);
	}
	vec2d operator*(const vec2d& vec){
	    return vec2d(x*vec.x,y*vec.y);
        }
        vec2d operator/(const vec2d& vec){
            return vec2d(x/vec.x,y/vec.y);
        }
	vec2d operator-(const double& d){
	    return vec2d(x-d,y-d);
	}
	vec2d operator+(const double& d){
	    return vec2d(x+d,y+d);
	}
	vec2d operator*(const double& d){
	    return vec2d(x*d,y*d);
	}
	vec2d operator/(const double& d){
	    return vec2d(x/d,y/d);
	}
	vec2d& operator-=(const vec2d& vec){
            x-=vec.x; y-=vec.y;
            return *this;
	}
	vec2d& operator+=(const vec2d& vec){
            x+=vec.x; y+=vec.y;
            return *this;
	}
	vec2d& operator*=(const vec2d& vec){
            x*=vec.x; y*=vec.y;
            return *this;
        }
        vec2d& operator/=(const vec2d& vec){
            x/=vec.x; y/=vec.y;
            return *this;
        }
	vec2d& operator-=(const double& d){
	    x-=d;y-=d;
            return *this;
	}
	vec2d& operator+=(const double& d){
	    x+=d;y+=d;
            return *this;
	}
	vec2d& operator*=(const double& d){
	    x*=d;y*=d;
            return *this;
	}
	vec2d& operator/=(const double& d){
	    x/=d;y/=d;
            return *this;
        }
        bool operator==(const vec2d& vec){
            return vec.x==x && vec.y==y;
        }
        bool operator!=(const vec2d& vec){
            return vec.x!=x && vec.y!=y;
        }
};

class trform3{
    public:
	vec3f pos{0,0,0};
	vec3f rot{0,0,0};
	vec3f scl{1,1,1};

        vec3f glpos{0,0,0};
	trform3();
};
class trform3d{
    public:
	vec3d pos{0,0,0};
	vec3d rot{0,0,0};
	vec3d scl{1,1,1};

        vec3d glpos{0,0,0};
	trform3d();
};
class trform2{
    public:
	vec2f pos{0,0};
	vec2f rot{0,0};
	vec2f scl{1,1};

        vec2f glpos{0,0};
	trform2();
};
class trform2d{
    public:
	vec2d pos{0,0};
	vec2d rot{0,0};
	vec2d scl{1,1};

        vec2d glpos{0,0};
	trform2d();
};


float rad_to_deg(float rad);
float deg_to_rad(float deg);


vec3f calc_dot_global(trform3& mesh, vec3f& pos);
vec3f calc_dot_local(trform3 local, vec3f pos);
