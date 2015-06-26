#include "sensor_utils/dynamic_entity.h"

namespace sensor_utils {
DynamicEntity::DynamicEntity() : position(0, 0),lastPositon(0,0), viewDirection(1, 0),lastViewDirection(1,0),
    velocity(0),lastVelocity(0), moveDirection(1, 0),lastMoveDirection(1,0) {}

void DynamicEntity::updatePosition(const lms::math::vertex2f &position,
                                   const lms::math::vertex2f &viewDirection) {
    this->lastPositon = this->position;
    this->position = position;
    this->lastViewDirection = this->viewDirection;
    this->viewDirection = viewDirection;
}

void DynamicEntity::updateVelocity(float velocity,
                    const lms::math::vertex2f &moveDirection) {
    this->lastVelocity = this->velocity;
    this->velocity = velocity;
    this->lastMoveDirection = this->moveDirection;
    this->moveDirection = moveDirection;
}

float DynamicEntity::movedDistance() const {
    return this->position.distance(this->lastPositon);
}


lms::math::vertex2f DynamicEntity::deltaPosition() const{
    return this->position-lastPositon;
}

float DynamicEntity::deltaVelocity() const {
    return this->velocity - this->lastVelocity;
}


float DynamicEntity::deltaX() const{
    return position.x -lastPositon.x;
}
float DynamicEntity::deltaY() const{
    return position.y -lastPositon.y;
}
float DynamicEntity::deltaPhi() const{
    return viewDirection.angle()-lastViewDirection.angle();

}

}//sensor_utils
