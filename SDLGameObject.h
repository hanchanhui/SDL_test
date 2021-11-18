#pragma once
#include "GameObject.h"
#include "SDL.h"
#include "Vector2D.h"


class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual void draw();
  virtual void drawDir();
  virtual void update();
  virtual void clean();
  virtual ~SDLGameObject() {}

  void SetMass(float mass) {m_Mass = mass;}
  void SetFravity(float gravity){m_Gravity = gravity;}

  void ApplyForce(Vector2D F){m_Force = F;}
  void ApplyForceX(float Fx){m_Force.m_x = Fx;}
  void ApplyForceY(float Fy){m_Force.m_y = Fy;}
  void UnSetForce(){m_Force = Vector2D(0,0);}

  void ApplyFriction(Vector2D Fr){m_Friction = Fr;}
  void UnSetFriction(){m_Friction = Vector2D(0,0);}

  Vector2D GetPos() { return m_position; }

  

protected:
  std::string m_textureID;

  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;

  float m_Mass;
  float m_Gravity;

  Vector2D m_Force;
  Vector2D m_Friction;

  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;

};
