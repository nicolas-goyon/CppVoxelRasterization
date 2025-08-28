#pragma once


struct Voxel{
    unsigned int VoxelID;

    bool IsSolid(){
        return VoxelID == 0;
    };

};