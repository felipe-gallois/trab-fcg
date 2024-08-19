//     Universidade Federal do Rio Grande do Sul
//             Instituto de Informática
//       Departamento de Informática Aplicada
//
//    INF01047 Fundamentos de Computação Gráfica
//               Prof. Eduardo Gastal
//
//                   LABORATÓRIO 5
//

#include <limits>

#include "collisions.hpp"

float CalculateAABBToPlaneCollisionTime(float plane_height, float bbox_min_height, float vel) {
    return (plane_height - bbox_min_height) / vel;
}

bool RayIntersectsAABB(glm::vec4 &ray_origin, glm::vec4 &ray_direction, glm::vec4 &aabb_min, glm::vec4 &aabb_max) {
    float t_min = 0.0f;
    float t_max = std::numeric_limits<float>::max();

    // Iterate over the three axes (x, y, z)
    for (int i = 0; i < 3; i++) {
        float invD = 1.0f / (i == 0 ? ray_direction.x : (i == 1 ? ray_direction.y : ray_direction.z));
        float t0 = ((i == 0 ? aabb_min.x : (i == 1 ? aabb_min.y : aabb_min.z)) - (i == 0 ? ray_origin.x : (i == 1 ? ray_origin.y : ray_origin.z))) * invD;
        float t1 = ((i == 0 ? aabb_max.x : (i == 1 ? aabb_max.y : aabb_max.z)) - (i == 0 ? ray_origin.x : (i == 1 ? ray_origin.y : ray_origin.z))) * invD;

        if (invD < 0.0f) std::swap(t0, t1);

        t_min = std::max(t_min, t0);
        t_max = std::min(t_max, t1);

        if (t_max <= t_min) {
            return false; // No intersection
        }
    }

    return true; // Intersection exists
}
