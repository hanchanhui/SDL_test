#pragma once
#include "GameObject.h"
#include "SDL.h"
#include "Vector2D.h"

#define UNI_MASS 1.0f
#define GRAVITY 9.8f

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual void draw();
  virtual void drawDir();
  virtual void update(float dt);
  virtual void clean();
  virtual ~SDLGameObject() {}
  
  void TranslateX(float x){m_x += x;}
  void TranslateY(float y){m_y += y;}
  void Translate(Vector2D v){m_x += v.m_x; m_y += v.m_y;}

  // Setter Gravity & Mass
    void SetMass(float mass){ m_Mass = mass; }
    void SetFravity(float gravity){ m_Gravity = gravity; }

    // Force
    void ApplyForce(Vector2D F){m_Force = F;}
    //void ApplyForceX(Vector2D Fx){ m_Force.m_x = Fx; }
    //void ApplyForceY(Vector2D Fy){ m_Force.m_y = Fy; }
    void UnSetForce() {m_Force = Vector2D(0,0);}

    // Friction
    void ApplyFriction(Vector2D Fr){ m_Friction = Fr; }
    void UnSetFriction(){ m_Friction = Vector2D(0,0); }

    // Getters
    float GetMass () { return m_Mass; }
    Vector2D position() { return m_position; }
    Vector2D veclocity() { return m_velocity; }
    Vector2D accelaration() { return m_acceleration; }

protected:
  std::string m_textureID;
  

  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;

  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;

  float m_Mass;
  float m_Gravity;

  Vector2D m_Force;
  Vector2D m_Friction;
};
