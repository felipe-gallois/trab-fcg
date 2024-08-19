//     Universidade Federal do Rio Grande do Sul
//             Instituto de Informática
//       Departamento de Informática Aplicada
//
//    INF01047 Fundamentos de Computação Gráfica
//               Prof. Eduardo Gastal
//
//                   LABORATÓRIO 5
//

// Função que calcula o tempo que irá levar para um plano e um AABB colidirem, assumindo que
// o plano é estático, o AABB se move a uma velocidade constante para baixo e o AABB
// inicialmente não intersecciona o plano. Um tempo negativo indica que os dois objetos nunca
// irão colidir.
float CalculateAABBToPlaneCollisionTime(float plane_height, float bbox_min_height, float vel);
void CheckSwordCollision();
void UpdateBoundingBox(BoundingBox &box, glm::vec3 position, glm::vec3 scale); //Faz update do bounding box do inimigo pra teste de colisão
bool CheckCollision(const BoundingBox &box1, const BoundingBox &box2);
bool CheckPlayerEnemyCollision();
bool CheckPlayerTreeCollision() ;