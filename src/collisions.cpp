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
    return (plane_height - bbox_min_height) / vel;
}

///TESTE DE COLISÃO
bool CheckCollision(const BoundingBox &box1, const BoundingBox &box2) {
    return (box1.min.x <= box2.max.x && box1.max.x >= box2.min.x) &&
           (box1.min.y <= box2.max.y && box1.max.y >= box2.min.y) &&
           (box1.min.z <= box2.max.z && box1.max.z >= box2.min.z);
}

// Função para verificar colisão com inimigo
bool CheckPlayerEnemyCollision() {
    return CheckCollision(playerBox, enemyBox);
}

bool CheckPlayerTreeCollision() {
    for (const auto& treeBox : treeBoxes) {
        if (CheckCollision(playerBox, treeBox)) {
            return true; // Colidiu com pelo menos uma árvore
        }
    }
    return false;
}

bool RayIntersectsAABB(const glm::vec4& ray_origin, const glm::vec4& ray_direction, const BoundingBox& box, float& tmin)
{
    float tmax = std::numeric_limits<float>::max();
    tmin = 0.0f;

    for (int i = 0; i < 3; ++i) {
        if (abs(ray_direction[i]) < std::numeric_limits<float>::epsilon()) {
            // O raio é paralelo a este plano; verifica se está fora da caixa neste eixo
            if (ray_origin[i] < box.min[i] || ray_origin[i] > box.max[i])
                return false;
        } else {
            // Calcula os valores de t para as interseções com os dois planos
            float t1 = (box.min[i] - ray_origin[i]) / ray_direction[i];
            float t2 = (box.max[i] - ray_origin[i]) / ray_direction[i];

            // Garantimos que t1 seja o menor e t2 seja o maior
            if (t1 > t2) std::swap(t1, t2);

            // Atualizamos tmin e tmax
            tmin = std::max(tmin, t1);
            tmax = std::min(tmax, t2);

            // Se a janela de t (tmin, tmax) não é válida, não há interseção
            if (tmin > tmax)
                return false;
        }
    }

    // Se passarmos por todos os eixos, há uma interseção
    return true;
}

void UpdateBoundingBox(BoundingBox &box, glm::vec3 position, glm::vec3 scale) {
            box.min = position - scale * 0.5f;
            box.max = position + scale * 0.5f;
        }
        

void CheckSwordCollision() {
    glm::vec4 ray_origin = camera_position_c; // Posição da câmera
    glm::vec4 ray_direction = glm::normalize(camera_view_vector); // Direção do vetor de visão

    for (const BoundingBox& box : enemyBoxes) {
        float tmin;
        if (RayIntersectsAABB(ray_origin, ray_direction, box, tmin)) {
            // Colisão detectada, você pode tratar a lógica da espada aqui
            std::cout << "Colisão detectada!" << std::endl;
        }
    }
}