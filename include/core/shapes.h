//Ryan P. Gingery

//This is to create the vertices for each of the shapes being used within the project. 
#pragma once
#include <rendering/types.h>

#include <numbers>
#include <tuple>
#include <vector>

struct Shapes {
    static inline void UpdateNormals(Vertex& p1, Vertex& p2, Vertex& p3) {
        glm::vec3 U = p2.Position - p1.Position;
        glm::vec3 V = p3.Position - p1.Position;

        auto normal = glm::cross(U, V);

        p1.Normal = normal;
        p2.Normal = normal;
        p3.Normal = normal;
    }

    //for the cube light
    static inline std::vector<Vertex> cubeVertices{
        // Front face
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Right face
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Back face
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Left face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 1.f}
        },
        // Top face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 1.f}
        },

        // bottom face
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 0.f}
        },
    };
    static inline std::vector<uint32_t> cubeElements{
        // front face    
        0, 1, 3, 1, 2, 3, 
        // right face
        4, 5, 7, 5, 6, 7, 
        // back face
        8, 9, 11, 9, 10, 11, 
        // left face
        12, 13, 15, 13, 14, 15, 
        // top face
        16, 17, 19, 17, 18, 19, 
        // bottom face
        20, 21, 23, 21, 22, 23 
    };

    //for the 6 sided dice, D6 #0
    static inline std::vector<Vertex> dSixVertices{
        // Front face
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Right face
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Back face
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Left face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 1.f}
        },
        // Top face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 1.f}
        },

        // bottom face
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 0.f}
        },
    };
    static inline std::vector<uint32_t> dSixElements{
        // front face    
        0, 1, 3, 1, 2, 3,
        // right face
        4, 5, 7, 5, 6, 7,
        // back face
        8, 9, 11, 9, 10, 11,
        // left face
        12, 13, 15, 13, 14, 15,
        // top face
        16, 17, 19, 17, 18, 19,
        // bottom face
        20, 21, 23, 21, 22, 23
    };

    //for the 6 sided dice, D6 #1
    static inline std::vector<Vertex> dSix1Vertices{
        // Front face
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Right face
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Back face
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Left face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 1.f}
        },
        // Top face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 1.f}
        },

        // bottom face
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 0.f}
        },
    };
    static inline std::vector<uint32_t> dSix1Elements{
        // front face    
        0, 1, 3, 1, 2, 3,
        // right face
        4, 5, 7, 5, 6, 7,
        // back face
        8, 9, 11, 9, 10, 11,
        // left face
        12, 13, 15, 13, 14, 15,
        // top face
        16, 17, 19, 17, 18, 19,
        // bottom face
        20, 21, 23, 21, 22, 23
    };

    //for the 6 sided dice, D6 #2
    static inline std::vector<Vertex> dSix2Vertices{
        // Front face
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Right face
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Back face
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Left face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 1.f}
        },
        // Top face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 1.f}
        },

        // bottom face
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 0.f}
        },
    };
    static inline std::vector<uint32_t> dSix2Elements{
        // front face    
        0, 1, 3, 1, 2, 3,
        // right face
        4, 5, 7, 5, 6, 7,
        // back face
        8, 9, 11, 9, 10, 11,
        // left face
        12, 13, 15, 13, 14, 15,
        // top face
        16, 17, 19, 17, 18, 19,
        // bottom face
        20, 21, 23, 21, 22, 23
    };

    //for the 6 sided dice, D6 #3
    static inline std::vector<Vertex> dSix3Vertices{
        // Front face
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Right face
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.5f, 0.5f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Back face
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 1.f}
        },
        // Left face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Uv = {1.f, 1.f}
        },
        // Top face
        {
                .Position = {-0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, 0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 0.f}
        },
        {
                .Position = {0.5f, 0.5f, -0.5f},
                .Color = {0.f, 1.f, 0.f},
                .Uv = {1.f, 1.f}
        },

        // bottom face
        {
                .Position = {0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 0.f}
        },
        {
                .Position = {0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {0.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, 0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 1.f}
        },
        {
                .Position = {-0.5f, -0.5f, -0.5f},
                .Color = {0.f, 0.5f, 0.f},
                .Normal = {0, -1, 0},
                .Uv = {1.f, 0.f}
        },
    };
    static inline std::vector<uint32_t> dSix3Elements{
        // front face    
        0, 1, 3, 1, 2, 3,
        // right face
        4, 5, 7, 5, 6, 7,
        // back face
        8, 9, 11, 9, 10, 11,
        // left face
        12, 13, 15, 13, 14, 15,
        // top face
        16, 17, 19, 17, 18, 19,
        // bottom face
        20, 21, 23, 21, 22, 23
    };

    //Cylinder for PENCIL
    static inline std::vector<Vertex> GetUnitCircleVertices(uint32_t sectorCount) {
        float sectorStep = 2.f * std::numbers::pi_v<float> / static_cast<float>(sectorCount);
        float sectorAngle; //radians

        std::vector<Vertex> vertices{};

        for (auto i = 0; i <= sectorCount; i++) {
            sectorAngle = static_cast<float>(i) * sectorStep;
            vertices.push_back({
                .Position = {
                       std::cos(sectorAngle),
                       std::sin(sectorAngle),
                       0
                }
                });
        }

        return vertices;
    };

    // adapted from Songho: http://www.songho.ca/opengl/gl_cylinder.html
    static inline std::tuple<std::vector<Vertex>, std::vector<uint32_t>> BuildSmoothCylinder(uint32_t sectorCount, float baseRadius, float height) {
        std::vector<Vertex> vertices{};
        std::vector<uint32_t> indices{};

        auto unitCircleVertices = GetUnitCircleVertices(sectorCount);

        /*
         *          BUILDING VERTEX ARRAY
         */

         // Build the sides
        for (auto i = 0; i < 2; i++) { 
            float h = -height / 2.f + static_cast<float>(i) * height;
            float t = 1.f - i;      // texCoord

            // loop over all unit circle vertices
            uint32_t vertexIndex{ 0 };
            for (auto &vertex : unitCircleVertices) {
                vertices.push_back({
                       .Position = {
                               vertex.Position.x * baseRadius,
                               vertex.Position.y * baseRadius,
                               h,
                       },
                       .Color = {
                               vertexIndex % 3 == 0 ? 1.f : 0.f,
                               vertexIndex % 3 == 1 ? 1.f : 0.f,
                               vertexIndex % 3 == 2 ? 1.f : 0.f,
                       },
                       .Normal = {
                               vertex.Position.x * baseRadius,
                               vertex.Position.y * baseRadius,
                               vertex.Position.z * baseRadius,
                       },
                       .Uv = {
                               static_cast<float>(vertexIndex) / static_cast<float>(sectorCount),
                               t
                       }
                    });

                vertexIndex++;
            }
        }
        auto baseCenterIndex = vertices.size();
        auto topCenterIndex = baseCenterIndex + sectorCount + 1;

        // Build the top and bottom
        // the bottom half and top half
        for (auto i = 0; i < 2; i++) { 
            float h = -height / 2.f + static_cast<float>(i) * height;
            // -1 to 1, normal value of z
            float nz = -1.f + static_cast<float>(i) * 2;                 

            // center point
            vertices.push_back({
                .Position = { 0, 0, h },
                .Color = {1.f, 1.f, 1.f},
                .Normal = { 0, 0, nz},
                .Uv = {0.5f, 0.5f}
                });

            // loop over all unit circle vertices
            uint32_t vertexIndex{ 0 };
            for (auto &vertex : unitCircleVertices) {
                vertices.push_back({
                    .Position = {
                        vertex.Position.x * baseRadius,
                        vertex.Position.y * baseRadius,
                        h,
                    },
                    .Color = {
                        vertexIndex % 3 == 0 ? 1.f : 0.f,
                        vertexIndex % 3 == 1 ? 1.f : 0.f,
                        vertexIndex % 3 == 2 ? 1.f : 0.f,
                    },
                    .Normal = {
                        0,
                        0,
                        nz,
                    },
                    .Uv = {
                        -vertex.Position.x * 0.5f + 0.5f,
                        -vertex.Position.y * 0.5f + 0.5f
                    }
                    });

                vertexIndex++;
            }
        }

         /////////////////////////////////////////
         //////////BUILDING INDEX ARRAY //////////
         /////////////////////////////////////////


         // elements for side surface

        uint32_t k1 = 0;
        uint32_t k2 = sectorCount + 1;
        for (auto i = 0; i < sectorCount; i++, k1++, k2++) {
            // 2 triangles per sector
            indices.push_back(k1);
            indices.push_back(k1 + 1);
            indices.push_back(k2);

            indices.push_back(k2);
            indices.push_back(k1 + 1);
            indices.push_back(k2 + 1);
        }

        // bottom surface
        for (uint32_t i = 0, k = baseCenterIndex + 1; i < sectorCount; i++, k++) {
            if (i < sectorCount - 1) {
                indices.push_back(baseCenterIndex);
                indices.push_back(k + 1);
                indices.push_back(k);
            }
            else {
                indices.push_back(baseCenterIndex);
                indices.push_back(baseCenterIndex + 1);
                indices.push_back(k);
            }
        }

        for (uint32_t i = 0, k = topCenterIndex + 1; i < sectorCount; i++, k++) {
            if (i < sectorCount - 1) {
                indices.push_back(topCenterIndex);
                indices.push_back(k);
                indices.push_back(k + 1);
            }
            else {
                indices.push_back(topCenterIndex);
                indices.push_back(k);
                indices.push_back(topCenterIndex + 1);
            }
        }

        return { vertices, indices };
    }



    //table to set the scene on
    static inline std::vector<Vertex> tableVertices{
        {
            .Position = {-2.5f, 0.f, 2.f},
            .Color = {0, 1.f, 0},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {2.5f, 0.f, 2.f},
            .Color = {0, 1.f, 0},
            .Uv = {1.f, 0.f},
        },
        {
            .Position = {2.5f, 0.f, -1.f},
            .Color = {0, 1.f, 0},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {-2.5f, 0.f, -1.f},
            .Color = {0, 1.f, 0},
            .Uv = {0.f, 1.f},
        },
    };
    static inline std::vector<uint32_t> tableElements{
        0, 1, 2,
        0, 2, 3
    };

    //Dungeon Master Screen Boards
    static inline std::vector<Vertex> dmScreenMainVertices{
        //inner face 0 1 2 3
        {
            .Position = {-1.f, 0.f, 0.f},
            .Color = {0.5f, 0.5f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.f, 0.f, 0.f},
            .Color = {0.5f, 0.5f, 0.5f},
            .Uv = {1.f, 0.f},

        },
        {
            .Position = {1.f, 1.f, 0.f},
            .Color = {0.5f, 0.5f, 0.5f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {-1.f, 1.f, 0.f},
            .Color = {0.5f, 0.5f, 0.5f},
            .Uv = {0.f, 1.f},
        },
        //right face 4 5 6 7
        {
            .Position = {1.f, 0.f, 0.f},
            .Color = {1.f, 1.f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.f, 0.f, -0.1f},
            .Color = {1.f, 1.f, 0.5f},
            .Uv = {1.f, 0.f},
        },
        {
            .Position = {1.f, 1.f, -0.1f},
            .Color = {1.f, 1.f, 0.5f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {1.f, 1.f, 0.f},
            .Color = {1.f, 1.f, 0.5f},
            .Uv = {0.f, 1.f},
        },
        //top face 8 9 10 11
        {
            .Position = {-1.f, 1.f, 0.f},
            .Color = {1.f, 0.f, 0.f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.f, 1.f, 0.f},
            .Color = {0.5f, 0.5f, 0.5f},
            .Uv = {1.f, 0.f},
        },
        {
            .Position = {1.f, 1.f, -0.1f},
            .Color = {1.f, 0.f, 0.f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {-1.f, 1.f, -0.1f},
            .Color = {1.f, 0.f, 0.f},
            .Uv = {0.f, 1.f},
        },

        //left face 12 13 14 15
        {
            .Position = {-1.f, 0.f, -0.1f},
            .Color = {1.f, 1.f, 1.f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {-1.f, 0.f, 0.f},
            .Color = {1.f, 1.f, 1.f},
            .Uv = {1.f, 0.f},
        },
        {
            .Position = {-1.f, 1.f, 0.f},
            .Color = {1.f, 1.f, 1.f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {-1.f, 1.f, -0.1f},
            .Color = {1.f, 1.f, 1.f},
            .Uv = {0.f, 1.f},
        },
        //back face 16 17 18 19
        {
            .Position = {-1.f, 0.f, -0.1f},
            .Color = {0.f, 0.f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {-1.f, 1.f, -0.1f},
            .Color = {0.f, 0.f, 0.5f},
            .Uv = {1.f, 0.f},
        },
        {
            .Position = {1.f, 1.f, -0.1f},
            .Color = {0.f, 0.f, 0.5f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {1.f, 0.f, -0.1f},
            .Color = {0.f, 0.f, 1.f},
            .Uv = {0.f, 1.f},
        },
        //bottom face 20 21 22 23
        {
            .Position = {-1.f, 0.f, 0.f},
            .Color = {0.f, 0.f, 0.f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.f, 0.f, 0.f},
            .Color = {0.f, 0.f, 0.f},
            .Uv = {1.f, 0.f},
        },
        {
            .Position = {1.f, 0.f, -0.1f},
            .Color = {0.f, 0.f, 0.f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {-1.f, 0.f, -0.1f},
            .Color = {0.f, 0.f, 0.f},
            .Uv = {0.f, 1.f},
        },
    };
    static inline std::vector<uint32_t> dmScreenMainElements {
        //front face
        0, 1, 2,
        0, 2, 3,
        //right face
        4, 5, 6,
        4, 6, 7,
        //top face
        8, 9, 10,
        8, 10, 11,
        //left face
        12, 13, 14,
        12, 14, 15,
        //back face
        16, 17, 18,
        16, 18, 19,
        //bottom face
        20, 21, 22,
        20, 22, 23,
    };

    static inline std::vector<Vertex> dmScreenRightVertices{
        //front face 0 1 2 3
            {
                .Position = {1.f, 0.f, 0.f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {1.95f, 0.f, 0.5f},
                .Color = {1.5f, 1.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {1.95f, 1.f, 0.5f},
                .Color = {0.25f, 1.f, 0.5f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {1.f, 1.f, 0.f},
                .Color = {0.5f, 1.f, 0.f},
                .Uv = {0.f, 1.f},
            },
            //left face 4 5 6 7
            {
                .Position = {1.f, 0.f, 0.f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {1.f, 1.f, 0.f},
                .Color = {0.5f, 1.f, 0.5f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {1.025f, 1.f, -0.1f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {1.025f, 0.f, -0.1f},
                .Color = {0.5f, 1.f, 0.f},
                .Uv = {0.f, 1.f},
            },
            //back face 8 9 10 11
            {
                .Position = {1.025f, 0.f, -0.1f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {1.025f, 1.f, -0.1f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {2.f, 1.f, 0.4f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {2.f, 0.f, 0.4f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {0.f, 1.f},
            },
            //right face 12 13 14 15
            {
                .Position = {2.f, 0.f, 0.4f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {2.f, 1.f, 0.4f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {1.95f, 1.f, 0.5f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {1.95f, 0.f, 0.5f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {0.f, 1.f},
            },
            //top face 16 17 18 19
            {
                .Position = {1.025f, 1.f, -0.1f},
                .Color = {1.f, 0.f, 0.f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {1.f, 1.f, 0.f},
                .Color = {1.5f, 1.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {1.95f, 1.f, 0.5f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {2.f, 1.f, 0.4f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {0.f, 1.f},
            },
            //bottom face 20 21 22 23
            {
                .Position = {1.025f, 0.f, -0.1f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {1.f, 0.f, 0.f},
                .Color = {1.5f, 1.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {1.95f, 0.f, 0.5f},
                .Color = {0.5f, 1.f, 0.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {2.f, 0.f, 0.4f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {0.f, 1.f},
            },
    };
    static inline std::vector<uint32_t> dmScreenRightElements{
        //front face
        0, 1, 2,
        0, 2, 3,
        //left face
        4, 5, 6,
        4, 6, 7,
        //back face
        8, 9, 10,
        8, 10, 11,
        //right face
        12, 13, 14,
        12, 14, 15,
        //top face
        16, 17, 18,
        16, 18, 19,
        //bottom face
        20, 21, 22,
        20, 22, 23
    };

    static inline std::vector<Vertex> dmScreenLeftVertices{
        //front face 0 1 2 3
            {
                .Position = {-1.f, 0.f, 0.f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {-1.f, 1.f, 0.f},
                .Color = {1.5f, 1.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-1.95f, 1.f, 0.5f},
                .Color = {0.25f, 1.f, 0.5f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-1.95f, 0.f, 0.5f},
                .Color = {0.5f, 1.f, 0.f},
                .Uv = {0.f, 1.f},
            },
            //right face 4 5 6 7
            {
                .Position = {-1.f, 0.f, 0.f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {-1.025f, 0.f, -0.1f},
                .Color = {0.5f, 1.f, 0.5f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-1.025f, 1.f, -0.1f},
                .Color = {1.f, 1.f, 0.5f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-1.f, 1.f, 0.f},
                .Color = {0.5f, 1.f, 0.f},
                .Uv = {0.f, 1.f},
            },
            //back face 8 9 10 11
            {
                .Position = {-2.f, 0.f, 0.4f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {-2.f, 1.f, 0.4f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-1.025f, 1.f, -0.1f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-1.025f, 0.f, -0.1f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {0.f, 1.f},
            },
            //left face 12 13 14 15
            {
                .Position = {-2.f, 0.f, 0.4f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {-1.95f, 0.f, 0.5f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-1.95f, 1.f, 0.5f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-2.f, 1.f, 0.4f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {0.f, 1.f},
            },
            //top face 16 17 18 19
            {
                .Position = {-2.f, 1.f, 0.4f},
                .Color = {1.f, 0.f, 0.f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {-1.95f, 1.f, 0.5f},
                .Color = {1.5f, 1.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-1.f, 1.f, 0.f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-1.025f, 1.f, -0.1f},
                .Color = {1.f, 1.f, 0.f},
                .Uv = {0.f, 1.f},
            },
            //bottom face 20 21 22 23
            {
                .Position = {-2.f, 0.f, 0.4f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {-1.95f, 0.f, 0.5f},
                .Color = {0.5f, 1.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-1.f, 0.f, 0.f},
                .Color = {1.5f, 1.f, 0.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-1.025f, 0.f, -0.1f},
                .Color = {0.f, 0.f, 0.5f},
                .Uv = {0.f, 1.f},
            },
    };
    static inline std::vector<uint32_t> dmScreenLeftElements{
        //front face
        0, 1, 2,
        0, 2, 3,
        //left face
        4, 5, 6,
        4, 6, 7,
        //back face
        8, 9, 10,
        8, 10, 11,
        //right face
        12, 13, 14,
        12, 14, 15,
        //top face
        16, 17, 18,
        16, 18, 19,
        //bottom face
        20, 21, 22,
        20, 22, 23
    };

    ///////////////////////////////////////////////////////////////
    //Dungeon Master Screen Face Bolts (pyramids instead of sphere)
    //First is the center bolts on the top and bottom straps
    static inline std::vector<Vertex> centerBoltVertices{
        //Bolt on top strap
            //top face 0 1 2
            {
                .Position = {0.f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.05f, 0.97f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.05f, 0.97f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 3 4 5
            {
                .Position = {0.f, 0.95f, -0.14f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.05f, 0.97f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.05f, 0.93f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //bottom face 6 7 8
            {
                .Position = {0.f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.05f, 0.93f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.05f, 0.93f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
            //left face 9 10 11
            {
                .Position = {0.f, 0.95f, -0.14f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.05f, 0.93f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.05f, 0.97f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
            //========================================//
            //Bolt on bottom strap
            //top face 12 13 14
            {
                .Position = {0.f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.05f, 0.07f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.05f, 0.07f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 15 16 17
            {
                .Position = {0.f, 0.05f, -0.14f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.05f, 0.07f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.05f, 0.03f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //bottom face 18 19 20
            {
                .Position = {0.f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.05f, 0.03f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.05f, 0.03f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
            //left face 21 22 23
            {
                .Position = {0.f, 0.05f, -0.14f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.05f, 0.03f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.05f, 0.07f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
    };
    static inline std::vector<uint32_t> centerBoltElement{
        //top strap bolt
        //top face
        0, 1, 2,
        //right face
        3, 4, 5,
        //bottom face
        6, 7, 8,
        //left face
        9, 10, 11,

        //========================================//
        //Bolt on bottom strap
        12, 13, 14,
        15, 16, 17,
        18, 19, 20,
        21, 22, 23
    };

    //Next, large far left bolts top and bottom
    static inline std::vector<Vertex> farLeftBoltVertices{
        //top strap
            //top face 0 1 2
            {
                .Position = {-0.9f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.95f, 0.97f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.85f, 0.97f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 3 4 5
            {
                .Position = {-0.9f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.85f, 0.97f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.85f, 0.93f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //bottom face 6 7 8
            {
                .Position = {-0.9f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.85f, 0.93f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.95f, 0.93f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
            //left face 9 10 11
            {
                .Position = {-0.9f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.95f, 0.93f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.95f, 0.97f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },

            //========================================//
            //Bolt on bottom strap

            //top face 12 13 14
            {
                .Position = {-0.9f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.95f, 0.07f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.85f, 0.07f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 15 16 17
            {
                .Position = {-0.9f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.85f, 0.07f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.85f, 0.03f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //bottom face 18 19 20
            {
                .Position = {-0.9f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.85f, 0.03f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.95f, 0.03f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
            //left face 21 22 23
            {
                .Position = {-0.9f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.95f, 0.03f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.95f, 0.07f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
    };
    static inline std::vector<uint32_t> farLeftBoltElement{
        //top face
            0, 1, 2,
            //right face
            3, 4, 5,
            //bottom face
            6, 7, 8,
            //left face
            9, 10, 11,

            //========================================//
            //Bolt on bottom strap
            12, 13, 14,
            15, 16, 17,
            18, 19, 20,
            21, 22, 23
    };

    //Next, large far right bolts top and bottom
    static inline std::vector<Vertex> farRightBoltVertices{
        //top strap bolt
            //top face 0 1 2
            {
                .Position = {0.9f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.85f, 0.97f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.95f, 0.97f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 3 4 5
            {
                .Position = {0.9f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.85f, 0.93f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.85f, 0.97f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //bottom face 6 7 8
            {
                .Position = {0.9f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.95f, 0.93f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.85f, 0.93f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
            //left face 9 10 11
            {
                .Position = {0.9f, 0.95f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.95f, 0.97f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.95f, 0.93f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },

            //========================================//
            //Bolt on bottom strap
            //top face 12 13 14
            {
                .Position = {0.9f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.85f, 0.07f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.95f, 0.07f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 15 16 17
            {
                .Position = {0.9f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.85f, 0.03f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.85f, 0.07f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //bottom face 18 19 20
            {
                .Position = {0.9f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.95f, 0.03f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.85f, 0.03f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
            //left face 21 22 23
            {
                .Position = {0.9f, 0.05f, -0.14f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.95f, 0.07f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.95f, 0.03f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
    };
    static inline std::vector<uint32_t> farRightBoltElement{
        //top face
            0, 1, 2,
            //right face
            3, 4, 5,
            //bottom face
            6, 7, 8,
            //left face
            9, 10, 11,

            //========================================//
            //Bolt on bottom strap
            12, 13, 14,
            15, 16, 17,
            18, 19, 20,
            21, 22, 23
    };

    //Now the left center small bolt for top and bottom
    static inline std::vector<Vertex> smallLeftBoltVertices{
        //top strap bolt
            //top face 0 1 2
            {
                .Position = {-0.45f, 0.95f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.475f, 0.96f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.425f, 0.96f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 3 4 5
            {
                .Position = {-0.45f, 0.95f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.425f, 0.96f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.425f, 0.94f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },

            //bottom face 6 7 8
            {
                .Position = {-0.45f, 0.95f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.425f, 0.94f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.475f, 0.94f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //left face 9 10 11
            {
                .Position = {-0.45f, 0.95f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.475f, 0.94f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.475f, 0.96f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },

            //========================================//
            //Bolt on bottom strap
            //top face 12 13 14
            {
                .Position = {-0.45f, 0.05f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.475f, 0.06f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.425f, 0.06f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 15 16 17
            {
                .Position = {-0.45f, 0.05f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.425f, 0.06f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.425f, 0.04f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },

            //bottom face 18 19 20
            {
                .Position = {-0.45f, 0.05f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.425f, 0.04f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.475f, 0.04f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //left face 21 22 23
            {
                .Position = {-0.45f, 0.05f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {-0.475f, 0.04f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {-0.475f, 0.06f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
    };
    static inline std::vector<uint32_t> smallLeftBoltElement{
        //top face
            0, 1, 2,
            //right face
            3, 4, 5,
            //bottom face
            6, 7, 8,
            //left face
            9, 10, 11,

            //========================================//
            //Bolt on bottom strap
            12, 13, 14,
            15, 16, 17,
            18, 19, 20,
            21, 22, 23
    };

    //Now the right center small bolt for top and bottom
    static inline std::vector<Vertex> smallRightBoltVertices{
        //top strap bolt
            //top face 0 1 2
            {
                .Position = {0.45f, 0.95f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.425f, 0.96f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.475f, 0.96f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 3 4 5
            {
                .Position = {0.45f, 0.95f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.425f, 0.94f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.425f, 0.96f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },

            //bottom face 6 7 8
            {
                .Position = {0.45f, 0.95f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.475f, 0.94f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.425f, 0.94f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //left face 9 10 11
            {
                .Position = {0.45f, 0.95f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.475f, 0.96f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.475f, 0.94f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },

            //========================================//
            //Bolt on bottom strap
            //top face 12 13 14
            {
                .Position = {0.45f, 0.05f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.425f, 0.06f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.475f, 0.06f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //right face 15 16 17
            {
                .Position = {0.45f, 0.05f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.425f, 0.04f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.425f, 0.06f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },

            //bottom face 18 19 20
            {
                .Position = {0.45f, 0.05f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.475f, 0.04f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f}

            },
            {
                .Position = {0.425f, 0.04f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f}
            },
            //left face 21 22 23
            {
                .Position = {0.45f, 0.05f, -0.13f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.5f, 1.f}
            },
            {
                .Position = {0.475f, 0.06f, -0.1f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f}
            },
            {
                .Position = {0.475f, 0.04f, -0.1f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f}
            },
    };
    static inline std::vector<uint32_t> smallRightBoltElement{
        //top face
            0, 1, 2,
            //right face
            3, 4, 5,
            //bottom face
            6, 7, 8,
            //left face
            9, 10, 11,

            //========================================//
            //Bolt on bottom strap
            12, 13, 14,
            15, 16, 17,
            18, 19, 20,
            21, 22, 23
    };

    /////////////////////////////////////////////////////////////////
    //Straps that are on the front of the dungeon master screen
    static inline std::vector<Vertex> strapsVertices{
        ////////LEFT BOARD////////
            //top strap 0 1 2 3 
            {
                .Position = {-1.025f, 1.f, -0.11f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {-1.025f, 0.9f, -0.11f},
                .Color = {1.f, 0.f, 0.5f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-2.f, 0.9f, 0.39f},
                .Color = {1.f, 0.f, 1.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-2.f, 1.f, 0.39f},
                .Color = {0.5f, 1.f, 0.5f},
                .Uv = {0.f, 1.f},
            },
            //================
            //bottom strap 4 5 6 7 
            {
                .Position = {-1.025f, 0.f, -0.11f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {-2.f, 0.f, 0.39f},
                .Color = {0.5f, 1.f, 0.5f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-2.f, 0.1f, 0.39f},
                .Color = {1.f, 0.f, 1.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-1.025f, 0.1f, -0.11f},
                .Color = {1.f, 0.f, 0.5f},
                .Uv = {0.f, 1.f},
            },
            ////////CENTER BOARD////////
            //back face top strap 8 9 10 11
            {
                .Position = {1.f, 1.f, -0.11f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {1.f, 0.9f, -0.11f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-1.f, 0.9f, -0.11f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-1.f, 1.f, -0.11f},
                .Color = {1.f, 1.f, 1.f},
                .Uv = {0.f, 1.f},
            },
            //back face bottom strap 12 13 14 15
            {
                .Position = {1.f, 0.1f, -0.11f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {1.f, 0.f, -0.11f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {-1.f, 0.0f, -0.11f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-1.f, 0.1f, -0.11f},
                .Color = {0.f, 0.f, 0.f},
                .Uv = {0.f, 1.f},
            },
            ////////RIGHT BOARD////////
            //================
            //top strap 16 17 18 19
            {
                .Position = {2.f, 1.f, 0.39f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {2.f, 0.9f, 0.39f},
                .Color = {1.f, 0.f, 0.5f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {1.025f, 0.9f, -0.11f},
                .Color = {1.f, 0.f, 1.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {1.025f, 1.f, -0.11f},
                .Color = {0.5f, 1.f, 0.5f},
                .Uv = {0.f, 1.f},
            },
            //================
            //bottom strap 20 21 22 23
            {
                .Position = {2.f, 0.1f, 0.39f},
                .Color = {1.f, 0.5f, 0.5f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = {2.f, 0.f, 0.39f},
                .Color = {0.5f, 1.f, 0.5f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {1.025f, 0.f, -0.11f},
                .Color = {1.f, 0.f, 1.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {1.025f, 0.1f, -0.11f},
                .Color = {1.f, 0.f, 0.5f},
                .Uv = {0.f, 1.f},
            },
    };
    static inline std::vector<uint32_t> strapsElements{
        //left board top
        0, 1, 2,
        0, 2, 3,
        //left board bottom
        4, 5, 6,
        4, 6, 7,
        //center board top
        8, 9, 10,
        8, 10, 11,
        //center board bottom
        12, 13, 14,
        12, 14, 15,
        //right board top 
        16, 17, 18,
        16, 18, 19,
        //right board bottom
        20, 21, 22,
        20, 22, 23
    };

    //DM Screen Paper, Beholder
    static inline std::vector<Vertex> dmPaperVertices{
        {
            .Position = {-0.8f, 0.1f, 0.01f},
            .Color = {0.5f, 0.5f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {-0.08f, 0.1f, 0.01f},
            .Color = {0.5f, 0.5f, 0.5f},
            .Uv = {1.f, 0.f},

        },
        {
            .Position = {-0.08f, 0.95f, 0.01f},
            .Color = {0.5f, 0.5f, 0.5f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {-0.8f, 0.95f, 0.01f},
            .Color = {0.5f, 0.5f, 0.5f},
            .Uv = {0.f, 1.f},
        },
    };
    static inline std::vector<uint32_t> dmPaperElements{
        0, 1, 2,
        0, 2, 3
    };

    //DM Screen Paper, Red Dragon
     //front face 0 1 2 3
    static inline std::vector<Vertex> dmPaper1Vertices{
            {
                .Position = { 1.25f, 0.1f, 0.15f },
                .Color = { 1.f, 0.5f, 0.5f },
                .Uv = { 0.f, 0.f },
            },
            {
                .Position = {1.85f, 0.1f, 0.48f},
                .Color = {1.5f, 1.f, 0.f},
                .Uv = {1.f, 0.f},
            },
            {
                .Position = {1.85f, 0.95f, 0.48f},
                .Color = {0.25f, 1.f, 0.5f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {1.25f, 0.95f, 0.15f},
                .Color = {0.5f, 1.f, 0.f},
                .Uv = {0.f, 1.f},
            },
    };
    static inline std::vector<uint32_t> dmPaper1Elements{
        0, 1, 2,
        0, 2, 3
    };

        //DM Screen Paper, npcs
        //front face 0 1 2 3
    static inline std::vector<Vertex> dmPaper2Vertices{
            {
                .Position = {-1.85f, 0.1f, 0.48f},
                .Color = {1.5f, 1.f, 0.f},
                .Uv = {0.f, 0.f},
            },
            {
                .Position = { -1.25f, 0.1f, 0.15f },
                .Color = { 1.f, 0.5f, 0.5f },
                .Uv = { 1.f, 0.f },
            },
            {
                .Position = {-1.25f, 0.95f, 0.15f},
                .Color = {0.5f, 1.f, 0.f},
                .Uv = {1.f, 1.f},
            },
            {
                .Position = {-1.85f, 0.95f, 0.48f},
                .Color = {0.25f, 1.f, 0.5f},
                .Uv = {0.f, 1.f},
            },
    };
    static inline std::vector<uint32_t> dmPaper2Elements{
        0, 1, 2,
        0, 2, 3
    };


    ////////////////////////////////////////////////////////////////
    //Dungeon Masters Guidebook//
    //Cover
    static inline std::vector<Vertex> coverVertices{
        //Book Front Cover 0 1 2 3
        {
            .Position = {1.1f, 0.115f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 1.f},
        },
        {
            .Position = {1.1f, 0.115f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.85f, 0.115f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 0.f},
        },
        {
            .Position = {1.85f, 0.115f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 1.f},
        },
        
        
        //Book Back Cover 4 5 6 7
        {
            .Position = {1.1f, 0.01f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 1.f},
        },
        {
            .Position = {1.1f, 0.01f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.85f, 0.01f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 0.f},
        },
        {
            .Position = {1.85f, 0.01f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 1.f},
        },

    };
    static inline std::vector<uint32_t> coverElements{
        //Book Front Cover
        0, 1, 2,
        0, 2, 3,
        //Book Back Cover
        0, 1, 2,
        0, 2, 3
    };
    //Spine
    static inline std::vector<Vertex> spineVertices{
        {
            .Position = {1.1f, 0.01f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.1f, 0.01f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 1.f},
        },
        {
            .Position = {1.1f, 0.115f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {1.1f, 0.115f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 0.f},
        },

        

    };
    static inline std::vector<uint32_t> spineElements{
        0, 1, 2,
        0, 2, 3
    };
    //Pages on the book. 
    static inline std::vector<Vertex> paperVertices{
        //Long Side Pages 0 1 2 3
        {
            .Position = {1.85f, 0.01f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.85f, 0.01f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 1.f},
        },
        {
            .Position = {1.85f, 0.115f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {1.85f, 0.115f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 0.f},
        },
        //Book Top Pages 4 5 6 7
        {
            .Position = {1.1f, 0.01f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.1f, 0.115f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 1.f},
        },
        {
            .Position = {1.85f, 0.115f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {1.85f, 0.01f, 0.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 0.f},
        },
        //Book Bottom Pages 8 9 10 11
        {
            .Position = {1.1f, 0.01f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 0.f},
        },
        {
            .Position = {1.85f, 0.01f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {0.f, 1.f},
        },
        {
            .Position = {1.85f, 0.115f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 1.f},
        },
        {
            .Position = {1.1f, 0.115f, 1.7f},
            .Color = {1.f, 0.5f, 0.5f},
            .Uv = {1.f, 0.f},
        },

    };
    static inline std::vector<uint32_t> paperElements{
        //Long Side Pages
        0, 1, 2,
        0, 2, 3,
        //Book Top Pages
        4, 5, 6,
        4, 6, 7,
        //Book Bottom Pages
        8, 9, 10,
        8, 10, 11
    };

    ////////////////////
    //Four sided Dice. D4
    static inline std::vector<Vertex> dFourVertices{
        //Front face
        {               //X      Y      Z
            .Position = {0.f, 0.2f, -0.2f}, //0
            .Color = {0.5f, 0.25f, 1.f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {-0.2f, 0.f, 0.f}, //1
            .Color = {0.5f, 0.5f, 0.25f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {0.2f, 0.f, 0.f}, //2 
            .Color = {0.25f, 1.f, 0.5f},
            .Uv = {1.f, 0.f}
        },

        //Right face.
        {               //X      Y      Z
            .Position = {0.f, 0.2f, 0.2f}, //0
            .Color = {0.5f, 0.25f, 1.f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {0.2f, 0.f, 0.f}, //1
            .Color = {0.5f, 0.5f, 0.25f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {0.f, 0.f, -0.2f}, //2 
            .Color = {0.25f, 1.f, 0.5f},
            .Uv = {1.f, 0.f}
        },
        //Back face
        {               //X      Y      Z
            .Position = {0.f, 0.2f, 0.2f}, //0
            .Color = {0.5f, 0.25f, 1.f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {0.f, 0.f, -0.2f}, //2 
            .Color = {0.25f, 1.f, 0.5f},
            .Uv = {1.f, 0.f}
        },
        {
            .Position = {-0.2f, 0.f, 0.f}, //1
            .Color = {0.5f, 0.5f, 0.25f},
            .Uv = {0.f, 0.f}
        },
        //Bottom Face
        {
            .Position = {-0.2f, 0.f, 0.f}, //1
            .Color = {0.5f, 0.5f, 0.25f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {0.2f, 0.f, 0.f}, //2 
            .Color = {0.25f, 1.f, 0.5f},
            .Uv = {1.f, 0.f}
        },
        {
            .Position = {0.f, 0.f, -0.2f}, //2 
            .Color = {0.25f, 1.f, 0.5f},
            .Uv = {1.f, 0.f}
        },

    };

    static inline std::vector<uint32_t> dFourElements{
        //Front face
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
        9, 10, 11
    };



    /////////////////////////////////////////////////
    //Pyramid for 6-3 Assignment
    ////////////////////////////////////////////////
    static inline std::vector<Vertex> pyramidVertices{
        //Front face
        {               //X      Y      Z
            .Position = {0.f, 0.5f, 0.0f}, //0
            .Color = {0.5f, 0.25f, 1.f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {-0.5f, -0.5f, 0.5f}, //1
            .Color = {0.5f, 0.5f, 0.25f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {0.5f, -0.5f, 0.5f}, //2 
            .Color = {0.25f, 1.f, 0.5f},
            .Uv = {1.f, 0.f}
        },

        //Right face.
        {               //X      Y      Z
            .Position = {0.f, 0.5f, 0.0f}, //3
            .Color = {1.f, 0.f, 0.5f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {0.5f, -0.5f, 0.5f}, //4
            .Color = {1.f, 0.25f, 0.5f},
            .Uv = {0.f, 0.f}

        },
        {
            .Position = {0.5f, -0.5f, -0.5f}, //5 
            .Color = {0.5f, 1.f, 0.5f},
            .Uv = {1.f, 0.f}
        },
        //Back face
        {               //X      Y      Z
            .Position = {0.f, 0.5f, 0.0f}, //6
            .Color = {0.5f, 1.f, 0.5f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {0.5f, -0.5f, -0.5f}, //7
            .Color = {0.75f, 1.f, 0.5f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-0.5f, -0.5f, -0.5f}, //8
            .Color = {0.f, 0.5f, 0.5f},
            .Uv = {1.f, 0.f}
        },
        //left face
        {               //X      Y      Z
            .Position = {0.f, 0.5f, 0.0f}, //9
            .Color = {0.5f, 1.f, 0.f},
            .Uv = {0.5f, 1.f}
        },
        {
            .Position = {-0.5f, -0.5f, -0.5f}, //10
            .Color = {1.f, 0.5f, 0.f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-0.5f, -0.5f, 0.5f}, //11
            .Color = {0.5f, 0.5f, 0.f},
            .Uv = {1.f, 0.f}
        },
        //Bottom Face
        {               //X      Y      Z
            .Position = {-0.5f, -0.5f, -0.5f}, //12
            .Color = {0.5f, 0.0f, 0.0f},
            .Uv = {0.f, 0.f}
        },
        {
            .Position = {-0.5f, -0.5f, 0.5f}, //13
            .Color = {0.25f, 0.0f, 1.f},
            .Uv = {1.f, 0.f}
        },
        {
            .Position = {0.5f, -0.5f, 0.5f}, //14
            .Color = {0.5f, 1.f, 0.0f},
            .Uv = {1.f, 1.f}
        },
        {
            .Position = {0.5f, -0.5f, -0.5f}, //15
            .Color = {0.5f, 0.0f, 0.75f},
            .Uv = {0.f, 1.f}
        },

    };

    static inline std::vector<uint32_t> pyramidElements{
        //Front face
        0, 1, 2,
        //Right face
        3, 4, 5,
        //Back face
        6, 7, 8,
        //Left Face
        9, 10, 11,
        //Bottom Face
        12, 13, 15, 13, 14, 15
    };




};