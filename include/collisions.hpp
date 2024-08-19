//     Universidade Federal do Rio Grande do Sul
//             Instituto de Informática
//       Departamento de Informática Aplicada
//
//    INF01047 Fundamentos de Computação Gráfica
//               Prof. Eduardo Gastal
//
//                   LABORATÓRIO 5
//

#include <glm/vec4.hpp>

// Função que calcula o tempo que irá levar para um plano e um AABB colidirem, assumindo que
// o plano é estático, o AABB se move a uma velocidade constante para baixo e o AABB
// inicialmente não intersecciona o plano. Um tempo negativo indica que os dois objetos nunca
// irão colidir.
float CalculateAABBToPlaneCollisionTime(float plane_height, float bbox_min_height, float vel);

// Função que calcula se um raio intersecta um AABB
bool RayIntersectsAABB(glm::vec4 &ray_origin, glm::vec4 &ray_direction, glm::vec4 &aabb_min, glm::vec4 &aabb_max);
