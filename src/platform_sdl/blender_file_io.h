#pragma once
#ifndef PLATFORM_SDL_BLENDER_FILE_IO_HPP
#define PLATFORM_SDL_BLENDER_FILE_IO_HPP

#include "glm/fwd.hpp"
#include "SDL_stdinc.h"

class ParseMesh {
public:
    struct Animation {
        int num_frames;
        int anim_transform_start;
    };
    int num_vert;
    static const int kFloatsPerVert = 3+2+3+4+4;
    float* vert; //Vert data, 3v 2uv 3n 4bone_index 4bone_weight
    int num_index;
    Uint32* indices;
    int num_bones;
    glm::mat4* rest_mats;
    int* bone_parents;
    int num_animations;
    Animation* animations;
    glm::mat4* anim_transforms;
    void Dispose();
    ~ParseMesh();
};

void ParseTestFile(const char* path, ParseMesh* mesh_final);

#endif