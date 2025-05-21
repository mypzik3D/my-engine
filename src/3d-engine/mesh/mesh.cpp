#include "mesh.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

triangle::triangle(){
}
mesh::mesh(){
}
dot::dot(vec3f pos){
    this->pos = pos; 
}

triangle* mesh::add_triangle(vec3f pos1, vec3f pos2, vec3f pos3){
    triangle* tri = new triangle;
    dot* dts[3] = {
        new dot{pos1},
        new dot{pos2},
        new dot{pos3}
    };
    for(int i = 0; i < 3; i++){
        bool flag = false;
        for(int a = 0; a < dots.size(); a++){
            if(dts[i]->pos == dots.at(a)->pos){
                delete(dts[i]);
                dts[i] = dots.at(a);
                flag = true;
                break;
            }
        }
        if(!flag)
            dots.push_back(dts[i]);
    }

    tri->dots[0] = dts[0];
    tri->dots[1] = dts[1];
    tri->dots[2] = dts[2];
    triangles.push_back(tri);
    return tri;
}

triangle* mesh::add_triangle(dot* pos1, dot* pos2, dot* pos3){
    triangle* tri = new triangle;
    tri->dots[0] = pos1;
    tri->dots[1] = pos2;
    tri->dots[2] = pos3;
    triangles.push_back(tri);
    return tri;
}
triangle* mesh::add_triangle(dot* pos1, dot* pos2, dot* pos3, sf::Color color){
    triangle* tri = new triangle;
    tri->dots[0] = pos1;
    tri->dots[1] = pos2;
    tri->dots[2] = pos3;
    tri->color = color;
    triangles.push_back(tri);
    return tri;
}
triangle* mesh::add_triangle(dot* pos1, dot* pos2, dot* pos3, vec3f norm, sf::Color color){
    triangle* tri = new triangle;
    tri->dots[0] = pos1;
    tri->dots[1] = pos2;
    tri->dots[2] = pos3;
    tri->normal = norm;
    tri->color = color;
    triangles.push_back(tri);
    return tri;
}



triangle* mesh::add_triangle(vec3f pos1, vec3f pos2, vec3f pos3, vec3f norm){
    triangle* tri = new triangle;
    dot* dts[3] = {
        new dot{pos1},
        new dot{pos2},
        new dot{pos3}
    };  
    for(int i = 0; i < 3; i++){
        bool flag = false;
        for(int a = 0; a < dots.size(); a++){
            if(dts[i]->pos == dots.at(a)->pos){
                delete(dts[i]);
                dts[i] = dots.at(a);
                flag = true;
                break;
            }
        }
        if(!flag)
            dots.push_back(dts[i]);
    }

    tri->dots[0] = dts[0];
    tri->dots[1] = dts[1];
    tri->dots[2] = dts[2];
    tri->normal = norm;
    triangles.push_back(tri);
    return tri;
}

triangle* mesh::add_triangle(vec3f pos1, vec3f pos2, vec3f pos3, vec3f norm, sf::Color color){
    triangle* tri = new triangle;
    dot* dts[3] = {
        new dot{pos1},
        new dot{pos2},
        new dot{pos3}
    };  
    for(int i = 0; i < 3; i++){
        bool flag = false;
        for(int a = 0; a < dots.size(); a++){
            if(dts[i]->pos == dots.at(a)->pos){
                delete(dts[i]);
                dts[i] = dots.at(a);
                flag = true;
                break;
            }
        }
        if(!flag)
            dots.push_back(dts[i]);
    }

    tri->dots[0] = dts[0];
    tri->dots[1] = dts[1];
    tri->dots[2] = dts[2];
    tri->normal = norm;
    tri->color = color;
    triangles.push_back(tri);
    return tri;
}


void mesh::calc_dots(vec3f campos){
    for(int i = 0; i < dots.size(); i++){
        dots.at(i)->iscalc = false;
    }
    vec3f x(1,0,0),y(0,1,0),z(0,0,1);
    ofx = calc_dot_global(this->trform, x);
    ofy = calc_dot_global(this->trform, y);
    ofz = calc_dot_global(this->trform, z);

    for(int i = 0; i < triangles.size(); i++){
        triangles.at(i)->glnorm = (ofx*triangles.at(i)->normal.x+ofy*triangles.at(i)->normal.y+ofz*triangles.at(i)->normal.z);
        vec3f ang1 = norm(campos-(triangles.at(i)->dots[0]->glpos+triangles.at(i)->dots[1]->glpos+triangles.at(i)->dots[2]->glpos)/3);
        vec3f ang2 = triangles.at(i)->glnorm;
 
        float scal = ang1.x*ang2.x+ang1.y*ang2.y+ang1.z*ang2.z;
        float lenght1 = lengh3(ang1);
        float lenght2 = lengh3(ang2);
        float ancos = scal/(lenght1*lenght2);
        float ang = (1-(ancos))*70;
        triangles.at(i)->cmang = vec2f(ang,ancos); 
        for(int j = 0; j < 3; j++){
            if(ancos > 0 && !triangles.at(i)->dots[j]->iscalc){
                triangles.at(i)->dots[j]->glpos = (ofx*triangles.at(i)->dots[j]->pos.x+ofy*triangles.at(i)->dots[j]->pos.y+ofz*triangles.at(i)->dots[j]->pos.z)*this->trform.scl+this->trform.pos;
                triangles.at(i)->dots[j]->iscalc = true;
            }
        }
    }

    old = trform;
}
void mesh::clear(){
    for(int i = 0; i < triangles.size(); i++){
        delete(triangles.at(i));
    }
    delete this;
}

mesh cube(float size, vec3f offset, trform3 trform){
    mesh cube;
    cube.trform = trform;
    cube.add_triangle(
        vec3f(0,size,0)-offset,
        vec3f(size,0,0)-offset,
        vec3f(0,0,0)-offset,
        vec3f(0,0,1)
    );
    cube.add_triangle(
        vec3f(size,0,0)-offset,
        vec3f(0,size,0)-offset,
        vec3f(size,size,0)-offset,
        vec3f(0,0,1)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,0,size)-offset,
        vec3f(0,0,size)-offset,
        vec3f(0,0,-1)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(0,size,size)-offset,
        vec3f(0,0,size)-offset,
        vec3f(0,0,-1)
    );

    cube.add_triangle(
        vec3f(0,0,size)-offset,
        vec3f(0,size,0)-offset,
        vec3f(0,0,0)-offset,
        vec3f(0,1,0)
    );
    cube.add_triangle(
        vec3f(0,size,0)-offset,
        vec3f(0,0,size)-offset,
        vec3f(0,size,size)-offset,
        vec3f(0,1,0)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,size,0)-offset,
        vec3f(size,0,0)-offset,
        vec3f(0,-1,0)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,0,size)-offset,
        vec3f(size,0,0)-offset,
        vec3f(0,-1,0)
    );

    cube.add_triangle(
        vec3f(0,0,size)-offset,
        vec3f(size,0,0)-offset,
        vec3f(0,0,0)-offset,
        vec3f(1,0,0)
    );
    cube.add_triangle(
        vec3f(size,0,0)-offset,
        vec3f(0,0,size)-offset,
        vec3f(size,0,size)-offset,
        vec3f(1,0,0)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,size,0)-offset,
        vec3f(0,size,0)-offset,
        vec3f(-1,0,0)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(0,size,size)-offset,
        vec3f(0,size,0)-offset,
        vec3f(-1,0,0)
    );
    printf("> created cube mesh\n");
    return cube;
}

class material{
    public:
        std::string name;
        float r,g,b,a;
};

void dprint(int level, std::string text){
    for(int i = 0; i < level; i++){
        std::cout << ">";
    }
    std::cout << " " << text << std::endl;
}

 void load_obj_file(const std::string& filename, mesh& mesh, sf::Color defcol){
    dprint(1, "start load object file");
    
    std::ifstream file(filename);
    std::string line;

    bool uvflag=false;

    std::vector<material*> materials;
    std::vector<vec3f*> norms;

    material* matnow=nullptr;
    while(std::getline(file, line)){
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        if(type == "mtllib"){
            std::string namemtl;
            iss >> namemtl;
            std::string mtlfname;
            int countsl = 0;
            for(int i = 0; i < filename.size(); i++){
                if(filename.at(i) == '/')
                    countsl++;
            }
            int prcount = 0;
            for(int i = 0; i < filename.size(); i++){
                mtlfname+=filename.at(i);
                if(filename.at(i) == '/')
                    prcount++;
                if(prcount>=countsl){
                    mtlfname+=namemtl;
                    break;
                }
            }
            std::ifstream mtlf(mtlfname);
            std::cout << "  object use mtl file: " << namemtl << " in dir: " << mtlfname << "\n";
            std::string mline;
            while(std::getline(mtlf, mline)){
                std::istringstream issm(mline);
                std::string mtyp;
                issm >> mtyp;
                material* mat;
                if(mtyp=="newmtl"){
                    mat = new material;
                    issm >> mat->name;
                    std::cout << "  created new material: " << mat->name << "\n"; 
                }else if(mat != nullptr && mtyp=="Kd"){
                    issm >> mat->r >> mat->g >> mat->b;
                    std::cout << "  colors-> r:" << mat->r << ", g:" << mat->g << ", b:" << mat->b << ", alpha:" << mat->a << ";\n";
                }else if(mat != nullptr && mtyp=="d"){
                    issm >> mat->a;
                    materials.push_back(mat);
                    mat = nullptr;
                }
            }
        }else if(type == "v"){
            float x,y,z;
            iss >> x >> y >> z;
            mesh.dots.push_back(new dot(vec3f(x,y,z)));
        }else if(type == "vn"){
            float x,y,z;
            iss >> x >> y >> z;
            norms.push_back(new vec3f(x,y,z));
        }else if(type == "vt" && !uvflag){
            std::cout << "  object use UV - skipped: " << "\n";
            uvflag = true;
        }else if(type == "usemtl"){
            std::string nam;
            iss >> nam;
            for(int i = 0; i < materials.size(); i++){
                if(materials.at(i)->name == nam){
                    matnow = materials.at(i);
                }
            }  
        }else if(type == "f"){
            std::string str;
                int d[3],n=0;
                for(int i = 0; i < 3; i++){
                    iss>>str;
                    std::replace(str.begin(), str.end(), '/', ' ');
                    std::istringstream index_stream(str);
                    int non;
                    index_stream >> d[i];
                    if(i==2){
                        if(uvflag){
                            index_stream >> non;
                            index_stream >> n;
                        }else{
                            index_stream >> n;  
                        }
                    }
                }
                sf::Color color;
                if(matnow != nullptr){
                    color = sf::Color(matnow->r*255,matnow->g*255,matnow->b*255,matnow->a*255);
                }
                else
                    color = defcol;
                mesh.add_triangle(mesh.dots.at(d[0]-1),mesh.dots.at(d[1]-1),mesh.dots.at(d[2]-1), *norms.at(n-1), color); 
        }
    }
    for(int i = 0; i < materials.size(); i++){delete(materials.at(i));}
    materials.clear();
    for(int i = 0; i < norms.size(); i++){delete(norms.at(i));}
    norms.clear();
    std::cout << "  in mesh: " << mesh.dots.size() << " vertices, " << mesh.triangles.size() << " triangles\n";
    dprint(1, "mesh sucsessfull loaded!");
}
