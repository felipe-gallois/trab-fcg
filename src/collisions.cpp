//     Universidade Federal do Rio Grande do Sul
//             Instituto de Informática
//       Departamento de Informática Aplicada
//
//    INF01047 Fundamentos de Computação Gráfica
//               Prof. Eduardo Gastal
//
//                   LABORATÓRIO 5
//

#include "collisions.hpp"

float CalculateAABBToPlaneCollisionTime(float plane_height, float bbox_min_height, float vel) {
    return (bbox_min_height - plane_height) / vel;
}

