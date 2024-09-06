#pragma once

#include <glm/vec2.hpp>

#include "../../Physics/PhysicsEngine.h"

class IGameObject {
public:

    enum class EObjectType {
        BettonWall,
        Border,
        BrickWall,
        Bullet,
        Eagle,
        Ice,
        Tank,
        Trees,
        Water,
        Unknown
    };

    IGameObject(const EObjectType objectType, const glm::vec2& position, const glm::vec2& size, const float rotation, const float layer);
    virtual void render() const = 0;
    virtual void update(const double delta) {};
    virtual ~IGameObject();
    virtual glm::vec2& getCurrentPosition() { return m_position; }
    virtual glm::vec2& getCurrentDirection() { return m_direction; }
    virtual double getCurrentVelocity() { return m_velocity; }
    virtual void setVelocity(const double velocity);

    void setCollideState(bool value) {
        m_is_collide = value;
    }

    bool getCollideState() const { return m_is_collide; }

    const glm::vec2& getSize() const { return m_size; }
    const std::vector<Physics::AABB>& getColliders() const { return m_colliders; }

    EObjectType getObjectType() const { return m_objectType; }
    virtual bool collides(const IGameObject::EObjectType objectType) { return true; }
    virtual void onCollision() {}

protected:
    glm::vec2 m_position;
    glm::vec2 m_size;
    float m_rotation;
    float m_layer;
    EObjectType m_objectType;

    glm::vec2 m_direction;
    double m_velocity;
    std::vector<Physics::AABB> m_colliders;

    bool m_is_collide;
};